#include "forgetpassword.h"
#include "ui_forgetpassword.h"

ForgetPassword::ForgetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
    ui->firstPassword_Edit->setEchoMode(QLineEdit::Password);
    ui->twicePassword_Edit->setEchoMode(QLineEdit::Password);
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
}

void ForgetPassword::on_push_Button_clicked()
{
    QString newUser = ui->user_Edit->text();
    QString firstPassword = ui->firstPassword_Edit->text();
    QString twicePassword = ui->twicePassword_Edit->text();

    //检查新用户名是否存在
    QSqlQuery query ;
    query.exec(QString("select user from user_password where user = '%1'").arg(newUser));
    query.next();
    if(query.value(0).toString() == NULL)
    {
        if(firstPassword == twicePassword)
        {
            query.exec(QString("insert into user_password value('%1','%2');").arg(newUser,firstPassword));
            QMessageBox msgBox;
            msgBox.setText("注册成功");
            msgBox.exec();

            MainWindow *mainwidow = new MainWindow();
            mainwidow->show();
            this->close();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("两次密码输入不一致");
            msgBox.exec();
        }

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("次用户已存在，请重新输入");
        msgBox.exec();
    }




}
