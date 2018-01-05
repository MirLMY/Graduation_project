#ifndef SHOWMAINWINDOW_H
#define SHOWMAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "comform.h"
#include <QByteArray>
#include <QString>
#include "protocolanalysis.h"
#include <QMenu>
#include <QMessageBox>

#include <QWidget>
#include <QRectF>
#include <QTime>
#include <QTimer>
#include <QPoint>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QtMath>

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include<QPixmap>


#define IOT_SEND_HEAD 0x12

struct Today
{
    QString ganmao;
    QString city;
    QString updatetime;
    QString wendu;
    QString fengli;
    QString fengxiang;
    QString sunrise;
    QString sunset;
    QString shidu;
    QString type;
};

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
    QNetworkAccessManager *manager;
    QString URL_1;
    QString URL_2;

    int choose;
    Today today;

    ProtocolAnalysis *protocolAnalysis;
    QString timeT;
    QDateTime dateTime;
    qint64 timestamp;

private slots:
    void serialPortAction();
    void mysqlAction();
    void recv_serialport();
    void prase_cmd_package(QByteArray);
    void prase_period_info_package(quint8, quint8*, int);
    void prase_get_info_package(quint8, quint8*, int);
    QString prase_info_to_string(quint8*, int);


    QRectF textRectF(double radius, int pointSize, double angle);
    void paintEvent(QPaintEvent *event);

    void replayFinished(QNetworkReply *reply);
    void parseXml(QString Xml);
};

#endif // SHOWMAINWINDOW_H
