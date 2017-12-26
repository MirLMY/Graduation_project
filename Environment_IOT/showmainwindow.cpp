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
    delete comform;
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

//串口接收的串口数据
void ShowMainWindow::recv_serialport()
{
    QByteArray comBuffer = comform->my_serialport->readAll();//接收串口的内容
    int comBuffer_len = comBuffer.length();//记录接收数据长度

    qint16 checkSum = (comBuffer[comBuffer_len-2]<<8) | (comBuffer[comBuffer_len-1]);//提取接收数据后2位的校验位

    //校验位检测
    if(qChecksum(comBuffer, comBuffer_len-2) == checkSum)
    {
        ProtocolAnalysis protocolAnalysis(comBuffer,comBuffer.length()-2);//解析包
        QByteArray comBufferJson = protocolAnalysis.bufferToJson();
        //json解析出cmd，head,cmd
    }
    else
    {
        qDebug()<< "校验位不正确";
    }


}

void ShowMainWindow::on_sendButton_clicked()
{
    QByteArray sendBuffer = "A3 52 33 01 10 2B 00 00 05 00 00 00 00 01 01 52";

    QByteArray rx_Buffer = QByteArray::fromHex(sendBuffer);
    quint8 x = rx_Buffer[0];
    if(x = 0xa3)
    {
        qDebug()<<x<<QString::number(x,16);
    }
}
