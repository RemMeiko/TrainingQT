#include "widget.h"
#include "ui_widget.h"
#include "furniture.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 对应标志位初始化
    switchLabel = {0,0,0,0,0,0,0};
    isReset = false;

    timer = new QTimer(this);
    timer->start();
    // timer->stop();
    timer->setInterval (1000) ;//设置定时周期，单位：毫秒
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    // 隐藏掉计时部分

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    this->setWindowModality(Qt::ApplicationModal);  //阻塞除当前窗体之外的所有的窗体
    this->installEventFilter(this);

   ui->widget->setStyleSheet(QString("QWidget#widget{border-image: url(:/resources/background/1.png);}"));//.arg(1));
    qDebug() << "Funrntiure:" << Furniture::flag_type;

    qint8 imageswitchcount = ui->widget->findChildren<ImageSwitch*>().count(); // 开关控件数量
    qint8 labelcount = ui->widget->findChildren<QLabel*>().count(); // 窗户控件的数量
    for(int i = 1; i <= imageswitchcount;i++)
    {
        QString name = QString("imageSwitch1_%1").arg(i);
        ImageSwitch* imageSwitch1 = ui->widget->findChild<ImageSwitch*>(name); //根据子控件的名称查找
        images.insert(name,imageSwitch1);
    }
    for(int j =1; j <=2;j++)
    {
        for(int i = 1; i <= labelcount;i++)
        {
            QString name = QString("label%1_%2").arg(j).arg(i);
            QLabel* label = ui->widget->findChild<QLabel*>(name); //根据子控件的名称查找
            labels.insert(name,label);
        }
    }

//    // 绑定事件
//    for(int i = 0;i < imageswitchcount;i++)
//    {
//        imageName = QString("imageSwitch1_%1").arg(i);
//        labelName = QString("label2_%1").arg(i);
//        connect(images.value(imageName),SIGNAL(clicked()),this,SLOT(Sign()));
//    }
    QString PicLedUp = "QLabel{border-image: url(:/resources/background/ico_up.png);}";
    QString PicLedDown = "QLabel{border-image: url(:/resources/background/ico_down.png);}";
    QString PicWindowUp = "QLabel{border-image: url(:/resources/background/2_window_up.png);}";
    QString PicWindowDown = "QLabel{border-image: url(:/resources/background/2_window_down.png);}";
    listdata.append(PicLedUp);listdata.append(PicLedDown);
    listdata.append(PicWindowUp);listdata.append(PicWindowDown);


}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *evt)
{
    static int index = 1;
    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - this->pos();

            if (index == 4) {
                index = 1;
            } else {
                index++;
            }
            // ui->widget->setStyleSheet(QString("QWidget#widget{border-image: url(:/resources/background/%1.png);}").arg(1));//arg(index));
            return true;
        } else if(event->button() == Qt::RightButton){ // 右键关闭
            this->close();
            return true;
        } else {
            exit(0);
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            this->move(event->globalPos() - mousePoint);
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

// 定时器处理函数
void Widget::on_timer_timeout()
{
    if(Furniture::flag_type == 2) // 显示窗户背景
    {
        if(isReset)
        {
            ui->widget->setStyleSheet(QString("QWidget#widget{border-image: url(:/resources/background/2_window.png);}"));//.arg(1));
            for(int i = 1;i <= 6;i++)
            {
                labels.value(QString("label2_%1").arg(i))->setStyleSheet(listdata[3]);
                if(images.value(QString("imageSwitch1_%1").arg(i))->isChecked)
                {
                    images.value(QString("imageSwitch1_%1").arg(i))->setChecked(false);
                    switchLabel[i-1] ++;
                }
            }
            isReset = false;
        }
    } else { // 显示灯光背景
        if(isReset)
        {
            ui->widget->setStyleSheet(QString("QWidget#widget{border-image: url(:/resources/background/1.png);}"));//.arg(1));
            for(int i = 1;i <= 6;i++)
            {
                labels.value(QString("label2_%1").arg(i))->setStyleSheet(listdata[1]);
                if(images.value(QString("imageSwitch1_%1").arg(i))->isChecked)
                {
                    images.value(QString("imageSwitch1_%1").arg(i))->setChecked(false);
                    switchLabel[i-1] ++;
                }
            }
            isReset = false;
        }
    }
}

// 处理灯泡和窗户两种情况的显示
void Widget::dealCombobox1(QLabel *label,qint8  type,qint8 index)
{
    if(index == 1)// 灯泡
    {
        if(type % 2 == 1)
        {
            label->setStyleSheet(listdata[0]);
        } else{
            label->setStyleSheet(listdata[1]);

        }
    }
    else if(index == 2) // 窗户
    {
        if(type % 2 == 1)
        {
            label->setStyleSheet(listdata[2]);
        } else{
            label->setStyleSheet(listdata[3]);
        }
    }
}

void Widget::on_imageSwitch1_1_clicked()
{
    switchLabel[0]++;
    dealCombobox1(ui->label2_1,switchLabel[0],Furniture::flag_type);
}
void Widget::on_imageSwitch1_2_clicked()
{
    switchLabel[1]++;
    dealCombobox1(ui->label2_2,switchLabel[1],Furniture::flag_type);
}
void Widget::on_imageSwitch1_3_clicked()
{
    switchLabel[2]++;
    dealCombobox1(ui->label2_3,switchLabel[2],Furniture::flag_type);
}
void Widget::on_imageSwitch1_4_clicked()
{
    switchLabel[3]++;
    dealCombobox1(ui->label2_4,switchLabel[3],Furniture::flag_type);
}
void Widget::on_imageSwitch1_5_clicked()
{
    switchLabel[4]++;
    dealCombobox1(ui->label2_5,switchLabel[4],Furniture::flag_type);
}
void Widget::on_imageSwitch1_6_clicked()
{
    switchLabel[5]++;
    dealCombobox1(ui->label2_6,switchLabel[5],Furniture::flag_type);
}
