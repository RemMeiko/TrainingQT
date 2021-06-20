#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QLabel>
#include <QMovie>
#include <QImage>
#include <QPropertyAnimation>

#include <QSqlQueryModel>
#include <QTableView>
#include "imageswitch.h"
#include "qcustomplot.h"
#include <QTimer>
#include <QVector>

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_login_register);

    /*窗口标题*/
    this->setWindowTitle("Login & Register");

    /*窗口图标*/
    this->setWindowIcon(QIcon(":/new/prefix1/images/ico.png"));

    /*加载登录界面的gif*/
//    QMovie *movie = new QMovie(":/new/prefix1/images/loading.gif");
//    ui->label->setMovie(movie);
//    movie->start();
    /*--------------*/




    /*花里胡哨的按钮*/
    //ImageSwitch image;
//    ui->imageSwitch1->setChecked(false);
//    ui->imageSwitch1->setFixedSize(87, 28);
//    ui->imageSwitch1->setButtonStyle(ImageSwitch::ButtonStyle_2);

    /*-----------------------定时器初始化*---------------------------*/
    timer = new QTimer(this);
    timer->start();
    timer->setInterval (500) ;//设置定时周期，单位：毫秒
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));

    qint8 imageswitchcount = ui->page_data_show1->findChildren<ImageSwitch*>().count();
    qint8 labelcount = ui->page_data_show1->findChildren<QLabel*>().count();
    for(int i = 1; i <= imageswitchcount;i++)
    {
        QString name = QString("imageSwitch1_%1").arg(i);
        ImageSwitch* imageSwitch1 = ui->page_data_show1->findChild<ImageSwitch*>(name); //根据子控件的名称查找
        images.insert(name,imageSwitch1);
    }

    for(int j =1; j <=2;j++)
    {
        for(int i = 1; i <= labelcount;i++)
        {
            QString name = QString("label%1_%2").arg(j).arg(i);
            QLabel* label = ui->page_data_show1->findChild<QLabel*>(name); //根据子控件的名称查找
            labels.insert(name,label);
        }
    }
    /*--------------------------------------------------------*/




    /*----------------------tableview的样式优化---------------------------------*/
    ui->datashow1_tableview->setShowGrid(false); //网格线取消
    //ui->datashow1_tableview->setTextElideMode();



    /*--------------------画静态折线图-----------------------------------------------*/

    QCustomPlot *pCustomPlot = new QCustomPlot(ui->label_graph);
    //添加一条曲线
    QCPGraph* pgraph = pCustomPlot->addGraph();
    //给曲线准备数据 设置数据
    QVector<double> x(80000);
    QVector<double> y(80000);

    for(int i = 0; i<x.size();i++)
       {
           x[i] = i;
           if(i%2==0)
               y[i] = 10;
           else
               y[i] = 20;
       }

    int i = 0;
    if(i < 7)
    {
        y[0] = 25;
        y[1] = 32;
        y[2] = 32;
        y[3] = 28;
        y[4] = 26;
        y[5] = 22;
        y[6] = 32;
    }

    else
    {
        for(int a = 0; a<x.size();i++)
           {
               x[a] = a;
               if(a%2==0)
                   y[a] = 10;
               else
                   y[a] = 20;
           }
    }





    pCustomPlot->setBackground(QColor(71,100,104));
    pCustomPlot->graph(0)->setPen(QPen(Qt::white)); // 曲线的颜色


    //设置数据
    pCustomPlot->graph(0)->setData(x,y);

    //设置Y轴范围
    pCustomPlot->yAxis->setRange(0,30);
    //x轴名字
    pCustomPlot->xAxis->setLabel("X");
    //Y轴名字
    pCustomPlot->yAxis->setLabel("temperature");
    //设置大小
    pCustomPlot->resize(ui->label_graph->width(),ui->label_graph->height());
    //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
    pCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    //重绘 每次改变完以后都要调用这个进行重新绘制
    pCustomPlot->replot();


    /*------------------------------------------------------------------------------*/



    /*--------------------画时间为坐标轴的静态折线图-----------------------------------------------*/

//    QCustomPlot* p2 = new QCustomPlot(ui->label_graph2);

//    QVector<double> time;
//    QVector<double> y2;

//    //模拟几个时间 .toTime_t()是转换为 时间戳 从1970年到现在的秒数
//    time<<QDateTime::fromString("2019-01-15 17:08:23","yyyy-MM-dd hh:mm:ss").toTime_t();
//    time<<QDateTime::fromString("2019-01-25 17:08:23","yyyy-MM-dd hh:mm:ss").toTime_t();
//    time<<QDateTime::fromString("2019-02-15 17:08:23","yyyy-MM-dd hh:mm:ss").toTime_t();
//    time<<QDateTime::fromString("2019-02-25 17:08:23","yyyy-MM-dd hh:mm:ss").toTime_t();
//    time<<QDateTime::fromString("2019-03-27 13:08:23","yyyy-MM-dd hh:mm:ss").toTime_t();

//    y2<<5<<15<<5<<15<<5;

//    //增加一条线
//    p2->addGraph();
//    //设置Y轴范围
//    p2->yAxis->setRange(0,20);

//    //QCPAxisTickerDateTime 时间坐标轴 必须要用 智能指针
//    QSharedPointer<QCPAxisTickerDateTime> timer(new QCPAxisTickerDateTime);

//    //设置时间格式
//    timer->setDateTimeFormat("yyyy-MM-dd");
//    //设置时间轴 一共几格
//    //timer->setTickCount(6);
//    //设置label 旋转30° 横着显示可能显示不全
//    p2->xAxis->setTickLabelRotation(30);

//   // timer->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
//    //设置坐标轴
//    p2->xAxis->setTicker(timer);

//    p2->xAxis->setRange(time.at(0),time.at(4));

//    p2->graph(0)->setData(time,y2);

//    p2->resize(ui->label_graph2->width(),ui->label_graph2->height());

//    p2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


    /*------------------------------------------------------------------------------*/




    /*利用提升部件画个图-----------------------------------------------------------------*/

//    QCustomPlot *customPlot = ui->customPlot;
//    //每条曲线都会独占一个graph()


//    customPlot->setBackground(QColor(207,207,207)); //设置画布背景色
////    customPlot->xAxis->setTickLabelColor(QColor(146,168,204));
////    customPlot->yAxis->setTickLabelColor(QColor(146,168,204));

//    //设置坐标线颜色
//    customPlot->xAxis->setBasePen(QColor(146, 168, 204));//设置x坐标线颜色
//    customPlot->yAxis->setBasePen(QColor(146, 168, 204));//设置y坐标线颜色
//    customPlot->xAxis->setTickPen(QColor(146, 168, 204));//设置x坐标线上大分格线颜色
//    customPlot->yAxis->setTickPen(QColor(146, 168, 204));//设置y坐标线上大分格线颜色
//    customPlot->xAxis->setSubTickPen(QColor(146, 168, 204));//设置x坐标线上小分格线颜色
//    customPlot->yAxis->setSubTickPen(QColor(146, 168, 204));//设置y坐标线上小分格线颜色

//    //选框放大样式
//    customPlot->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
//    customPlot->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
//    customPlot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
//    //

//    customPlot->addGraph();
//    customPlot->graph(0)->setPen(QPen(Qt::blue)); // 曲线的颜色
//    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // 曲线与X轴包围区的颜色
//    customPlot->addGraph();//添加graph等价于添加新曲线
//    customPlot->graph(1)->setPen(QPen(Qt::red)); // 曲线的颜色
//    // 生成模拟数据点 (x1-y0 第一条曲线, x1-y1为第2条曲线):
//    QVector<double> x1(251), y0(251), y1(251);
//    for (int i=0; i<251; ++i)
//    {
//      x1[i] = i;
//      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // 第一条曲线：y0衰减cos
//      y1[i] = qExp(-i/150.0);              // 第二条曲线：y1衰减指数
//    }
//    // 边框右侧和上侧均显示刻度线，但不显示刻度值:
//    // (参见 QCPAxisRect::setupFullAxesBox for a quicker method to do this)
//    customPlot->xAxis2->setVisible(true);
//    customPlot->xAxis2->setTickLabels(false);
//    customPlot->yAxis2->setVisible(true);
//    customPlot->yAxis2->setTickLabels(false);
//    // 使上下两个X轴的范围总是相等，使左右两个Y轴的范围总是相等
//    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
//    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
//    // 把已存在的数据填充进graph的数据区
//    customPlot->graph(0)->setData(x1, y0);
//    customPlot->graph(1)->setData(x1, y1);
//    //自动调整XY轴的范围，以便显示出graph(0)中所有的点（下面会单独讲到这个函数）
//    customPlot->graph(0)->rescaleAxes();
//    //自动调整XY轴的范围，以便显示出graph(1)中所有的点
//    customPlot->graph(1)->rescaleAxes(true);
//    // 支持鼠标拖拽轴的范围、滚动缩放轴的范围，左键点选图层（每条曲线独占一个图层）
//    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
//    // 立即刷新图像
//    ui->customPlot->replot();


    /*------------------------------------------------------------------------------*/


    /*-------------------------------------柱形图------------------------------------*/
//    QVector<QString> labels(5);
//    QVector<double> values(5);
//    for(int i=0;i<5;++i)
//        labels[i]=QString("MAC")+('0'+i);
//    values[0]=(4);
//    values[1]=3;
//    values[2]=2;
//    values[3]=1;
//    values[4]=4.5;

//    QCPBars* bars=new QCPBars(ui->customPlot->xAxis,ui->customPlot->yAxis);
//    QVector<double> index(5);
//    for(int i=1;i<6;++i)
//        index[i]=i;
//    bars->setData(index,values);

////    ui->customPlot->xAxis->setAutoTicks(false);
////    ui->customPlot->xAxis->setAutoTickLabels(false);
////    ui->customPlot->xAxis->setAutoTickStep(false);

//    double wid=ui->customPlot->xAxis->range().upper - ui->customPlot->xAxis->range().lower;
//    double cl=bars->width()+(1.0*wid-bars->width()*5)/4;

//    QVector<double> coor;
//    for(int i=0;i<5;++i)
//        coor.append(ui->customPlot->xAxis->range().lower+i*cl+bars->width()/2);
////    ui->customPlot->xAxis->setTickVector(coor);
////    ui->customPlot->xAxis->setTickVectorLabels(labels);

//    ui->customPlot->replot();


    /*------------------------------------------------------------------------*/



    QCPAxis *keyAxis = ui->customPlot->xAxis;
    QCPAxis *valueAxis =ui->customPlot->yAxis;
    QCPBars *fossil = new QCPBars(keyAxis, valueAxis);  // 使用xAxis作为柱状图的key轴，yAxis作为value轴

    fossil->setAntialiased(false); // 为了更好的边框效果，关闭抗齿锯
    fossil->setName("Fossil fuels"); // 设置柱状图的名字，可在图例中显示
    fossil->setPen(QPen(QColor(0, 168, 140).lighter(130))); // 设置柱状图的边框颜色
    fossil->setBrush(QColor(0, 168, 140));  // 设置柱状图的画刷颜色

    // 为柱状图设置一个文字类型的key轴，ticks决定了轴的范围，而labels决定了轴的刻度文字的显示
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "1" << "2" << "3" << "4" << "5" << "6" << "7";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);

    keyAxis->setTicker(textTicker);        // 设置为文字轴

    keyAxis->setTickLabelRotation(1);     // 轴刻度文字旋转60度
    keyAxis->setSubTicks(false);           // 不显示子刻度
    keyAxis->setTickLength(0, 4);          // 轴内外刻度的长度分别是0,4,也就是轴内的刻度线不显示
    keyAxis->setRange(0, 8);               // 设置范围
    keyAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    valueAxis->setRange(0, 90);
    valueAxis->setPadding(35);             // 轴的内边距，可以到QCustomPlot之开始（一）看图解
    valueAxis->setLabel("humanity");
    valueAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QVector<double> fossilData;
    fossilData  << 65 << 55 << 74 << 43 << 77 << 85 << 62;
    fossil->setData(ticks, fossilData);






//    连接服务器数据库*/
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  //加入MYSQL的数据库驱动
//    db.setHostName("106.52.206.43");         //主机名
//    db.setPort(3306);                    //端口
//    db.setUserName("tan35");              //用户名
//    db.setPassword("899996");            //密码
//    db.setDatabaseName("tan35");          //数据库名


//    //测试连接
//    if(!db.open())//打开数据库
//    {
//      qDebug()<<"can not connec";
//      qDebug() << db.lastError();//打印错误信息
//    }
//    else
//    {
//       qDebug()<<"connect success";
//    }
//    /*--------------



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintBulb()
{
//    if(ui->imageSwitch1->getChecked())
//        qDebug() << "当前状态为:开";
}


void MainWindow::initserial()
{
    serial = new QSerialPort();
    //设置串口名
    serial->setPortName("ttyUSB0");
    //设置波特率
    serial->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//设置波特率和读写方向
    serial->setDataBits(QSerialPort::Data8);      //数据位为8位
    serial->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    serial->setParity(QSerialPort::NoParity); //无校验位
    serial->setStopBits(QSerialPort::OneStop); //一位停止位
    qDebug() << "serial connent:" << serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialDealdata()));
}

void MainWindow::serialDealdata()
{

    QByteArray buf;

    buf = serial->readAll();

    qDebug() << "buf:" << buf;

    if (buf.startsWith("temperature:")){
        QStringList list = QString(buf).split(",");
        QString temperature = list[0].mid(12,2);
        QString humidity = list[1].mid(9,2) ;
        qDebug() << "temperature:" << temperature;
        qDebug() << "humidity:" << humidity;
        temperature1 = temperature.toInt();
        humidity1 = humidity.toInt();
        ui->lcdNumber_temp->display(temperature1);
        ui->lcdNumber_hum->display(humidity1);
    }
}




//注册槽函数
void MainWindow::on_btn_regiter_clicked()
{
//    QString user = ui->lineEdit_username->text().trimmed();
//    QString passwd = ui->lineEdit_passwd->text().trimmed();

//    QSqlTableModel *model = new QSqlTableModel;
//    model->setTable("user");//选择数据表
//    model->setFilter(QString("name='%1'").arg(user));//设置查询过滤选项，此处查询用户名
//    model->select();//获取查询数据

//    int row = model->rowCount();
//    if(row>0)
//    {//查询到用户名已在数据库中
//        QMessageBox::information(this,"Sorry","用户已注册！");
//    }
//    else
//    {
//        QString cmd = QString("insert into user(name,password) values ('%1','%2')")
//                .arg(user).arg(passwd);
//        qDebug() << "cmd = " << cmd ;
//        QSqlQuery *query = new QSqlQuery;

//        if(query->exec(cmd))
//        {
//            QMessageBox::information(this,"Congratulations!","注册成功!");
//        }
//        else
//        {
//            QMessageBox::information(this,"Sorry","注册失败!请联系管理员");
//        }
//        delete query;
//        ui->lineEdit_passwd->clear();//清除密码输入框
//    }
}


//登录槽函数
void MainWindow::on_btn_login_clicked()
{
//    QString userName = ui->lineEdit_username->text().trimmed();
//    QString password = ui->lineEdit_passwd->text().trimmed();

//    QSqlTableModel *model = new QSqlTableModel;
//    model->setTable("user");
//    model->setFilter(QString("name='%1'").arg(userName));//查询用户名
//    model->select();

//    int row = model->rowCount();
//        if(row>0)
//        {//查询成功
//            row=0;
//            model->setFilter(QString("name='%1' and password='%2'").arg(userName).arg(password));//查询用户与密码
//            model->select();
//            row = model->rowCount();
//            if(row>0)
//            {//查询成功
//                qDebug()<< "登录成功";
//                QMessageBox::information(this,"Congratulations!","登录成功!欢迎进入查询界面");
//                //登录成功就打开datashow1的界面
                ui->stackedWidget->setCurrentWidget(ui->page_data_show1);
//            }
//            else
//            {
//                QMessageBox::information(this,"Sorry","密码错误，登录失败!");
//                ui->lineEdit_passwd->clear();
//            }
//        }
//        else
//        {//查询失败
//            QMessageBox::information(this,"Sorry","用户未注册!");
//        }

//        delete model;
}

//datashow1界面的返回按钮槽函数
void MainWindow::on_btn_show1_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login_register);
}

//datashow1界面跳转到datashow2的槽函数
void MainWindow::on_btn_show1Toshow2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_data_show2);
}

//datashow2界面的返回按钮槽函数
void MainWindow::on_btn_show2_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_data_show1);
}

void MainWindow::on_btn_show1_database_select_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from dataforht");
//    model->setHeaderData(0, Qt::Horizontal, tr("id"));
//    model->setHeaderData(1, Qt::Horizontal, tr("name"));
//    QTableView *view = new QTableView;
//    view->setModel(model);

    ui->datashow1_tableview->setModel(model);

}

void MainWindow::on_btn_show2Toshow3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_data_show3);
}

void MainWindow::on_btn_show3_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_data_show2);
}

void MainWindow::on_timer_timeout()
{



    for(int i = 1; i <= 6;i++)
    {
        QString imageName = QString("imageSwitch1_%1").arg(i);
        if(images.value(imageName)->isChecked)
        {
            QString labelName = QString("label2_%1").arg(i);
            labels.value(labelName)->setStyleSheet("QLabel{background-color: rgb(240, 240, 240);border-radius: 18px;}");

        } else if(!images.value(imageName)->isChecked)
        {
            QString labelName = QString("label2_%1").arg(i);
            labels.value(labelName)->setStyleSheet("QLabel{background-color: rgb(71, 100, 104);}");
        }
    }
    qDebug() << images.value("imageSwitch1_1");
    qDebug() << labels.value("label1_1");
}




