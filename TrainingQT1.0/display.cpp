#include "display.h"
#include "ui_display.h"
#include "mainwindow.h"

display::display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

    // connect(ui->btn_back,SIGNAL(clicked()),this,SLOT(OnBack()));
    connect(ui->btn_back,&QPushButton::clicked,this,&display::Sendslot);
}

display::~display()
{
    delete ui;
}

void display::OnBack()
{
    this->close();
}

void display::Sendslot()
{
     emit Mysignal();
}
