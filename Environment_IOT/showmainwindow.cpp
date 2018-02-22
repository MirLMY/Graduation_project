#include "showmainwindow.h"
#include "ui_showmainwindow.h"
#include <QDebug>
#include <QXmlStreamReader>
#include <QDateTime>
#include <QSqlQuery>
#include "macro.h"
#include <QSize>

ShowMainWindow::ShowMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowMainWindow)
{
    ui->setupUi(this);

    //设置pushbutton按下时有阴影
    ButtonSetCheckable();

    //灯开关控件初始化
    WidgetInit();

    comform = new comForm();

    menu1= new QMenu("设置");
    comAction = new QAction(menu1);
    sqlAction = new QAction(menu1);
    sqlAction->setText("MYSQL数据");
    comAction->setText("串口配置");
    menu1->addAction(comAction);
    menu1->addAction(sqlAction);
    ui->menubar->addMenu(menu1);

    manager = new QNetworkAccessManager(this);
    //天气API
    //URL_1 = "http://wthrcdn.etouch.cn/weather_mini?city=";
    //URL_2 = "http://wthrcdn.etouch.cn/WeatherApi?city="
    URL_2 = "http://wthrcdn.etouch.cn/WeatherApi?citykey=101270101";//成都天气xml

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replayFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl(URL_2)));

    //定时器中断初始化
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    dateTime = QDateTime::currentDateTime();//初始化获取时间戳
    timestamp = dateTime.toMSecsSinceEpoch();

    connect(comAction, SIGNAL(triggered()), this, SLOT(serialPortAction()));
    connect(sqlAction,SIGNAL(triggered()),this,SLOT(mysqlAction()));
}

ShowMainWindow::~ShowMainWindow()
{
    delete ui;
    if(comform != NULL)
    {
        delete comform;
        comform = NULL;
    }
    delete comAction;
    comAction = NULL;

    delete sqlAction;
    sqlAction = NULL;

    delete menu1;
    menu1 = NULL;

    delete lightSwitch_Button;
    delete lightSwitch_Label;
    lightSwitch_Button = NULL;
    lightSwitch_Label = NULL;

    delete pixmap;
    pixmap = NULL;

}

void ShowMainWindow::serialPortAction()
{

    comform->show();
    connect(comform->my_serialport,SIGNAL(readyRead()),this,SLOT(recv_serialport()));
}

void ShowMainWindow::mysqlAction()
{
    qDebug()<<"mysqlAction";
}

/*
    head    cmd     ip      info    checksum
    1bit    1bit    1bit    nbit    2bit
*/

//串口接收的串口数据
void ShowMainWindow::recv_serialport()
{
    QByteArray comBuffer, praseIp, praseInfo;
    int comBuffer_len = 0;
    quint16 checkSum = 0;
    comBuffer.clear();
    praseInfo.clear();
    praseIp.clear();

    comBuffer = comform->my_serialport->readAll();//接收串口的内容
    comBuffer_len = comBuffer.length();//记录接收数据长度
    praseIp = comBuffer.mid(2,1);
    praseInfo = comBuffer.mid(3,comBuffer_len - 3 - 2);//减去ip,cmd,head,checksum

    checkSum = ((comBuffer[comBuffer_len-2])<<8) | (comBuffer[comBuffer_len-1]);//提取接收数据后2位的校验位

    //校验位检测
//    qDebug() << "checksum is "<<QByteArray::number(checkSum,16);
//    qDebug() << QByteArray::number(qChecksum(comBuffer, comBuffer_len-2),16);
    if(/*qChecksum(comBuffer, comBuffer_len-2) == checkSum*/1)
    {
        if(comBuffer[0] == HEAD)
        {
            if(comBuffer[1] == CMD_GET_INFO)
            {
                qDebug() << praseInfo.toHex();
                switchIntofuction(praseIp, praseInfo);
            }
            else if(comBuffer[1] == CMD_PERIOD_INFO)
            {

            }
            else
            {
                qDebug() << "cmd 为其他命令";
            }
        }
        else
        {
            qDebug() << "包头不正确";
        }

    }
    else
    {
        qDebug()<< "校验位不正确";
    }
}

//解析CMD然后根据CMD 进入不同的prase函数
void ShowMainWindow::prase_cmd_package(QByteArray protocol)
{
    qDebug() << "in cmd package";
    //传过来的Buffer包含了校验位，在PtrotocolAnalysis类中没有去剔除校验位
    protocolAnalysis = new ProtocolAnalysis(protocol, protocol.length()-2);

    if(protocolAnalysis->bufferToHead() == HEAD)
    {
        switch (protocolAnalysis->bufferToCmd()) {
        case CMD_PERIOD_INFO:
            prase_period_info_package(protocolAnalysis->bufferToIp(), protocolAnalysis->bufferToInfo(), protocolAnalysis->infoLen);
            break;
        case CMD_GET_INFO:
            prase_get_info_package(protocolAnalysis->bufferToIp(), protocolAnalysis->bufferToInfo(), protocolAnalysis->infoLen);
            break;
        default:
            qDebug() << "other cmd";
        }
    }
    else
    {
        qDebug() << "head 错误！";
    }

    delete protocolAnalysis;
    protocolAnalysis = NULL;
}

//周期性回传数据
void ShowMainWindow::prase_period_info_package(quint8 ip, quint8 *info, int infoLen)
{
    QSqlQuery query;
    switch (ip) {
    case IP_WIND:

        break;
    case IP_THERMOMETER:

        break;
    case IP_HYGROMETER:

        break;
    case IP_INFRARED_BODY:

        break;
    case IP_PM2_5:

        break;
    case IP_FIRE:

        break;
    default:
        break;
    }

}

QString ShowMainWindow::prase_info_to_string(quint8* info, int infoLen)
{
    quint16 sum = 0;
    for(int i = 0;i < infoLen; i++)
    {
       sum += info[i];
    }


}

//下发查询指令回传数据
void ShowMainWindow::prase_get_info_package(quint8 ip,quint8 *info, int infoLen)
{
    QSqlQuery query;
    switch (ip) {
    case IP_WIND:

        break;
    case IP_THERMOMETER:

        break;
    case IP_HYGROMETER:

        break;
    case IP_INFRARED_BODY:

        break;
    case IP_PM2_5:

        break;
    case IP_FIRE:

        break;
    default:
        break;
    }
}

QRectF ShowMainWindow::textRectF(double radius, int pointSize, double angle)
{
    QRectF rectF;
    rectF.setX(radius*qCos(angle*M_PI/180.0) - pointSize*2);
    rectF.setY(radius*qSin(angle*M_PI/180.0) - pointSize/2.0);
    rectF.setWidth(pointSize*4);
    rectF.setHeight(pointSize);
    return rectF;
}

//时钟界面
void ShowMainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 时针、分针、秒针位置 - 多边形
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -30)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -65)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -80)
    };

    // 时针、分针、秒针颜色
    QColor hourColor(200, 100, 0, 200);
    QColor minuteColor(0, 127, 127, 150);
    QColor secondColor(0, 160, 230, 150);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    //每1s获取一次时间戳并且更新UI上显示时间
    dateTime = QDateTime::currentDateTime();
    timestamp = dateTime.toMSecsSinceEpoch();
    timeT = dateTime.toString();

    ui->date_label->setText(timeT);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // 平移坐标系原点至中心点
   // painter.translate(width() / 2, height() / 2);
    painter.translate(660, 150);

    // 缩放
   // painter.scale(side / 200.0, side / 200.0);

    // 绘制时针
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    painter.save();
    // 每圈360° = 12h 即：旋转角度 = 小时数 * 30°
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    // 绘制小时线 （360度 / 12 = 30度）
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    int radius = 100;
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    int pointSize = font.pointSize();

    // 绘制小时文本
    int nHour = 0;
    for (int i = 0; i < 12; ++i) {
        nHour = i + 3;
        if (nHour > 12)
            nHour -= 12;
        painter.drawText(textRectF(radius*0.8, pointSize, i * 30), Qt::AlignCenter, QString::number(nHour));
    }

    // 绘制分针
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    // 每圈360° = 60m 即：旋转角度 = 分钟数 * 6°
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    // 绘制分钟线 （360度 / 60 = 6度）
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    // 绘制秒针
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    // 每圈360° = 60s 即：旋转角度 = 秒数 * 6°
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}

//查询天气
void ShowMainWindow::replayFinished(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        //QString result(bytes);
        //qDebug()<<result;

            QString result(bytes);
            //qDebug()<<result;
            parseXml(result);


    }
    else
        QMessageBox::information(this,tr("出错啦"),tr("网络错误,请检查网络连接"),QMessageBox::Ok,QMessageBox::Ok);
        //qDebug()<<"网络出错\n";
}

void ShowMainWindow::parseXml(QString Xml)
{
    QXmlStreamReader xml(Xml);

    while(!xml.atEnd())
    {
        if(xml.hasError())
        {
            QMessageBox::information(this,tr("出错啦"),tr("数据出错,请重试"),QMessageBox::Ok,QMessageBox::Ok);
            return;
        }
        else if(xml.isStartElement())
        {
            if(xml.name()=="city")
            {
                today.city = xml.readElementText();
            }
            else if(xml.name() == "type")
            {
                today.type = xml.readElementText();

                xml.clear();

                ui->city_label->setText(tr("%1").arg(today.city));
                ui->forecast_0_type->setPixmap(QPixmap(tr(":/images/images/%1").arg(today.type)));

                return;
           }
            else
                xml.readNext();
        }
        else
            xml.readNext();
    }
    xml.clear();


}

void ShowMainWindow::on_PM2_5_Button_clicked()
{
    //pushbutton按下后取消其他按键阴影，只保留当前pushbutton阴影
    ButtonSetChecked(PM2_5Button);
    WidgetSwitchShow(PM2_5Button);
}

void ShowMainWindow::on_tempe_Button_clicked()
{
    //pushbutton按下后取消其他按键阴影，只保留当前pushbutton阴影
   ButtonSetChecked(tempeButton);
   WidgetSwitchShow(tempeButton);
}

void ShowMainWindow::on_humidity_Button_clicked()
{
   //pushbutton按下后取消其他按键阴影，只保留当前pushbutton阴影
    ButtonSetChecked(humidityButton);
    WidgetSwitchShow(humidityButton);
}

void ShowMainWindow::on_wind_Button_clicked()
{
   //pushbutton按下后取消其他按键阴影，只保留当前pushbutton阴影
    ButtonSetChecked(windButton);
    WidgetSwitchShow(windButton);
}

void ShowMainWindow::on_light_Button_clicked()
{
    ButtonSetChecked(lightButton);
    WidgetSwitchShow(lightButton);
}

void ShowMainWindow::on_lightSwitch_Button_clicked()
{
   //向灯光设备发送一条开关灯命令
}

/**
 *brief	打开界面中几个按钮的checkable
 *param
 *return
 *note
 */
void ShowMainWindow::ButtonSetCheckable()
{
    ui->PM2_5_Button->QAbstractButton::setCheckable(true);
    ui->wind_Button->QAbstractButton::setCheckable(true);
    ui->humidity_Button->QAbstractButton::setCheckable(true);
    ui->tempe_Button->QAbstractButton::setCheckable(true);
    ui->light_Button->QAbstractButton::setCheckable(true);
}

/**
 *brief	打开按下按钮的控件的阴影 and 关闭其他按钮控件的阴影
 *param 选择需要显示阴影的控件配置
 *return
 *note
 */
void ShowMainWindow::ButtonSetChecked(PushButtonSwitch_t pushButtonSwitch)
{
    ui->wind_Button->QAbstractButton::setChecked(false);
    ui->PM2_5_Button->QAbstractButton::setChecked(false);
    ui->humidity_Button->QAbstractButton::setChecked(false);
    ui->tempe_Button->QAbstractButton::setChecked(false);
    ui->light_Button->QAbstractButton::setChecked(false);

    switch (pushButtonSwitch) {
    case windButton:
        ui->wind_Button->QAbstractButton::setChecked(true);
        break;
    case PM2_5Button:
        ui->PM2_5_Button->QAbstractButton::setChecked(true);
        break;
    case humidityButton:
        ui->humidity_Button->QAbstractButton::setChecked(true);
        break;
    case tempeButton:
        ui->tempe_Button->QAbstractButton::setChecked(true);
        break;
    case lightButton:
        ui->light_Button->QAbstractButton::setChecked(true);
        break;
    default:
        break;
    }
}

/**
 *brief	初始化每个主界面按钮控制的控件
 *param 选择需要显示的控件
 *return
 *note
 */
void ShowMainWindow::WidgetInit()
{
    //灯光开关
    lightSwitch_Button = new QPushButton(this);
    lightSwitch_Label = new QLabel(this);

    pixmap = new QPixmap();
   // pixmap->scaled(lightSwitch_Label->size(),Qt::KeepAspectRatio);

    //打开label的pixmap充满整个Label的使能
    lightSwitch_Label->setScaledContents(true);

    lightSwitch_Button->setGeometry(300, 230, 75, 45);
    lightSwitch_Label->setGeometry(230, 230, 55, 55);

    //这里需要向灯光发送查询指令，查询开关状态
    pixmap->load(tr(":/images/images/light/%1").arg("light_off"));
    lightSwitch_Label->setPixmap(*pixmap);
    lightSwitch_Button->setIcon(QIcon(QPixmap(tr(":/images/images/light/%1").arg("switch_off"))));
    lightFlag = false;

    lightSwitch_Button->close();
    lightSwitch_Label->close();

    connect(lightSwitch_Button, SIGNAL(clicked()), this, SLOT(on_lightSwitch_Button_clicked()));
}

/**
 *brief	选择需要显示的控件
 *param
 *return
 *note
 */
void ShowMainWindow::WidgetSwitchShow(PushButtonSwitch_t pushButtonSwitch)
{
    lightSwitch_Button->close();
    lightSwitch_Label->close();


    switch (pushButtonSwitch) {
    case windButton:

        break;
    case PM2_5Button:

        break;
    case humidityButton:

        break;
    case tempeButton:

        break;
    case lightButton:
        lightSwitch_Button->show();
        lightSwitch_Label->show();
        break;
    default:
        break;
    }
}

/**
 *brief 通过ip来选择进入一个函数
 *param 传入这是那个设备发过来的消息IP，和传过来什么消息
 *return
 *note
 */
void ShowMainWindow::switchIntofuction(QByteArray praseIp, QByteArray praseInfo)
{
    switch (praseIp[0]) {
    case IP_LIGHT:
        alterTheLightSwitch(praseInfo[0]);
        break;
    }
}

void ShowMainWindow::alterTheLightSwitch(int flag)
{
    if(flag == 0x00)
    {
         pixmap->load(":/images/images/light/light_off.png");
         lightSwitch_Label->setPixmap(*pixmap);
         lightSwitch_Button->setIcon(QIcon(":/images/images/light/switch_off.png"));
    }
    else if(flag = 0x01)
    {

        pixmap->load(":/images/images/light/light_on.png");
        lightSwitch_Label->setPixmap(*pixmap);
        lightSwitch_Button->setIcon(QIcon(":/images/images/light/switch_on.png"));
    }
    else
    {
        qDebug() << "light flag 出错！！";
    }
}
