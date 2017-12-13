#include "showmainwindow.h"
#include "ui_showmainwindow.h"
#include <QMenu>
#include <QDebug>



ShowMainWindow::ShowMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowMainWindow)
{
    ui->setupUi(this);

    QMenu *menu1= new QMenu("设置");
    QAction * comAction = new QAction(menu1);
    QAction * sqlAction = new QAction(menu1);
    sqlAction->setText("MYSQL数据");
    comAction->setText("串口配置");
    menu1->addAction(comAction);
    menu1->addAction(sqlAction);
    ui->menubar->addMenu(menu1);

    connect(comAction, SIGNAL(triggered()), this, SLOT(serialPortAction()));
    connect(sqlAction,SIGNAL(triggered()),this,SLOT(mysqlAction()));

}

ShowMainWindow::~ShowMainWindow()
{
    delete ui;
}

void ShowMainWindow::serialPortAction()
{

    comform->show();
    connect(comform->my_serialport,SIGNAL(readyRead()),this,SLOT(recv_serialport()));
}

void ShowMainWindow::mysqlAction()
{
    qDebug()<<"falser";
}

void ShowMainWindow::recv_serialport()
{
    qDebug()<<"in";
    QByteArray comBuf = comform->my_serialport->readAll();
    QString buf(comBuf);
    ui->textBrowser->setText(buf);

}
