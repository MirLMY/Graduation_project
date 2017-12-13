#include "comform.h"
#include "ui_comform.h"
#include <QDebug>

#define BAUD_2400   0
#define BAUD_4800   1
#define BAUD_9600   2
#define BAUD_115200 3

#define NONE        0
#define ODD         1
#define EVEN        2
#define MARK        3
#define SPACE       4

#define ONESTOP                 0
#define ONEANDHALFStOP          1
#define TWOSTOP                 2

comForm::comForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comForm)
{
    //获取COM号，并添加到控件中去
    ui->setupUi(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->com_Box->addItem(info.portName());
    }
}

comForm::~comForm()
{
    delete ui;
}

void comForm::on_openClose_Button_clicked()
{
    //配置选取的COM口
    QString comPort = ui->com_Box->currentText();
    my_serialport->setPortName(comPort);

    //波特率配置
    switch (ui->baud_Box->currentIndex())
    {
    case BAUD_2400:
        my_serialport->setBaudRate(QSerialPort::Baud2400);
        break;
    case BAUD_4800:
        my_serialport->setBaudRate(QSerialPort::Baud4800);
        break;
    case BAUD_9600:
        my_serialport->setBaudRate(QSerialPort::Baud9600);
        break;
    case BAUD_115200:
        my_serialport->setBaudRate(QSerialPort::Baud115200);
        break;
    }
    //校验位配置
    switch (ui->parity_Box->currentIndex())
    {
    case NONE:
        my_serialport->setParity(QSerialPort::NoParity);
        break;
    case ODD:
        my_serialport->setParity(QSerialPort::OddParity);
        break;
    case EVEN:
        my_serialport->setParity(QSerialPort::EvenParity);
        break;
    case MARK:
        my_serialport->setParity(QSerialPort::MarkParity);
        break;
    case SPACE:
        my_serialport->setParity(QSerialPort::SpaceParity);
        break;
    default:
        my_serialport->setParity(QSerialPort::UnknownParity);
    }
    //数据位配置
    switch (ui->data_Box->currentText().toInt()) {
    case 5:
        my_serialport->setDataBits(QSerialPort::Data5);
        break;
    case 6:
        my_serialport->setDataBits(QSerialPort::Data6);
        break;
    case 7:
        my_serialport->setDataBits(QSerialPort::Data7);
        break;
    case 8:
        my_serialport->setDataBits(QSerialPort::Data8);
        break;
    }
    //停止位
    switch(ui->stop_Box->currentIndex())
    {
    case ONESTOP:
        my_serialport->setStopBits(QSerialPort::OneStop);
        break;
    case ONEANDHALFStOP:
        my_serialport->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    case TWOSTOP:
        my_serialport->setStopBits(QSerialPort::TwoStop);
        break;
    }
    my_serialport->open(QIODevice::ReadWrite);
    this->close();

}
