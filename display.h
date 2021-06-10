#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

namespace Ui {
    class display;
}

class display : public QWidget
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();

private slots:
    void OnBack();//返回主界面
    void Sendslot();    // 给主窗口发送信号

private:
    Ui::display *ui;

signals:
    void Mysignal();                //返回值信号


};

#endif // DISPLAY_H
