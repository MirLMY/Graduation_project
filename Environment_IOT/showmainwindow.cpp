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

    connect(comAction, SIGNAL(triggered()), this, SLOT(checkedLibAction()));
    connect(sqlAction,SIGNAL(triggered()),this,SLOT(checkedLibAction1()));
}

ShowMainWindow::~ShowMainWindow()
{
    delete ui;
}

void ShowMainWindow::checkedLibAction()
{
    qDebug()<<"ok";
}

void ShowMainWindow::checkedLibAction1()
{
    qDebug()<<"falser";
}
