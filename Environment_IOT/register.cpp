#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->oldPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->newPassword_lineEdit->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}



void Register::on_pushButton_clicked()
{
    QString user = ui->user_Edit->text();
    QString oldPassword = ui->oldPasswordEdit->text();
    QString newPassword = ui->newPassword_lineEdit->text();

    //查询老密码和用户是否匹配，然后修改密码，再查询新密码是否修改成功
    QSqlQuery query;

    query.exec(QString("select user from user_password where user = '%1';").arg(user));
    query.next();
    QString checkUser = query.value(0).toString();
    if (checkUser == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("没有此用户");
        msgBox.exec();
    }
    else
    {
        query.exec(QString("select password from user_password where user = '%1';").arg(user));//查询user的密码，然后与输入密码比较
        query.next();
        if(query.value(0).toString() == oldPassword)
        {

            query.exec(QString("update user_password set password = '%1' where user = '%2';").arg(newPassword, user));//修改密码

            query.exec(QString("select password from user_password where user = '%1' ;").arg(user));
            query.next();

            QString password = query.value(0).toString();

            if(password == newPassword)
            {
                //关闭修改密码界面，并且打开登陆界面
                this->close();
                QMessageBox msgBox;
                msgBox.setText("密码修改成功");
                msgBox.exec();
                MainWindow *mainwidow = new MainWindow();
                mainwidow->show();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("密码修改不成功，请重新再试");
                msgBox.exec();

            }
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("旧密码错误，请重新输入");
            msgBox.exec();
        }
    }


}

void Register::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainwidow = new MainWindow();
    mainwidow->show();
}
