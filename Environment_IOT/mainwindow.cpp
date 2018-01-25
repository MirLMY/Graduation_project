#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "register.h"
#include "forgetpassword.h"

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
    delete showMainWindow;
}

//登陆按钮
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
        //清除错误密码
        //ui->user_Edit->setText(NULL);
        ui->password->setText(NULL);

        QMessageBox::critical(NULL, "Warning", "用户名不存在或者密码错误，请重新输入！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        showMainWindow = new ShowMainWindow();
        showMainWindow->show();
        this->close();
    }


}

void MainWindow::on_cancel_Button_clicked()
{
    close();
}


//修改密码UI界面
void MainWindow::on_forget_Button_clicked()
{
    this->close();
    Register *changePassword = new Register();
    changePassword->show();
    changePassword->setAttribute(Qt::WA_DeleteOnClose);
}

//注册账户UI界面
void MainWindow::on_pushButton_clicked()
{
    this->close();
    ForgetPassword *forgetPassword = new ForgetPassword();
    forgetPassword->show();
    forgetPassword->setAttribute(Qt::WA_DeleteOnClose);
}
