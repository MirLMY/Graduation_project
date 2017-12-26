#ifndef SHOWMAINWINDOW_H
#define SHOWMAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "comform.h"
#include <QByteArray>
#include <QString>
#include "protocolanalysis.h"

#define IOT_SEND_HEAD 0x12

namespace Ui {
class ShowMainWindow;
}

class ShowMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowMainWindow(QWidget *parent = 0);
    ~ShowMainWindow();
    comForm *comform  = new comForm();

private:
    Ui::ShowMainWindow *ui;

private slots:
    void serialPortAction();
    void mysqlAction();
    void recv_serialport();


    void on_sendButton_clicked();
};

#endif // SHOWMAINWINDOW_H
