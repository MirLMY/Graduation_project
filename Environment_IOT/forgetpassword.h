#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class ForgetPassword;
}

class ForgetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ForgetPassword(QWidget *parent = 0);
    ~ForgetPassword();

private slots:
    void on_push_Button_clicked();

private:
    Ui::ForgetPassword *ui;
};

#endif // FORGETPASSWORD_H
