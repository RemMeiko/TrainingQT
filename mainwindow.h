#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "display.h"
#include <QNetworkReply>
#include <map>
#include <QTimer>

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
    void OnLogin(); // 登陆确认
    void ShowForm(); //显示子页面
    void requestLoginFinished(QNetworkReply* reply); // 登陆确认后网络请求完成后处理(账号密码验证)
    void OnRegist(); // 注册确认(注册按钮)
    void requestRegistFinished(QNetworkReply* reply); // 注册确认后网络请求完成后处理(账号密码注册)
    void dealForm(); // 处理子窗口的函数

    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_timer_timeout() ; //定时溢出处理槽函数
    void Account_pic_del_timeout(); // 扫描账号框定时溢出处理函数
    // void dealPic(QNetworkReply* reply); // 处理返回的头像数据

    void on_tabWidget_reg_currentChanged(int index);
    void replyFinished(QNetworkReply *reply);// 图片数据库请求显示
    void uploadDealPic(QNetworkReply *reply);// 图片上传处理

    void on_btn_choose_clicked();

    // 处理请求的网络图片进行本地缓存
    void dealPicCache(QNetworkReply* reply);
    // 绘制头像
    void requestPicFinish(QNetworkReply *reply);
    void AvatarDrawing(qint16 choose,QString Address);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //声明新窗口
    display form2;
    QTimer *fTimer; //定时器
    QTime fTimeCounter;//计时器
    qint8 time;
    QString AvotorUrl;
    QVector<QString> PicUrls; // 上传图片后返回的图片地址和删除图片的地址
    qint16 flag_rl; // 判断此时是登陆界面还是注册界面

public:
    QMap<QString,int> users{{"remmeiko",1},{"mikasa",2}};
    void prompt(QString data); // 登陆和注册是否成功提示信息
    void Write(QString username,QString passwd); // 本地文件写入函数
    void readAccount(); // 本地文件读出函数


    // 头像压缩
    QString togray(int sx,QString fileName);
    // 压缩倍数确定
    int getSuoXiao(int sx,int w);
    // 图片本地缓存加载
    void PicCache();

    QString PicName;
    QString PicType;
    QMap<QString,QString> accountRem;

};



#endif // MAINWINDOW_H
