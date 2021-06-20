#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QLabel>
#include <QMovie>
#include "qevent.h"
#include <QPropertyAnimation>
#include "qdebug.h"
#include <QMovie>
#include <QIcon>
#include "imageswitch.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    bool eventFilter(QObject *watched, QEvent *evt);

public slots:
    void on_timer_timeout();
    void dealCombobox1(QLabel *label,qint8 type,qint8 index);// 处理灯泡情况

private slots:
    void on_imageSwitch1_1_clicked();

    void on_imageSwitch1_2_clicked();

    void on_imageSwitch1_3_clicked();

    void on_imageSwitch1_4_clicked();

    void on_imageSwitch1_5_clicked();

    void on_imageSwitch1_6_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    QMap<QString,ImageSwitch *> images;
    QMap<QString,QLabel *> labels;
    // 存储开关和label的标志位
    QList<qint8> switchLabel;

    QString imageName;
    QString labelName;
    QList<QString> listdata; // 存储图片的url
public:
    bool isReset; // 是否刷新


};

#endif // WIDGET_H
