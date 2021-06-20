#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <imageswitch.h>

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>


#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintBulb();



private slots:
    void on_btn_regiter_clicked();

    void on_btn_login_clicked();

    void on_btn_show1_return_clicked();

    void on_btn_show1Toshow2_clicked();

    void on_btn_show2_return_clicked();

    void on_btn_show1_database_select_clicked();

    void on_btn_show2Toshow3_clicked();

    void on_btn_show3_return_clicked();

    void on_timer_timeout();
    // 初始化串口
    void initserial();
    // 处理数据
    void serialDealdata();



private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QMap<QString,ImageSwitch *> images;
    QMap<QString,QLabel *> labels;
    QSerialPort *serial;
    qint16 temperature1;
    qint16 humidity1;

};

#endif // MAINWINDOW_H
