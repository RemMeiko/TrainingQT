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
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QHttpPart>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include <QElapsedTimer>
// #include "display.h"

/*
 * QT实训界面使用
 * 涉及：QT,mysql,mqtt,webhook,php,API
 * 界面：登陆界面+功能界面
 * 登陆界面功能:
 *    注册：头像,账号,密码，头像使用sm.ms做图床，利用其提供的v2_API接口上传图片
 * QT涉及：
 *    定时器，界面设计，NetWork模块，json处理模块
 * */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PicCache();

    // 初始化
    flag_rl = 0;
    // 初始化combobox
    readAccount();

    QVector<QString> PicUrls;
    // 配置定时器 倒计时定时器
    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval (1000) ;//设置定时周期，单位：毫秒
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    // 隐藏掉计时部分
    ui->label_time->hide();

    // 配置定时器 扫描账户框
    QTimer *AccountTimer = new QTimer(this);
    AccountTimer->setInterval(3000);
    AccountTimer->start();
    // AccountTimer->stop();
    // AccountTimer->stop();
    connect(AccountTimer,SIGNAL(timeout()),this,SLOT(Account_pic_del_timeout()));

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

    ui->label_pic->hide();

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
    // 选择上传图片
    // ui->btn_choose->hide();
}

// 在label-pic中绘制头像
void MainWindow::AvatarDrawing(qint16 choose,QString Address)
{
    // 1代表从网络中读取图片绘制 2表示从本地读取文件绘制
    if(choose == 1)
    {
        QNetworkRequest request;
        QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
        request.setUrl(QUrl(Address));
        connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(requestPicFinish(QNetworkReply *)));
        networkAccessManager->get(request);
    }
    else if(choose == 2)
    {
        // 头像绘制
        QPixmap pixmap(Address);
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

}

// 网络请求绘制头像
void MainWindow::requestPicFinish(QNetworkReply *reply)
{
    // 获取响应状态码，200表示正常
    // QVariant nCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (reply->error() == QNetworkReply::NoError)
    {
       QByteArray bytes = reply->readAll();
       QPixmap pixmap;
       pixmap.loadFromData(bytes);
       // ui->label->setPixmap(pixmap);


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
       // 缓存到本地
       QFile file("E:/head.jpg");
       if (file.open(QIODevice::Append))
           file.write(bytes);
       file.close();
    }
    else
    {
       // 错误处理-显示错误信息，或显示上一次缓存的图片或叉图。
    }
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
        request.setUrl(QUrl("http://127.0.0.1/mqtt/Account.php?model=1"));
        QString testData = QString("&username=%1&passwd=%2").arg(name).arg(pwd);
        naManager->post(request, testData.toUtf8());
        // qDebug() << "测试url测试数据:" << reply->readAll();
        // 是否记住密码进行处理
        if(ui->checkBox->isChecked())
        {
            if(ui->comboBox->findText(ui->comboBox->currentText()) == -1)
            {
                Write(name,pwd);
                qDebug() << "正在写入账户和数据 ";
            }
        }
    }
}

// 将账户和密码写入users.ini本地文件进行封装
void MainWindow::Write(QString username,QString passwd)
{
    QFile  fileName("F:/CodeWorkspace/01QT/08DevTrainingQT/users.ini");
    if(!fileName.open(QIODevice::ReadWrite  | QIODevice::Text))
    {
        qDebug() << "Open failed." << endl;
        return;
    }
    QTextStream txtOutput(&fileName);
    qint64 pos;
    pos = fileName.size();
    fileName.seek(pos);
    //写入文件
    qint64 length = -1;
    username = username+=" ";
    length = fileName.write(username.toLatin1(),username.length());
    txtOutput << '\n';
    // data = "remmeiko";
    length = fileName.write(passwd.toLatin1(),passwd.length());
    if(length == -1){
       qDebug()<<"写入文件失败";
    }else{
       qDebug()<<"写入文件成功";
    }
    // txtOutput << data;
    fileName.close();
}

// 从user.ini中读取账户和用户名字
void MainWindow::readAccount()
{
    QFile fileName("F:/CodeWorkspace/01QT/08DevTrainingQT/users.ini");
    if(!fileName.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open failed." << endl;
        return;
    }
    QTextStream txtInput(&fileName);

    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        qDebug() << "数据是：" << lineStr;
        if(!lineStr.isEmpty()) // 如果为空则跳过
        {
            QStringList listData = lineStr.split(" ");
            // ui->comboBox->currentText()->setText(listData[0]);
            // ui->lineEdit_login_passwd->setText(listData[1]);
            // 禁止添加重复元素
            qDebug() << "数据是：" << listData[0];
            if(ui->comboBox->findText(listData[0]) == -1)
            {
                ui->comboBox->addItem(listData[0]);
            }
            accountRem.insert(listData[0],listData[1]);
        }
    }
    fileName.close();
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
    if(name.isEmpty() or pwd.isEmpty() or pwd1.isEmpty() )
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
    else if(PicUrls.empty())
    {
        prompt("请确保已经选择好头像！");
        return;
    }
    else
    {
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestRegistFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setUrl(QUrl("http://127.0.0.1/mqtt/Account.php?model=2"));
        QString testUrl = QString("&username=%1&passwd=%2&avatorUrl=%3&deleteUrl=%4").arg(name).arg(pwd).arg(PicUrls[0]).arg(PicUrls[1]);
        qDebug() << "url构造参数是：" << testUrl;
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

// 下拉框数据变化
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    // 显示头像
    Account_pic_del_timeout();
}

// 倒计时定时器
void MainWindow::on_timer_timeout()
{
    // QTime curTime=QTime::currentTime(); //获取当前时间
    ui->label_time->setText(QString::number(time)+="s");
    ui->label_time->show();
    time --;
    if(time == 0)
    {
        ui->MessageWidget->close();
        fTimer->stop () ; //定时器停止
    }
}

// 账户框定时器扫描处理函数
void MainWindow::Account_pic_del_timeout()
{
    QString fileAddress = "";
    if(flag_rl%2 == 1)
    {
        // 匹配输入的数据和下拉框中存储的数据是否一致
        for(int i = 0;i < ui->comboBox->count();i++)
        {
            if(ui->comboBox->currentText() == ui->comboBox->itemText(i))
            {
                fileAddress = QString("D:/%1.jpg").arg(ui->comboBox->currentText());
                qDebug() <<"此时键值对中的键是:" <<  accountRem.value(ui->comboBox->currentText());
                // 密码填充
                ui->lineEdit_login_passwd->setText(accountRem.value(ui->comboBox->currentText()));
            } else
            {
                ui->lineEdit_login_passwd->clear();
            }
            AvatarDrawing(2,fileAddress);
        }
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

// flag_rl用来辨别当前显示界面是登录界面还是注册界面
// 初始值为0，0代表是注册界面，1代表登录界面，每次切换flagrl+1
void MainWindow::on_tabWidget_reg_currentChanged(int index)
{
    flag_rl ++;
    if(flag_rl%2 == 0)
    {
        ui->label_pic->hide();
        ui->btn_choose->show();
    }
    else if(flag_rl%2 == 1)
    {
        ui->label_pic->show();
        ui->btn_choose->hide();
    }
    if(flag_rl == 100)
    {
        flag_rl = 0; // 防止无上限的增加
    }
}

// 选择图片上传函数
void MainWindow::on_btn_choose_clicked()
{
        //网络载体
        QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);

        //网络载体的响应接收信号，与响应接收槽绑定
        connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(uploadDealPic(QNetworkReply *)));

        QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

        QHttpPart imagePart;
        // QString typePic = "image/png";
        //下面这行代码的作用是打开选择窗口，选择一个图片并返回路径
        QString strFilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择上传图片"), "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm *.jpeg);;All files (*.*)"));
        if(strFilePath.isEmpty())
        {
            return;
        }
        // 界面显示切换  成功后选择上传隐藏改为显示头像
        ui->btn_choose->hide();
        ui->label_pic->show();
        // 对上传图像进行压缩处理
        strFilePath = togray(2,strFilePath);
        // 确定图片类型  png-->image/png   jpg-->image/jpg  ...以此类推
        QStringList TypePics = strFilePath.split(".");
        QString TypePic = QString("image/%1").arg(TypePics[1]);
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(TypePic));
        //如果上传的是jpg图片，就修改为image/jpg
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"smfile\"; filename=\"image.png\""));
        //这里的smfile是参数名，不可以修改，因为SM.MS的API接口要求参数名必须为smfile

        QFile *file = new QFile(strFilePath);
        if(!file->open(QIODevice::ReadOnly))
           qDebug()<<"=================================";
        else{
           imagePart.setBodyDevice(file);
           multiPart->append(imagePart);
        }

        QNetworkRequest request;
        request.setUrl(QUrl("https://sm.ms/api/v2/upload"));
        networkAccessManager->post(request,multiPart);
}

// 上传成功后的处理函数，获取返回的图像的相关数据
void MainWindow::uploadDealPic(QNetworkReply* reply){
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        qDebug() << "statusCode:" << statusCode;

        if(reply->error() == QNetworkReply::NoError)
        {
            //官方文档显示返回的reply是json格式，所以我们采用json格式读取
            QByteArray allData = reply->readAll();
            QJsonParseError json_error;
            QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));
            qDebug() << jsonDoc;
            if(json_error.error != QJsonParseError::NoError)
               {
                   qDebug() << "json error!";
                   return;
               }
              QJsonObject rootObj = jsonDoc.object();
              QString accessUrl;
              //我们只需要上传后的url，所以值提取了url，如果你需要其他内容，请提取方法类似
              if(rootObj.contains("data"))
                {
                   QJsonObject subObj = rootObj.value("data").toObject();
                   accessUrl = subObj["url"].toString();
                   qDebug() << "头像的访问地址是：" << accessUrl;
                   QString deleteUrl = subObj["delete"].toString();
                   qDebug() << "用来删除图像的地址是：" << deleteUrl;
                   PicUrls.append(accessUrl);
                   PicUrls.append(deleteUrl);
                }
              // 绘制头像
              AvatarDrawing(1,accessUrl);
        }
        else
        {
                qDebug() << "=========";
        }
        reply->deleteLater();
}

// 网络图像进行本地缓存
void MainWindow::PicCache()
{
    // 先将文本数据写入下拉框
    readAccount();
    // 将数据存储进列表中
    QStringList dataAccount;
    for(int i = 0;i < ui->comboBox->count();i++)
    {
        dataAccount.append(ui->comboBox->itemText(i));
    }
    for(int i = 0; i < dataAccount.length();i++)
    {
        //qDebug() << "列表数据" << i << "是:" << dataAccount[i];
        // 以列表中数据位参数循环请求
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dealPicCache(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号作为参数进行url的构造
        request.setUrl(QUrl("http://127.0.0.1/mqtt/Account.php?model=3"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QString testData = QString("&username=%1").arg(dataAccount[i]);
        naManager->post(request, testData.toUtf8());
        qDebug() << "现在请求的账户是：" << dataAccount[i];
        // 头像名字
        PicName = dataAccount[i];
        // 线程延时
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<5000)
            QCoreApplication::processEvents();
    }
}

// 处理请求的图片缓存
// 处理返回的头像数据
void MainWindow::dealPicCache(QNetworkReply* reply)
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
    } else
    {
        //官方文档显示返回的reply是json格式，所以我们采用json格式读取
        QByteArray allData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));
        qDebug() << jsonDoc;
        if(json_error.error != QJsonParseError::NoError)
        {
           qDebug() << "json error!";
           return;
        }
        QJsonObject rootObj = jsonDoc.object();
        //我们只需要上传后的url，所以只提取了url，如果你需要其他内容，提取方法类似
        if(rootObj.contains("data"))
        {
           if(rootObj.value("data") == NULL)
           {
               return;
           }else {
               QJsonValue subObj = rootObj.value("data");
               QJsonObject subdata = subObj.toArray().at(0).toObject();
               // 获取头像的访问地址
               QString AvotorUrl = subdata["avatorUrl"].toString();
               // 处理头像图片类型
               PicType = AvotorUrl.mid(AvotorUrl.length()-3,3);
               qDebug() << "头像的访问地址是：" << AvotorUrl;
               QNetworkRequest request;
               QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
               request.setUrl(QUrl(AvotorUrl));
               connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
               networkAccessManager->get(request);
           }
        }
    }
}

// 响应结束，进行结果处理-网络图片显示
void MainWindow::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        // 缓存到本地
        QString fileName = QString("D:/%1.%2").arg(PicName).arg(PicType);
        qDebug() << "缓存图片名字是：" << fileName;
        QFile file(fileName);
        if(file.open(QFile::WriteOnly))
        {
           file.write(bytes);
           file.close();
        }
    }
    else
    {
        // 错误处理-显示错误信息，或显示上一次缓存的图片或叉图。
    }
}

/*
参数1：缩小的倍速参数
参数三：图片路径，名字
返回值：处理后的图像路径
*/
QString MainWindow::togray(int sx,QString fileName){

    QImage image(fileName);

    QImage *img = new QImage(image);//原图像
    QImage *grayImg;//处理后图像
    unsigned char *data=img->bits();//获取图像像素字节数据的首地址
    int width=img->width();//图像宽
    int height=img->height();//图像高
    //图片像素缩小的倍数
    int suoxiao = getSuoXiao(sx,width);

    int bytePerLine=(width*24+31)/8;//图像每行字节对齐

    unsigned char *graydata=new unsigned char[bytePerLine*(height)];//存储处理后的数据  bytePerLine*(height/(suoxiao-1))
    int sum = 0;

    // 计算总共有多少像素点
    for (int i=0;i<height;i++)
    {
      for (int j=0;j<width;j++)
      {
          sum++;
      }
    }
    qDebug()<< "处理前的像素点:"<<sum;
    data=img->bits();
    int realSum = 0;
    for (int i=0,k=0;i<height;i+=suoxiao,k++)
    {
      for (int j=0,p=0;j<width;j+=suoxiao,p++)
      {

        graydata[k*bytePerLine+p*3]  = *(data+2);
        graydata[k*bytePerLine+p*3+1] = *(data+1);
        graydata[k*bytePerLine+p*3+2] = *(data);
        realSum++;
        data+=4*suoxiao;
      }
        data = data+width*4*(suoxiao-1);
    }
    qDebug()<<"完成！缩小后像素点个数："<<realSum;
    grayImg=new QImage(graydata,width/suoxiao,height/suoxiao,bytePerLine,QImage::Format_RGB888);//Format_RGB888
    // 处理图像类型
    QString picPath = QString("D:/result.%1").arg(fileName.mid(fileName.length()-3,3));
    grayImg->save(picPath);
    return picPath;
  }

//参数一： 缩小的度
//参数二：图片的宽度
int MainWindow::getSuoXiao(int sx,int w){
   int suoxiao = 2;
   if(w%2 ==0)
   {
       if(sx ==1)
       {
          if(w%4 ==0)
          {
             suoxiao = 4;
          }
       }else if(sx ==2){
           if(w%8 ==0)
           {
              suoxiao = 8;
           }
       }else
         suoxiao = 2;
   }
    else if(w%3 ==0)
   {
       suoxiao = 3;
   }
   else if(w%5 ==0)
   {
       suoxiao = 5;
   }
   else if(w%7 ==0)
   {
       suoxiao = 7;
   }else{
       qDebug()<<"\n\n无法计算缩小倍数::"<<w;
   }
   return suoxiao;
}

void MainWindow::on_pushButton_clicked()
{
    PicCache();
}
