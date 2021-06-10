#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "display.h"
#include <QNetworkReply>
#include <map>
#include <Qtimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// 自定义槽函数
private slots:
    void OnLogin(); // 登陆确认槽函数
    void ShowForm(); //显示子页面槽函数
    void requestLoginFinished(QNetworkReply* reply); // 登陆确认后网络请求完成后处理槽函数
    void OnRegist(); // 注册确认槽函数
    void requestRegistFinished(QNetworkReply* reply); // 注册确认后网络请求完成后处理槽函数
    void dealForm(); // 处理子窗口的函数

    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_timer_timeout() ; //定时溢出处理槽函数

private:
    Ui::MainWindow *ui;
    //声明新窗口
    display form2;
    QTimer *fTimer; //定时器
    QTime fTimeCounter;//计时器
    qint8 time;

public:
    QMap<QString,int> users{{"remmeiko",1},{"mikasa",2}};
    void prompt(QString data); // 登陆和注册是否成功提示信息
};

#endif // MAINWINDOW_H
