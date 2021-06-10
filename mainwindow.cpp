#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QTabBar>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
// #include "display.h"
// #include "qmessagewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 配置定时器
    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval (1000) ;//设置定时周期，单位：毫秒
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    // 隐藏掉计时部分
    ui->label_time->hide();

    QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);


    //设置具体阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(22);
    ui->centralWidget->setGraphicsEffect(shadow_effect);

    // 头像绘制
    QPixmap pixmap(":/resources/avator.JPG");
    pixmap = pixmap.scaled(ui->label_pic->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    int width = ui->label_pic->size().width();
    int height = ui->label_pic->size().height();
    QPixmap image(width,height);
    image.fill(Qt::transparent);
    QPainterPath painterPath;
    painterPath.addEllipse(0, 0, width, height);
    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setClipPath(painterPath);
    painter.drawPixmap(0, 0, width, height, pixmap);
    //绘制到label
    ui->label_pic->setPixmap(image);

    // 确认按钮
    // connect(ui->btn_login_OK,SIGNAL(clicked(bool)),this,SLOT(OnLogin()));
    // 登陆确认按钮
    connect(ui->btn_login_OK,SIGNAL(clicked()),this,SLOT(OnLogin()));
    // 注册确认按钮
    connect(ui->btn_reg_OK,SIGNAL(clicked()),this,SLOT(OnRegist()));
    ui->MessageWidget->hide();
    connect(ui->pCloseButton, SIGNAL(clicked(bool)), ui->MessageWidget, SLOT(close()));

    // 处理子窗口信号
    //处理子窗口的信号
        connect(&form2,&display::Mysignal,this,&MainWindow::dealForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 登陆确认函数
void MainWindow::OnLogin()
{
    // 获取登陆框的账号和密码 同时判断是否为空
    QString name = ui->comboBox->currentText();
    QString pwd = ui->lineEdit_login_passwd->text();
    if(name.isEmpty() or pwd.isEmpty())
    {
        // QMessageBox::warning(this,"警告","用户名或密码不能为空");
        prompt("账号和密码不能为空，请检查是否输入！");
        return;
    } else{
        /*
         * 使用QT C++网络请求，借助NetWork模块
         * 1.构造QNetworkAccessManager对象(提供有发送QNetworkRequest网络请求和接收QNetworkReply网络回复、缓存和Cookie管理、代理设置等功能)
         * 2.构造QNetworkRequest对象(提供了对本次网络请求的封装,QNetworkRequest提供了很多方法来对请求进行配置，比如我们可以使用QNetworkRequest::setHeader设置请求头等)
         * 3.异步请求，请求完成后会调用void requestFinished(QNetworkReply* reply)槽函数，所以需要进行槽函数的定义和构造
         * */
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);

        // 将账号和密码作为参数进行url的构造
        request.setUrl(QUrl("http://47.106.160.176/index.php?model=1"));
        QString testData = QString("&name=%1&passwd=%2").arg(name).arg(pwd);
        naManager->post(request, testData.toUtf8());
        // qDebug() << "测试url测试数据:" << reply->readAll();
    }
}

void MainWindow::ShowForm()
{
    form2.show();
    this->close();
}

/*
 * 网络请求完成后调用的槽函数,在此函数中对请求得到的数据进行处理和其他函数的调用和逻辑编写
 */
void MainWindow::requestLoginFinished(QNetworkReply *reply)
{
    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {
        // 获取返回内容，对内容进行处理
        QString data =  reply->readAll();
        qDebug() << "得到的数据是:" << data;
        QStringList list = data.split("\"");//QString字符串分割函数
        qDebug() << "状态码:" << list[3];
        // 账号密码输入成功
        if(list[3] == "1")
        {
            ShowForm();
        }
        else if(list[3] == "2") // 账号和密码输入错误
        {
            // 账户或密码输入错误清空文本框并进行提示
            ui->lineEdit_login_passwd->clear();
            // ui->lineEdit_login_username->clear();
            // QMessageBox::critical(this,"提示","用户名或密码错误");
            prompt("不好意思,账号密码输入错误,请重新输入!");
        }
    }
}

// 注册确认函数
void MainWindow::OnRegist()
{
    // 获取登陆框的账号和密码 同时判断是否为空
    // QString name = ui->lineEdit_reg_username->text();
    // 读取下拉列表数据作为账号
    QString name = ui->lineEdit_reg_username->text();
    QString pwd = ui->lineEdit_reg_passwd->text();
    QString pwd1 = ui->lineEdit_reg_pwd_Again->text();
    if(name.isEmpty() or pwd.isEmpty() or pwd1.isEmpty())
    {
        prompt("账号和密码不能为空，请检查是否输入！");
        return;
    }
    else if(pwd != pwd1)
    {
        prompt("两次密码输入不一致，请重新输入");
        ui->lineEdit_reg_passwd->clear();
        ui->lineEdit_reg_pwd_Again->clear();
    }
    else
    {
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestRegistFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setUrl(QUrl("http://47.106.160.176/index.php?model=2"));
        QString testUrl = QString("&name=%1&passwd=%2").arg(name).arg(pwd);

        naManager->post(request, testUrl.toUtf8());
        // QNetworkReply* reply = naManager->post(request, testData.toUtf8());
    }
}

// 注册确认后网络请求完成后的槽函数处理
void MainWindow::requestRegistFinished(QNetworkReply *reply)
{
    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {
        // 获取返回内容，对内容进行处理
        QString data =  reply->readAll();
        qDebug() << "得到的数据是:" << data;
        QStringList list = data.split("'");//QString字符串分割函数
        qDebug() << "注册状态码:" << list[1];
        if(list[1] == "1")
        {
            prompt("注册成功！");
        } else if(list[1] == "-1")
        {
            prompt("不好意思,你输入的账号名已存在,请换一个!");
        } else
        {
            prompt("出问题了！蕾酱会尽快维修的，请稍后再试");
        }
    }
}

// 处理子窗口信号的函数
void MainWindow::dealForm()
{
    form2.close();
    this->show();
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString picData = "";
    //  QMap<QString,int> users{{"remmeiko",1},{"mikasa",2}};
    switch (users[arg1]) {
        case 1:
            picData = ":/resources/avator.JPG";
            // ui->lineEdit_login_username->setText("remmeiko");
            ui->lineEdit_login_passwd->setText("remmeiko123.");
            break;
        case 2:
            picData = ":/resources/mikasa.jpg";
            // ui->lineEdit_login_username->setText("mikasa");
            ui->lineEdit_login_passwd->setText("mikasa123.");
            break;
        default:
            break;
    }
    //QPixmap pixmapa(picData);
    QPixmap pixmap(picData);

    pixmap = pixmap.scaled(ui->label_pic->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    int width = ui->label_pic->size().width();
    int height = ui->label_pic->size().height();
    QPixmap image(width,height);
    image.fill(Qt::transparent);
    QPainterPath painterPath;
    painterPath.addEllipse(0, 0, width, height);
    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setClipPath(painterPath);
    painter.drawPixmap(0, 0, width, height, pixmap);
    //绘制到label
    ui->label_pic->setPixmap(image);

}

void MainWindow::on_timer_timeout()
{
    // QTime curTime=QTime::currentTime(); //获取当前时间
    ui->label_time->setText(QString::number(time)+="s");
    ui->label_time->show();
    time --;
    if(time == -1)
    {
        ui->MessageWidget->close();
        fTimer->stop () ; //定时器停止
    }

}

// 登陆和注册弹窗提示信息
void MainWindow::prompt(QString data)
{
    ui->MessageWidget->clearFocus();
    ui->label_highlight->setText(data);
    ui->MessageWidget->show();
    fTimer->start () ;//定时器开始工作
    time = 5;
    fTimeCounter.start () ; //计时器开始工作
}
