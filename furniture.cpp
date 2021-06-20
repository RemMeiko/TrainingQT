#include "furniture.h"
#include "ui_furniture.h"
#include "qevent.h"

qint8 Furniture::flag_type = 1;

Furniture::Furniture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Furniture)
{

    ui->setupUi(this);
    // this->installEventFilter(this); // 安装事件过滤器
    // ui->pushButton_2->hide();
    // 设置下拉框不可编辑
    // ui->comboBox_2->setEditable(false);
    // 处理下一窗口返回的信号
    // connect(&table,&Table::MysignalFurn,this,&Furniture::dealSign);

    futimer = new QTimer(this);
    futimer->start();
    futimer->setInterval (5000) ;//设置定时周期，单位：毫秒
    // 绑定返回主窗口的信号
    connect(ui->btn_return,&QPushButton::clicked,this,&Furniture::Sendslot);

    connect(futimer,SIGNAL(timeout()),this,SLOT(requestData()));

    connect(ui->btn_Mbed,SIGNAL(clicked(bool)),this,SLOT(showLED()));
    connect(ui->btn_Sbed,SIGNAL(clicked(bool)),this,SLOT(showLED()));
    connect(ui->btn_book,SIGNAL(clicked(bool)),this,SLOT(showLED()));
    connect(ui->btn_corr,SIGNAL(clicked(bool)),this,SLOT(showLED()));
    connect(ui->btn_live,SIGNAL(clicked(bool)),this,SLOT(showLED()));

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    ui->widget->installEventFilter(this);

    /*窗口出现动画效果*/
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "windowOpacity");
    animation1->setDuration(1000);
    animation1->setStartValue(0);
    animation1->setEndValue(1);
    animation1->start();

    // 设置返回图标

//    QIcon ButtonIcon(pixmap);
//    ui->pushButton->setIcon(ButtonIcon);
    // ui->pushButton->setIconSize(pixmap.rect().size());
    // ui->pushButton->setFixedSize(pixmap.rect().size());

    QPixmap pixmap(":/resources/background/ico_return.png");
    pixmap = pixmap.scaled(ui->label_return->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    int width = ui->label_return->size().width();
    int height = ui->label_return->size().height();
    QPixmap image(width,height);
    image.fill(Qt::transparent);
    QPainterPath painterPath;
    painterPath.addEllipse(0, 0, width, height);
    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setClipPath(painterPath);
    painter.drawPixmap(0, 0, width, height, pixmap);
    //绘制到label
    ui->label_return->setPixmap(image);

    // 设置前进按钮
    QPixmap pixmap2(":/resources/background/ico_going.png");
    pixmap2 = pixmap2.scaled(ui->label_going->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    int width2 = ui->label_going->size().width();
    int height2 = ui->label_going->size().height();
    QPixmap image2(width2,height2);
    image2.fill(Qt::transparent);
    QPainterPath painterPath2;
    painterPath2.addEllipse(0, 0, width2, height2);
    QPainter painter2(&image2);
    painter2.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter2.setClipPath(painterPath2);
    painter2.drawPixmap(0, 0, width2, height2, pixmap2);
    //绘制到label
    ui->label_going->setPixmap(image2);
}

Furniture::~Furniture()
{
    delete ui;
}

// 请求数据
void Furniture::requestData()
{
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dealData(QNetworkReply*)));
    Q_ASSERT(connRet);
    // 将账号作为参数进行url的构造
    request.setUrl(QUrl("https://web.remmeiko.top/API/QT.php?model=4"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString testData = QString("&id=1");
    naManager->post(request, testData.toUtf8());
}

void Furniture::showLED()
{
    FormLED.isReset = true;
    FormLED.show();
}

// 处理获取的数据
void Furniture::dealData(QNetworkReply* reply)
{
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
          //我们只需要上传后的url，所以值提取了url，如果你需要其他内容，请提取方法类似
          if(rootObj.contains("data"))
            {
               QJsonValue subObj = rootObj.value("data");
               // 数据数组
               QJsonArray dataArray = subObj.toArray();
               for(int i = 0;i < dataArray.size();i++)
               {
                   QJsonObject subdata = dataArray.at(i).toObject();
                   QString date = subdata["date"].toString();
                   qDebug() << "日期是：" << date;
                   QString humanity = subdata["humanity"].toString();
                   qDebug() << "湿度是：" << humanity;
                   QString temperature = subdata["temperature"].toString();
                   qDebug() << "温度是：" << temperature;
                   QString id = subdata["id"].toString();
                   qDebug() << "id是：" << id;
                   QString ppm = subdata["ppm"].toString();
                   qDebug() << "烟雾浓度是：" << ppm;
                   ZigData.insert("id",id);
                   ZigData.insert("ppm",ppm);
                   ZigData.insert("temperature",temperature);
                   ZigData.insert("humanity",humanity);
                   ZigData.insert("date",date);
                   }
            }
              ui->LCD_hum->display(ZigData.value("humanity"));
              ui->LCD_smoke->display(ZigData.value("ppm"));
              ui->LCD_tem->display(ZigData.value("temperature"));
    }
    else
    {
            qDebug() << "=========";
    }
    reply->deleteLater();
}

// 切换灯和窗户
void Furniture::on_comboBox_2_currentIndexChanged(int index)
{
    Furniture::flag_type = index + 1;
    // qDebug() << "dsdsdddddddddddddddddddddddddddddddddddddddddddddd测试的数据是：" << Furniture::flag_type;
}

void Furniture::Sendslot()
{
     emit Mysignal();
}

void Furniture::on_pushButton_clicked()
{

}



// 信号发送
void Furniture::dealSign()
{

}

// 切换到
void Furniture::on_btn_going_clicked()
{
    table.show();
    this->close();
}

// 切换界面
void Furniture::showBea()
{
    /*窗口出现动画效果*/
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "windowOpacity");
    animation1->setDuration(1000);
    animation1->setStartValue(0);
    animation1->setEndValue(1);
    animation1->start();
}
