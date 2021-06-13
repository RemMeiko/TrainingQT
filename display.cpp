#include "display.h"
#include "ui_display.h"
#include "mainwindow.h"
#include <QtNetwork>
#include <QHostAddress>
#include "mqtt/qmqtt.h"
#include <QDebug>


display::display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

    // connect(ui->btn_back,SIGNAL(clicked()),this,SLOT(OnBack()));
    connect(ui->btn_back,&QPushButton::clicked,this,&display::Sendslot);

    // 创建客户端
    client = new QMQTT::Client();
    // 端口的初始化设置
    QHostAddress host("42.193.228.185");
    QByteArray password = "";
    quint16 port = 1883;
    //client->set
    client->setKeepAlive(120);
    client->setHost(host);//设置EMQ代理服务器IP
    client->setPort(port);//设置EMQ代理服务器端口号
    client->setClientId("client");//设置一个客户端ID
    client->setUsername("");//设置一个客户端用户名
    client->setPassword(password);//设置一个客户端密码
    client->cleanSession();//清除缓存
    client->setVersion(QMQTT::MQTTVersion::V3_1_1);//设置mqtt版本
    client->connectToHost();//连接EMQ代理服务器

    // 分别是连接，订阅，成功收到信息槽函数
    connect(client, SIGNAL(connected()), this, SLOT(onMQTT_Connected()));
    connect(client, SIGNAL(subscribed(const QString &)), this, SLOT(onMQTT_Subscribed(QString)));
    connect(client, SIGNAL(received(const QMQTT::Message &)), this, SLOT(onMQTT_Received(QMQTT::Message)));}

display::~display()
{
    delete ui;
}

void display::OnBack()
{
    this->close();
}

void display::Sendslot()
{
     emit Mysignal();
}

void display::on_pushButton_clicked()
{


    // 发布信息-->主题和数据
    QString topicPub = "server";
    QString messagePub = "C++发给你的数据";
    QMQTT::Message msg(0, topicPub.toLatin1(), messagePub.toLatin1());
    client->publish(msg);

    // 订阅主题
    QString topicSub = "server";
    quint8 qosSub = 0;
    client->subscribe(topicSub, qosSub);
}

// 连接成功
void display::onMQTT_Connected()
{
    qDebug() << "连接成功！";
}

// 订阅成功信息
void display::onMQTT_Subscribed(const QString &topic)
{

}

// 收到信息
void display::onMQTT_Received(const QMQTT::Message &message)
{
    qDebug() << "主题是：" << message.topic() << "发送数据是:" << message.payload();
    ui->label->setText(message.payload());
}
