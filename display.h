#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include "mqtt/qmqtt_global.h"
#include "mqtt/qmqtt.h"

namespace Ui {
    class display;
}

class display : public QWidget
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();
    QMQTT::Client *client;// 创建MQTT客户端指针

private slots:
    void OnBack();//返回主界面
    void Sendslot();    // 给主窗口发送信号

    void on_pushButton_clicked();
    void onMQTT_Connected(); // 连接槽函数
    void onMQTT_Subscribed(const QString &topic); // 订阅槽函数
    void onMQTT_Received(const QMQTT::Message &message); // 接收信息槽函数

private:
    Ui::display *ui;

signals:
    void Mysignal();                //返回值信号

};

#endif // DISPLAY_H
