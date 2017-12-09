#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "register.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);

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
    query.exec(QString("select user from user_password where user = '%1' and password = '%2' ;").arg(user,password));
    query.next();
    QString use = query.value(0).toString();

    if(user != use)
    {
        QMessageBox::critical(NULL, "Warning", "密码错误，请重新输入密码！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }


}

void MainWindow::on_cancel_Button_clicked()
{
    close();
}


//修改密码registerUI界面
void MainWindow::on_forget_Button_clicked()
{
    this->close();
    Register *changePassword = new Register();
    changePassword->show();
}

void MainWindow::on_pushButton_clicked()
{

}
