#ifndef SHOWMAINWINDOW_H
#define SHOWMAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "comform.h"
#include <QPushButton>
#include <QLabel>
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

//主界面按钮阴影配置
typedef enum{
    windButton = 0,
    PM2_5Button,
    humidityButton,
    tempeButton,
    lightButton,
}PushButtonSwitch_t;



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

    QPushButton *lightSwitch_Button;
    QLabel *lightSwitch_Label;

    //设置开关状态的flag
    bool lightFlag;

    QPixmap *pixmap;

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

    void switchIntofuction(QByteArray, QByteArray);

    QRectF textRectF(double radius, int pointSize, double angle);
    void paintEvent(QPaintEvent *event);

    void replayFinished(QNetworkReply *reply);
    void parseXml(QString Xml);
    void on_PM2_5_Button_clicked();
    void on_tempe_Button_clicked();
    void on_humidity_Button_clicked();
    void on_wind_Button_clicked();

    void on_lightSwitch_Button_clicked();

    void alterTheLightSwitch(int flag);

    void ButtonSetCheckable();
    void ButtonSetChecked(PushButtonSwitch_t );
    void WidgetSwitchShow(PushButtonSwitch_t );
    void WidgetInit();
    void on_light_Button_clicked();
};

#endif // SHOWMAINWINDOW_H
