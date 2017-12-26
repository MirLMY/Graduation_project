#include "mainwindow.h"
#include <QApplication>
#include <QErrorMessage>
#include "protocolanalysis.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open())
    {
        QErrorMessage *msg = new QErrorMessage();
        msg->setWindowTitle("error");
        msg->showMessage("服务器连接错误,请重启服务器");
        msg->exec();
    }
    QByteArray sendBuffer = "A3 52 33 01 10 2B 00 00 05 00 00 00 00 01 01 52";

    QByteArray rx_Buffer = QByteArray::fromHex(sendBuffer);
    ProtocolAnalysis w(rx_Buffer,rx_Buffer.length());
    w.bufferToJson();

    return a.exec();
}
