#ifndef SHOWMAINWINDOW_H
#define SHOWMAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "comform.h"
#include <QByteArray>
#include <QString>
#include "protocolanalysis.h"
#include <QMenu>

#include <QWidget>
#include <QRectF>
#include <QTime>
#include <QTimer>
#include <QPoint>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QtMath>

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
    comForm *comform ;
    QMenu *menu1;
    QAction * comAction;
    QAction * sqlAction;

private:
    Ui::ShowMainWindow *ui;

private slots:
    void serialPortAction();
    void mysqlAction();
    void recv_serialport();
    void on_sendButton_clicked();

    QRectF textRectF(double radius, int pointSize, double angle);
    void paintEvent(QPaintEvent *event);
};

#endif // SHOWMAINWINDOW_H
