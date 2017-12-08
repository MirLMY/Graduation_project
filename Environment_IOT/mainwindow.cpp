#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open())
    {
        QErrorMessage msg(this);
        msg.setWindowTitle(tr("error"));
        msg.showMessage(tr("服务器连接错误,请重启服务器"));
        msg.exec();
    }

    ui->password_Edit->setEchoMode(QLineEdit::Password);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_landing_Button_clicked()
{
    //获取用户密码和用户账户
    QString user = ui->user_Edit->text();
    QString password = ui->password_Edit->text();

    QSqlQuery query;
    bool success = query.exec("select user from user_password where user ="+user+",password = "+password+";");
    query.next();
    qDebug()<<query.value(0).toString();


}
