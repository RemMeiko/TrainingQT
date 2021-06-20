#ifndef FURNITURE_H
#define FURNITURE_H

#include <QWidget>
#include <QTimer>
#include <QNetworkReply>
#include "QDebug"
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QPropertyAnimation>
#include <QPainter>
#include<QPixmap>
#include "widget.h"
#include "table.h"

namespace Ui {
class Furniture;
}

class Furniture : public QWidget
{
    Q_OBJECT

private slots:
    void showLED();

public:
    explicit Furniture(QWidget *parent = nullptr);
    static qint8 flag_type;
    ~Furniture();

protected:
    // bool eventFilter(QObject *watched, QEvent *evt);

private:
    Ui::Furniture *ui;
    Widget FormLED;
    QTimer *futimer;
    // 数据库数据
    QMap<QString,QString> ZigData;


private slots:
    void Sendslot(); //给主窗口发送信号
    void requestData(); // 请求网络数据
    void dealData(QNetworkReply* reply);

    void on_comboBox_2_currentIndexChanged(int index);


    void on_pushButton_clicked();

    void dealSign();

    void on_btn_going_clicked();

signals:
    void Mysignal();                //返回值信号

public:
    Table table;
    void showBea();


};

#endif // FURNITURE_H
