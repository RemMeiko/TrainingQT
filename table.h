#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QNetworkReply>
#include <QVector>
#include <QElapsedTimer>
#include "qcustomplot.h"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

private slots:
    void requestForm(); // 请求表格数据
    void dealForm(QNetworkReply*); // 处理表格数据
//    void Sendslot();// 给返回窗口发送信号

    void on_btn_return_clicked();

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();
    // 插入表格数据温度数据
    QList<QString> temList;
    QList<QString> humList;

private:
    Ui::Table *ui;

signals:
//    void MysignalFurn();
};

#endif // TABLE_H
