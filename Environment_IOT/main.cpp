#include "mainwindow.h"
#include <QApplication>
#include <QErrorMessage>
#include <QDebug>
#include <QByteArray>
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
    MainWindow w;
    w.show();

    return a.exec();
}
