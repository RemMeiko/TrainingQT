/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"
#include "imageswitch.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_login_register;
    QLineEdit *lineEdit_username;
    QPushButton *btn_login;
    QPushButton *btn_regiter;
    QLineEdit *lineEdit_passwd;
    QLabel *label_title;
    QWidget *page_data_show1;
    QPushButton *btn_show1_return;
    QLCDNumber *lcdNumber_temp;
    QPushButton *btn_show1Toshow2;
    QLCDNumber *lcdNumber_hum;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label2_5;
    QLabel *label1_3;
    QLabel *label1_2;
    QLabel *label1_1;
    QLabel *label1_6;
    ImageSwitch *imageSwitch1_2;
    ImageSwitch *imageSwitch1_5;
    QLabel *label2_3;
    ImageSwitch *imageSwitch1_3;
    QLabel *label2_4;
    QLabel *label1_4;
    QLabel *label1_5;
    QLabel *label2_6;
    ImageSwitch *imageSwitch1_6;
    ImageSwitch *imageSwitch1_1;
    QLabel *label2_1;
    QLabel *label2_2;
    ImageSwitch *imageSwitch1_4;
    QWidget *page_data_show2;
    QPushButton *btn_show2_return;
    QTableView *datashow1_tableview;
    QPushButton *btn_show1_database_select;
    QLabel *label_graph;
    QPushButton *btn_show2Toshow3;
    QCustomPlot *customPlot;
    QPushButton *btn_show2_start_collect;
    QPushButton *btn_show2_stop_collect;
    QWidget *page_data_show3;
    QLabel *label_graph2;
    QPushButton *btn_show3_return;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 480));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#page_login_register\n"
"{\n"
"	\n"
"	/*image: url(:/new/prefix1/images/bg.png);*/\n"
"	\n"
"	background-color: rgb(0, 41, 45);\n"
"}\n"
"\n"
"QWidget#page_data_show1,QWidget#page_data_show1,QWidget#page_data_show2,QWidget#page_data_show3\n"
"{\n"
"	\n"
"	/*image: url(:/new/prefix1/images/bgelse.png);*/\n"
"	\n"
"	background-color: rgb(0, 41, 45);\n"
"}\n"
"\n"
"QLabel#label_title\n"
"{\n"
"	color: rgb(240, 240, 240);\n"
"}"));
        page_login_register = new QWidget();
        page_login_register->setObjectName(QStringLiteral("page_login_register"));
        lineEdit_username = new QLineEdit(page_login_register);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(270, 150, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font.setPointSize(10);
        lineEdit_username->setFont(font);
        lineEdit_username->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
""));
        btn_login = new QPushButton(page_login_register);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(270, 280, 121, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font1.setPointSize(11);
        btn_login->setFont(font1);
        btn_login->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 15px;\n"
"\n"
"\n"
""));
        btn_regiter = new QPushButton(page_login_register);
        btn_regiter->setObjectName(QStringLiteral("btn_regiter"));
        btn_regiter->setGeometry(QRect(410, 280, 111, 51));
        btn_regiter->setFont(font1);
        btn_regiter->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
""));
        lineEdit_passwd = new QLineEdit(page_login_register);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(270, 210, 251, 41));
        lineEdit_passwd->setFont(font);
        lineEdit_passwd->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);"));
        label_title = new QLabel(page_login_register);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(280, 70, 231, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(28);
        font2.setBold(false);
        font2.setWeight(50);
        label_title->setFont(font2);
        stackedWidget->addWidget(page_login_register);
        page_data_show1 = new QWidget();
        page_data_show1->setObjectName(QStringLiteral("page_data_show1"));
        btn_show1_return = new QPushButton(page_data_show1);
        btn_show1_return->setObjectName(QStringLiteral("btn_show1_return"));
        btn_show1_return->setGeometry(QRect(40, 20, 31, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        btn_show1_return->setFont(font3);
        btn_show1_return->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_show1_return->setIcon(icon);
        lcdNumber_temp = new QLCDNumber(page_data_show1);
        lcdNumber_temp->setObjectName(QStringLiteral("lcdNumber_temp"));
        lcdNumber_temp->setGeometry(QRect(40, 80, 121, 211));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        lcdNumber_temp->setFont(font4);
        lcdNumber_temp->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border: 1px solid #B8B8B8;\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        lcdNumber_temp->setFrameShape(QFrame::Box);
        lcdNumber_temp->setSmallDecimalPoint(false);
        lcdNumber_temp->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_temp->setProperty("value", QVariant(24));
        btn_show1Toshow2 = new QPushButton(page_data_show1);
        btn_show1Toshow2->setObjectName(QStringLiteral("btn_show1Toshow2"));
        btn_show1Toshow2->setGeometry(QRect(40, 320, 261, 41));
        btn_show1Toshow2->setFont(font3);
        btn_show1Toshow2->setStyleSheet(QLatin1String("\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        lcdNumber_hum = new QLCDNumber(page_data_show1);
        lcdNumber_hum->setObjectName(QStringLiteral("lcdNumber_hum"));
        lcdNumber_hum->setGeometry(QRect(180, 80, 121, 211));
        lcdNumber_hum->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border: 1px solid #B8B8B8;\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        lcdNumber_hum->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_hum->setProperty("value", QVariant(77));
        label_2 = new QLabel(page_data_show1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 300, 121, 21));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_data_show1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 300, 121, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font5.setBold(false);
        font5.setWeight(50);
        label_3->setFont(font5);
        label_3->setAlignment(Qt::AlignCenter);
        label2_5 = new QLabel(page_data_show1);
        label2_5->setObjectName(QStringLiteral("label2_5"));
        label2_5->setGeometry(QRect(560, 330, 41, 41));
        label2_5->setFont(font5);
        label2_5->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);"));
        label2_5->setAlignment(Qt::AlignCenter);
        label1_3 = new QLabel(page_data_show1);
        label1_3->setObjectName(QStringLiteral("label1_3"));
        label1_3->setGeometry(QRect(460, 180, 251, 61));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setWeight(50);
        label1_3->setFont(font6);
        label1_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        label1_2 = new QLabel(page_data_show1);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setGeometry(QRect(460, 110, 251, 61));
        label1_2->setFont(font6);
        label1_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        label1_1 = new QLabel(page_data_show1);
        label1_1->setObjectName(QStringLiteral("label1_1"));
        label1_1->setGeometry(QRect(460, 40, 251, 61));
        label1_1->setFont(font6);
        label1_1->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        label1_6 = new QLabel(page_data_show1);
        label1_6->setObjectName(QStringLiteral("label1_6"));
        label1_6->setGeometry(QRect(460, 390, 251, 61));
        label1_6->setFont(font6);
        label1_6->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        imageSwitch1_2 = new ImageSwitch(page_data_show1);
        imageSwitch1_2->setObjectName(QStringLiteral("imageSwitch1_2"));
        imageSwitch1_2->setGeometry(QRect(630, 120, 71, 41));
        imageSwitch1_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        imageSwitch1_5 = new ImageSwitch(page_data_show1);
        imageSwitch1_5->setObjectName(QStringLiteral("imageSwitch1_5"));
        imageSwitch1_5->setGeometry(QRect(630, 330, 71, 41));
        imageSwitch1_5->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label2_3 = new QLabel(page_data_show1);
        label2_3->setObjectName(QStringLiteral("label2_3"));
        label2_3->setGeometry(QRect(560, 260, 41, 41));
        label2_3->setFont(font5);
        label2_3->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);"));
        label2_3->setAlignment(Qt::AlignCenter);
        imageSwitch1_3 = new ImageSwitch(page_data_show1);
        imageSwitch1_3->setObjectName(QStringLiteral("imageSwitch1_3"));
        imageSwitch1_3->setGeometry(QRect(630, 260, 71, 41));
        imageSwitch1_3->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label2_4 = new QLabel(page_data_show1);
        label2_4->setObjectName(QStringLiteral("label2_4"));
        label2_4->setGeometry(QRect(560, 190, 41, 41));
        label2_4->setFont(font5);
        label2_4->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);"));
        label2_4->setAlignment(Qt::AlignCenter);
        label1_4 = new QLabel(page_data_show1);
        label1_4->setObjectName(QStringLiteral("label1_4"));
        label1_4->setGeometry(QRect(460, 250, 251, 61));
        label1_4->setFont(font6);
        label1_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        label1_5 = new QLabel(page_data_show1);
        label1_5->setObjectName(QStringLiteral("label1_5"));
        label1_5->setGeometry(QRect(460, 320, 251, 61));
        label1_5->setFont(font6);
        label1_5->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        label2_6 = new QLabel(page_data_show1);
        label2_6->setObjectName(QStringLiteral("label2_6"));
        label2_6->setGeometry(QRect(560, 400, 41, 41));
        label2_6->setFont(font5);
        label2_6->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);"));
        label2_6->setAlignment(Qt::AlignCenter);
        imageSwitch1_6 = new ImageSwitch(page_data_show1);
        imageSwitch1_6->setObjectName(QStringLiteral("imageSwitch1_6"));
        imageSwitch1_6->setGeometry(QRect(630, 400, 71, 41));
        imageSwitch1_6->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        imageSwitch1_1 = new ImageSwitch(page_data_show1);
        imageSwitch1_1->setObjectName(QStringLiteral("imageSwitch1_1"));
        imageSwitch1_1->setGeometry(QRect(630, 50, 71, 41));
        imageSwitch1_1->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label2_1 = new QLabel(page_data_show1);
        label2_1->setObjectName(QStringLiteral("label2_1"));
        label2_1->setGeometry(QRect(560, 50, 41, 41));
        label2_1->setFont(font5);
        label2_1->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"\n"
"	"));
        label2_1->setAlignment(Qt::AlignCenter);
        label2_2 = new QLabel(page_data_show1);
        label2_2->setObjectName(QStringLiteral("label2_2"));
        label2_2->setGeometry(QRect(560, 120, 41, 41));
        label2_2->setFont(font5);
        label2_2->setStyleSheet(QLatin1String("background-color: rgb(71, 100, 104);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 18px;\n"
"\n"
"color: rgb(255, 255, 255);"));
        label2_2->setAlignment(Qt::AlignCenter);
        imageSwitch1_4 = new ImageSwitch(page_data_show1);
        imageSwitch1_4->setObjectName(QStringLiteral("imageSwitch1_4"));
        imageSwitch1_4->setGeometry(QRect(630, 190, 71, 41));
        imageSwitch1_4->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        stackedWidget->addWidget(page_data_show1);
        btn_show1_return->raise();
        lcdNumber_temp->raise();
        btn_show1Toshow2->raise();
        lcdNumber_hum->raise();
        label_2->raise();
        label_3->raise();
        label1_3->raise();
        label1_2->raise();
        label1_1->raise();
        label1_6->raise();
        imageSwitch1_2->raise();
        label2_4->raise();
        label1_4->raise();
        label1_5->raise();
        label2_6->raise();
        imageSwitch1_6->raise();
        imageSwitch1_1->raise();
        label2_1->raise();
        label2_2->raise();
        imageSwitch1_4->raise();
        label2_3->raise();
        imageSwitch1_3->raise();
        label2_5->raise();
        imageSwitch1_5->raise();
        page_data_show2 = new QWidget();
        page_data_show2->setObjectName(QStringLiteral("page_data_show2"));
        btn_show2_return = new QPushButton(page_data_show2);
        btn_show2_return->setObjectName(QStringLiteral("btn_show2_return"));
        btn_show2_return->setGeometry(QRect(740, 420, 31, 31));
        btn_show2_return->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        btn_show2_return->setIcon(icon);
        datashow1_tableview = new QTableView(page_data_show2);
        datashow1_tableview->setObjectName(QStringLiteral("datashow1_tableview"));
        datashow1_tableview->setGeometry(QRect(30, 30, 311, 361));
        datashow1_tableview->setStyleSheet(QStringLiteral("/*background-color: rgb(71,100,104);*/"));
        btn_show1_database_select = new QPushButton(page_data_show2);
        btn_show1_database_select->setObjectName(QStringLiteral("btn_show1_database_select"));
        btn_show1_database_select->setGeometry(QRect(30, 400, 51, 41));
        btn_show1_database_select->setFont(font3);
        btn_show1_database_select->setStyleSheet(QLatin1String("\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        label_graph = new QLabel(page_data_show2);
        label_graph->setObjectName(QStringLiteral("label_graph"));
        label_graph->setGeometry(QRect(390, 30, 381, 161));
        btn_show2Toshow3 = new QPushButton(page_data_show2);
        btn_show2Toshow3->setObjectName(QStringLiteral("btn_show2Toshow3"));
        btn_show2Toshow3->setGeometry(QRect(300, 400, 41, 41));
        btn_show2Toshow3->setFont(font3);
        btn_show2Toshow3->setStyleSheet(QLatin1String("\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        customPlot = new QCustomPlot(page_data_show2);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(390, 210, 381, 181));
        btn_show2_start_collect = new QPushButton(page_data_show2);
        btn_show2_start_collect->setObjectName(QStringLiteral("btn_show2_start_collect"));
        btn_show2_start_collect->setGeometry(QRect(100, 400, 81, 41));
        btn_show2_start_collect->setFont(font3);
        btn_show2_start_collect->setStyleSheet(QLatin1String("\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        btn_show2_stop_collect = new QPushButton(page_data_show2);
        btn_show2_stop_collect->setObjectName(QStringLiteral("btn_show2_stop_collect"));
        btn_show2_stop_collect->setGeometry(QRect(190, 400, 91, 41));
        btn_show2_stop_collect->setFont(font3);
        btn_show2_stop_collect->setStyleSheet(QLatin1String("\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	\n"
"	"));
        stackedWidget->addWidget(page_data_show2);
        page_data_show3 = new QWidget();
        page_data_show3->setObjectName(QStringLiteral("page_data_show3"));
        label_graph2 = new QLabel(page_data_show3);
        label_graph2->setObjectName(QStringLiteral("label_graph2"));
        label_graph2->setGeometry(QRect(280, 70, 221, 121));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font7.setPointSize(26);
        label_graph2->setFont(font7);
        label_graph2->setStyleSheet(QStringLiteral("color: rgb(240, 240, 240);"));
        label_graph2->setAlignment(Qt::AlignCenter);
        btn_show3_return = new QPushButton(page_data_show3);
        btn_show3_return->setObjectName(QStringLiteral("btn_show3_return"));
        btn_show3_return->setGeometry(QRect(720, 430, 31, 31));
        btn_show3_return->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"\n"
"border-radius: 15px;\n"
"background-color: rgb(71,100,104);\n"
"color: rgb(240, 240, 240);	"));
        btn_show3_return->setIcon(icon);
        label_5 = new QLabel(page_data_show3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 200, 631, 61));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setItalic(true);
        font8.setWeight(50);
        label_5->setFont(font8);
        label_5->setStyleSheet(QStringLiteral("color: rgb(240, 240, 240);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_data_show3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 240, 671, 51));
        label_6->setFont(font8);
        label_6->setStyleSheet(QStringLiteral("color: rgb(240, 240, 240);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_data_show3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 270, 571, 51));
        label_7->setFont(font8);
        label_7->setStyleSheet(QStringLiteral("color: rgb(240, 240, 240);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(page_data_show3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 300, 621, 51));
        label_8->setFont(font8);
        label_8->setStyleSheet(QStringLiteral("color: rgb(240, 240, 240);"));
        label_8->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_data_show3);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lineEdit_username->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        btn_login->setText(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btn_login->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_regiter->setText(QApplication::translate("MainWindow", "REGISTER", Q_NULLPTR));
        lineEdit_passwd->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        label_title->setText(QApplication::translate("MainWindow", "USER LOGIN", Q_NULLPTR));
        btn_show1_return->setText(QString());
        btn_show1Toshow2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\246\346\203\205", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", Q_NULLPTR));
        label2_5->setText(QApplication::translate("MainWindow", "\347\201\257", Q_NULLPTR));
        label1_3->setText(QApplication::translate("MainWindow", "  \345\215\247\345\256\244\357\274\232", Q_NULLPTR));
        label1_2->setText(QApplication::translate("MainWindow", "  \345\256\242\345\216\205\357\274\232", Q_NULLPTR));
        label1_1->setText(QApplication::translate("MainWindow", "  \345\256\242\345\216\205\357\274\232", Q_NULLPTR));
        label1_6->setText(QApplication::translate("MainWindow", "  \345\215\253\347\224\237\351\227\264\357\274\232", Q_NULLPTR));
        label2_3->setText(QApplication::translate("MainWindow", "\347\252\227", Q_NULLPTR));
        label2_4->setText(QApplication::translate("MainWindow", "\347\201\257", Q_NULLPTR));
        label1_4->setText(QApplication::translate("MainWindow", "  \345\215\247\345\256\244\357\274\232", Q_NULLPTR));
        label1_5->setText(QApplication::translate("MainWindow", "  \345\215\253\347\224\237\351\227\264\357\274\232", Q_NULLPTR));
        label2_6->setText(QApplication::translate("MainWindow", "\347\252\227", Q_NULLPTR));
        label2_1->setText(QApplication::translate("MainWindow", "\347\201\257", Q_NULLPTR));
        label2_2->setText(QApplication::translate("MainWindow", "\347\252\227", Q_NULLPTR));
        btn_show2_return->setText(QString());
        btn_show1_database_select->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        label_graph->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btn_show2Toshow3->setText(QApplication::translate("MainWindow", "\346\213\234\346\213\234", Q_NULLPTR));
        btn_show2_start_collect->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", Q_NULLPTR));
        btn_show2_stop_collect->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\351\207\207\351\233\206", Q_NULLPTR));
        label_graph2->setText(QApplication::translate("MainWindow", "\350\260\242\350\260\242\350\247\202\347\234\213", Q_NULLPTR));
        btn_show3_return->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Thanks to the whole group for working with each other", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Thanks to all the teachers for their help", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Software principals: RemMeiko Tan", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Hardware principals: Gong Yu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
