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
    query.exec(QString("select user from user_password where user = '%1' and password = '%2' ;").arg(user,oldPassword));
    query.next();
    if(query.value(0).toString() == user)
    {
        qDebug()<<"dd";
        query.exec(QString("update user_password set password = '%1' where user = '%2';").arg(newPassword, user));

        query.exec(QString("select user from user_password where user = '%1' and password = '%2' ;").arg(user,newPassword));
        query.next();
        QString use = query.value(0).toString();

        if(user != use)
        {
            QMessageBox::critical(NULL, "Warning", "密码修改错误，请重新再试！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        else
        {
            //关闭修改密码界面，并且打开登陆界面
            this->close();
            QMessageBox msgBox;
            msgBox.setText("密码修改成功");
            msgBox.exec();
            MainWindow *mainwidow = new MainWindow();
            mainwidow->show();

        }
    }
}
