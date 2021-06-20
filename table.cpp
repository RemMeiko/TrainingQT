#include "table.h"
#include "ui_table.h"


Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    // 加载相关信息
    this->setWindowTitle("数据可视化");
    this->setWindowIcon(QIcon(":/resources/ico.png"));

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    this->setWindowModality(Qt::ApplicationModal);  //阻塞除当前窗体之外的所有的窗体
    this->installEventFilter(this);

    // 绑定返回主窗口的信号
//    connect(ui->btn_return,&QPushButton::clicked,this,&Table::Sendslot);
    // 显示湿度
    requestForm();
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<5000)
        QCoreApplication::processEvents();
    QCPAxis *keyAxis = ui->customPlot_hum->xAxis;
    QCPAxis *valueAxis =ui->customPlot_hum->yAxis;
    QCPBars *humanity = new QCPBars(keyAxis, valueAxis);  // 使用xAxis作为柱状图的key轴，yAxis作为value轴

    humanity->setAntialiased(false); // 为了更好的边框效果，关闭抗齿锯
    humanity->setName("humanity fuels"); // 设置柱状图的名字，可在图例中显示
    humanity->setPen(QPen(QColor(0, 168, 140).lighter(130))); // 设置柱状图的边框颜色
    humanity->setBrush(QColor(0, 168, 140));  // 设置柱状图的画刷颜色

    // 为柱状图设置一个文字类型的key轴，ticks决定了轴的范围，而labels决定了轴的刻度文字的显示
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 8 << 9 << 10; // 横坐标
    labels << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);

    keyAxis->setTicker(textTicker);        // 设置为文字轴

    keyAxis->setTickLabelRotation(1);     // 轴刻度文字旋转60度
    keyAxis->setSubTicks(false);           // 不显示子刻度
    keyAxis->setTickLength(0, 4);          // 轴内外刻度的长度分别是0,4,也就是轴内的刻度线不显示
    keyAxis->setRange(0, 9);               // 设置范围
    keyAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    valueAxis->setRange(0, 100); // 范围
    valueAxis->setPadding(35);             // 轴的内边距，可以到QCustomPlot之开始（一）看图解
    valueAxis->setLabel("humanity");
    valueAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QVector<double> humanityData;
    humanityData  << humList[0].toDouble() << humList[1].toDouble() << humList[2].toDouble() << humList[3].toDouble() << humList[4].toDouble() << humList[5].toDouble() << humList[6].toDouble()
            << humList[7].toDouble() << humList[8].toDouble() << humList[9].toDouble();
    humanity->setData(ticks, humanityData);

    // 显示温度
    requestForm();
    QElapsedTimer q;
    q.start();
    while(q.elapsed()<5000)
        QCoreApplication::processEvents();
    keyAxis = ui->customPlot_tem->xAxis;
    valueAxis =ui->customPlot_tem->yAxis;
    QCPBars *temperature = new QCPBars(keyAxis, valueAxis);  // 使用xAxis作为柱状图的key轴，yAxis作为value轴

    temperature->setAntialiased(false); // 为了更好的边框效果，关闭抗齿锯
    temperature->setName("temperature fuels"); // 设置柱状图的名字，可在图例中显示
    temperature->setPen(QPen(QColor(0, 168, 140).lighter(130))); // 设置柱状图的边框颜色
    temperature->setBrush(QColor(0, 168, 140));  // 设置柱状图的画刷颜色

    // 为柱状图设置一个文字类型的key轴，ticks决定了轴的范围，而labels决定了轴的刻度文字的显示
    QVector<double> ticks2;
    QVector<QString> labels2;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 8 << 9 << 10; // 横坐标
    labels << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10";
    QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
    textTicker2->addTicks(ticks, labels);

    keyAxis->setTicker(textTicker2);        // 设置为文字轴

    keyAxis->setTickLabelRotation(1);     // 轴刻度文字旋转60度
    keyAxis->setSubTicks(false);           // 不显示子刻度
    keyAxis->setTickLength(0, 4);          // 轴内外刻度的长度分别是0,4,也就是轴内的刻度线不显示
    keyAxis->setRange(0, 9);               // 设置范围
    keyAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    valueAxis->setRange(0, 100); // 范围
    valueAxis->setPadding(35);             // 轴的内边距，可以到QCustomPlot之开始（一）看图解
    valueAxis->setLabel("temperature");
    valueAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QVector<double> temperatureData;
    temperatureData  << temList[0].toDouble() << temList[1].toDouble() << temList[2].toDouble() << temList[3].toDouble() << temList[4].toDouble() << temList[5].toDouble() << temList[6].toDouble()
            << temList[7].toDouble() << temList[8].toDouble() << temList[9].toDouble();
    temperature->setData(ticks, temperatureData);

    // 温度
    /*--------------------画静态折线图-----------------------------------------------*/
       QCustomPlot *pCustomPlot = new QCustomPlot(ui->label_tem);
       //添加一条曲线
       QCPGraph* pgraph = pCustomPlot->addGraph();
       //给曲线准备数据 设置数据
       QVector<double> x(10);
       QVector<double> y(800);
       for(int i = 0; i<x.size();i++)
          {
              x[i] = i;
              if(i%2==0)
                  y[i] = 10;
              else
                  y[i] = 20;
          }
       int i = 0;
       if(i < 10)
       {
           for(int i = 0;i < 10;i ++)
           {
               y[i] = temList[i].toDouble();
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
       pCustomPlot->resize(ui->label_tem->width(),ui->label_tem->height());
       //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
       pCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
       //重绘 每次改变完以后都要调用这个进行重新绘制
       pCustomPlot->replot();
       /*------------------------------------------------------------------------------*/
       // 湿度
       /*--------------------画静态折线图-----------------------------------------------*/
          pCustomPlot = new QCustomPlot(ui->label_hum);
          //添加一条曲线
          pgraph = pCustomPlot->addGraph();
          //给曲线准备数据 设置数据
          for(int i = 0; i<x.size();i++)
             {
                 x[i] = i;
                 if(i%2==0)
                     y[i] = 10;
                 else
                     y[i] = 20;
             }
          i = 0;
          if(i < 10)
          {
              for(int i = 0;i < 10;i ++)
              {
                  y[i] = humList[i].toDouble();
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
          pCustomPlot->yAxis->setLabel("humanity");
          //设置大小
          pCustomPlot->resize(ui->label_hum->width(),ui->label_hum->height());
          //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
          pCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
          //重绘 每次改变完以后都要调用这个进行重新绘制
          pCustomPlot->replot();
          /*------------------------------------------------------------------------------*/
}

Table::~Table()
{
    delete ui;
}

// 请求数据
void Table::requestForm()
{
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dealForm(QNetworkReply*)));
    Q_ASSERT(connRet);
    // 将账号作为参数进行url的构造
    request.setUrl(QUrl("https://web.remmeiko.top/API/QT.php?model=4"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString testData = QString("&id=1");
    naManager->post(request, testData.toUtf8());
}

// 处理获取的数据插入表格
void Table::dealForm(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        //官方文档显示返回的reply是json格式，所以我们采用json格式读取
        QByteArray allData = reply->readAll();
        QJsonParseError json_error;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));
        qDebug() << jsonDoc;
        if(json_error.error != QJsonParseError::NoError)
           {
               qDebug() << "json error!";
               return;
           }
          QJsonObject rootObj = jsonDoc.object();
          //我们只需要上传后的url，所以值提取了url，如果你需要其他内容，请提取方法类似
          if(rootObj.contains("data"))
            {
               QJsonValue subObj = rootObj.value("data");
               // 数据数组
               QJsonArray dataArray = subObj.toArray();
               for(int i = 0;i < dataArray.size();i++)
               {
                   QJsonObject subdata = dataArray.at(i).toObject();
                   QString humanity = subdata["humanity"].toString();
                   qDebug() << "湿度是：" << humanity;
                   QString temperature = subdata["temperature"].toString();
                   qDebug() << "温度是：" << temperature;
                   temList.append(temperature);
                   humList.append(humanity);
                   }
            }
    }
    else
    {
            qDebug() << "=========";
    }
    reply->deleteLater();
}

// 返回按钮
void Table::on_btn_return_clicked()
{

}

//// 发送信号
//void Table::Sendslot()
//{
//     emit MysignalFurn();
//}

