﻿//#pragma execution_character_set("utf-8")

#include "imageswitch.h"
#include "qpainter.h"
#include "qdebug.h"
#include <QDebug>
#include <QImage>

ImageSwitch::ImageSwitch(QWidget *parent) : QWidget(parent)
{
    isChecked = false;
    buttonStyle = ButtonStyle_2;

    imgOffFile = ":/new/prefix1/images/btncheckoff3.png";
    imgOnFile = ":/new/prefix1/images/btncheckon3.png";
    imgFile = imgOffFile;
}

void ImageSwitch::mousePressEvent(QMouseEvent *)
{
    imgFile = isChecked ? imgOffFile : imgOnFile;
    isChecked = !isChecked;
    qDebug() << "当前状态为：" << isChecked;
    this->update();
}




void ImageSwitch::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    QImage img(imgFile);
    img = img.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    //按照比例自动居中绘制
    int pixX = rect().center().x() - img.width() / 2;
    int pixY = rect().center().y() - img.height() / 2;
    QPoint point(pixX, pixY);
    painter.drawImage(point, img);
}

bool ImageSwitch::getChecked() const
{
    return isChecked;
}

ImageSwitch::ButtonStyle ImageSwitch::getButtonStyle() const
{
    return this->buttonStyle;
}

QSize ImageSwitch::sizeHint() const
{
    return QSize(87, 28);
}

QSize ImageSwitch::minimumSizeHint() const
{
    return QSize(87, 28);
}

void ImageSwitch::setChecked(bool isChecked)
{
    if (this->isChecked != isChecked) {
        this->isChecked = isChecked;
        imgFile = isChecked ? imgOnFile : imgOffFile;
        this->update();
    }
}

void ImageSwitch::setButtonStyle(const ImageSwitch::ButtonStyle &buttonStyle)
{
    if (this->buttonStyle != buttonStyle) {
        this->buttonStyle = buttonStyle;

        if (buttonStyle == ButtonStyle_1) {
            imgOffFile = ":/imageswitch/btncheckoff1.png";
            imgOnFile = ":/imageswitch/btncheckon1.png";
            this->resize(87, 28);
        } else if (buttonStyle == ButtonStyle_2) {
            imgOffFile = ":/imageswitch/btncheckoff2.png";
            imgOnFile = ":/imageswitch/btncheckon2.png";
            this->resize(87, 28);
        } else if (buttonStyle == ButtonStyle_3) {
            imgOffFile = ":/imageswitch/btncheckoff3.png";
            imgOnFile = ":/imageswitch/btncheckon3.png";
            this->resize(96, 38);
        }

        imgFile = isChecked ? imgOnFile : imgOffFile;
        setChecked(isChecked);
        this->update();
        updateGeometry();
    }
}
