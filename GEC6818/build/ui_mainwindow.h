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
    QLabel *label;
    QPushButton *btn_regiter;
    QLineEdit *lineEdit_passwd;
    QWidget *page_data_show1;
    QPushButton *btn_show1_return;
    QLCDNumber *lcdNumber_temp;
    QPushButton *btn_show1Toshow2;
    QLCDNumber *lcdNumber_hum;
    QLabel *label_2;
    QLabel *label_3;
    ImageSwitch *imageSwitch1;
    QLabel *label_bulb_on;
    QLabel *label_bulb_off;
    QWidget *page_data_show2;
    QPushButton *btn_show2_return;
    QTableView *datashow1_tableview;
    QPushButton *btn_show1_database_select;
    QLabel *label_graph;
    QPushButton *btn_show2Toshow3;
    QWidget *page_data_show3;
    QLabel *label_graph2;
    QPushButton *btn_show3_return;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	border: 1px solid #B8B8B8;\n"
"	border-radius: 6px;\n"
"	padding: 2px;\n"
"	background: none;\n"
"	selection-background-color: #454648;\n"
"}\n"
"\n"
"\n"
"QPushButton#btn_login,QPushButton#btn_regiter\n"
"{\n"
"	border: 1px solid #B8B8B8;\n"
"	border-radius: 6px;\n"
"	\n"
"	background-color: rgb(240, 240, 240);\n"
"	color: rgb(59, 61, 83);\n"
"}\n"
"\n"
"QPushButton#btn_login:hover\n"
"{\n"
"	\n"
"	background-color: rgb(59, 61, 83);\n"
"	\n"
"	color: rgb(255, 240, 251);\n"
"}\n"
"\n"
"QPushButton#btn_regiter:hover\n"
"{\n"
"	\n"
"	background-color: rgb(59, 61, 83);\n"
"	\n"
"	color: rgb(255, 240, 251);\n"
"}\n"
"\n"
"QWidget#centralWidget\n"
"{\n"
"	/*image: url(:/new/prefix1/images/bg.png);*/\n"
"}\n"
"\n"
"/*QLabel#label_2\n"
"{\n"
"	\n"
"	color: rgb(240, 240, 240);\n"
"}*/"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 800, 480));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#page_login_register\n"
"{\n"
"	\n"
"	image: url(:/new/prefix1/images/bg.png);\n"
"}"));
        page_login_register = new QWidget();
        page_login_register->setObjectName(QStringLiteral("page_login_register"));
        lineEdit_username = new QLineEdit(page_login_register);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(60, 50, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font.setPointSize(10);
        lineEdit_username->setFont(font);
        btn_login = new QPushButton(page_login_register);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(60, 170, 111, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font1.setPointSize(11);
        btn_login->setFont(font1);
        label = new QLabel(page_login_register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 50, 191, 161));
        btn_regiter = new QPushButton(page_login_register);
        btn_regiter->setObjectName(QStringLiteral("btn_regiter"));
        btn_regiter->setGeometry(QRect(200, 170, 111, 51));
        btn_regiter->setFont(font1);
        lineEdit_passwd = new QLineEdit(page_login_register);
        lineEdit_passwd->setObjectName(QStringLiteral("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(60, 110, 251, 41));
        lineEdit_passwd->setFont(font);
        stackedWidget->addWidget(page_login_register);
        page_data_show1 = new QWidget();
        page_data_show1->setObjectName(QStringLiteral("page_data_show1"));
        btn_show1_return = new QPushButton(page_data_show1);
        btn_show1_return->setObjectName(QStringLiteral("btn_show1_return"));
        btn_show1_return->setGeometry(QRect(40, 400, 91, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        btn_show1_return->setFont(font2);
        lcdNumber_temp = new QLCDNumber(page_data_show1);
        lcdNumber_temp->setObjectName(QStringLiteral("lcdNumber_temp"));
        lcdNumber_temp->setGeometry(QRect(40, 80, 121, 211));
        lcdNumber_temp->setProperty("value", QVariant(24));
        btn_show1Toshow2 = new QPushButton(page_data_show1);
        btn_show1Toshow2->setObjectName(QStringLiteral("btn_show1Toshow2"));
        btn_show1Toshow2->setGeometry(QRect(40, 350, 251, 41));
        btn_show1Toshow2->setFont(font2);
        lcdNumber_hum = new QLCDNumber(page_data_show1);
        lcdNumber_hum->setObjectName(QStringLiteral("lcdNumber_hum"));
        lcdNumber_hum->setGeometry(QRect(170, 80, 121, 211));
        lcdNumber_hum->setProperty("value", QVariant(77));
        label_2 = new QLabel(page_data_show1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 300, 121, 21));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_data_show1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 300, 121, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\350\267\235\346\233\264\347\272\261\351\273\221\344\275\223 SC"));
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignCenter);
        imageSwitch1 = new ImageSwitch(page_data_show1);
        imageSwitch1->setObjectName(QStringLiteral("imageSwitch1"));
        imageSwitch1->setGeometry(QRect(340, 380, 91, 51));
        label_bulb_on = new QLabel(page_data_show1);
        label_bulb_on->setObjectName(QStringLiteral("label_bulb_on"));
        label_bulb_on->setGeometry(QRect(310, 100, 231, 241));
        label_bulb_off = new QLabel(page_data_show1);
        label_bulb_off->setObjectName(QStringLiteral("label_bulb_off"));
        label_bulb_off->setGeometry(QRect(600, 120, 161, 221));
        stackedWidget->addWidget(page_data_show1);
        page_data_show2 = new QWidget();
        page_data_show2->setObjectName(QStringLiteral("page_data_show2"));
        btn_show2_return = new QPushButton(page_data_show2);
        btn_show2_return->setObjectName(QStringLiteral("btn_show2_return"));
        btn_show2_return->setGeometry(QRect(80, 390, 75, 23));
        datashow1_tableview = new QTableView(page_data_show2);
        datashow1_tableview->setObjectName(QStringLiteral("datashow1_tableview"));
        datashow1_tableview->setGeometry(QRect(30, 30, 231, 151));
        btn_show1_database_select = new QPushButton(page_data_show2);
        btn_show1_database_select->setObjectName(QStringLiteral("btn_show1_database_select"));
        btn_show1_database_select->setGeometry(QRect(60, 210, 121, 41));
        label_graph = new QLabel(page_data_show2);
        label_graph->setObjectName(QStringLiteral("label_graph"));
        label_graph->setGeometry(QRect(320, 30, 431, 371));
        btn_show2Toshow3 = new QPushButton(page_data_show2);
        btn_show2Toshow3->setObjectName(QStringLiteral("btn_show2Toshow3"));
        btn_show2Toshow3->setGeometry(QRect(170, 430, 121, 41));
        stackedWidget->addWidget(page_data_show2);
        page_data_show3 = new QWidget();
        page_data_show3->setObjectName(QStringLiteral("page_data_show3"));
        label_graph2 = new QLabel(page_data_show3);
        label_graph2->setObjectName(QStringLiteral("label_graph2"));
        label_graph2->setGeometry(QRect(50, 40, 321, 241));
        btn_show3_return = new QPushButton(page_data_show3);
        btn_show3_return->setObjectName(QStringLiteral("btn_show3_return"));
        btn_show3_return->setGeometry(QRect(640, 360, 75, 23));
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
        btn_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btn_login->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btn_regiter->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        lineEdit_passwd->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        btn_show1_return->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_show1Toshow2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\246\346\203\205", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", Q_NULLPTR));
        label_bulb_on->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_bulb_off->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btn_show2_return->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_show1_database_select->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        label_graph->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btn_show2Toshow3->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255\346\237\245\347\234\213\350\257\246\346\203\205", Q_NULLPTR));
        label_graph2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btn_show3_return->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
