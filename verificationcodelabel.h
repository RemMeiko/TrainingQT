#ifndef VERIFICATIONCODELABEL_H
#define VERIFICATIONCODELABEL_H
////这是一个继承QLabel从而用来实现验证码功能的标签
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <QDebug>

class VerificationCodeLabel : public QLabel
{
    Q_OBJECT
public:
    VerificationCodeLabel(QWidget *parent=0);
    ~VerificationCodeLabel();
    //返回一个字符串（字母一律都按照大写返回）
    QString getVerificationCode() const;
    bool flag;     // 判断绘制何种验证码(定义成public类型是为了方便子在其他类中操作该数据)    为真时绘制不同的验证码 为假时绘制相同的验证码

public slots:       //公共槽函数
    void slt_reflushVerification();     //刷新验证码

protected:
    //重写绘制事件,以此来生成验证码
    void paintEvent(QPaintEvent *event);
    // 增加点击事件
    virtual void mouseReleaseEvent(QMouseEvent * ev);
private:
    const int letter_number = 4;//产生字符的数量
    int noice_point_number ;//噪点的数量
    enum {
        NUMBER_FLAG,
        UPLETTER_FLAG,
        LOWLETTER_FLAG
    };
    //这是一个用来生成验证码的函数
    QChar * produceVerificationCode() const;
    //产生一个随机的字符
    QChar produceRandomLetter() const;
    //产生随机的颜色
    QColor * produceRandomColor() const;
    // 这两个函数是可以直接写在重写的绘制事件中的
    void paintLabelDiff(); // 绘制随机验证码
    void paintLabelSame(); // 绘制相同验证码

    QChar *verificationCode;
    QColor *colorArray;

    // 用来记录上一次的数据
    QChar *verficiBackup;
    QColor *colorBackup;
signals:
    void clicked(void); // 点击信号
};

#endif // VERIFICATIONCODELABEL_H
