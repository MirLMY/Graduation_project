#include "showmainwindow.h"
#include "ui_showmainwindow.h"
#include <QDebug>
#include <QXmlStreamReader>

ShowMainWindow::ShowMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowMainWindow)
{
    ui->setupUi(this);

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

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    connect(comAction, SIGNAL(triggered()), this, SLOT(serialPortAction()));
    connect(sqlAction,SIGNAL(triggered()),this,SLOT(mysqlAction()));
}

ShowMainWindow::~ShowMainWindow()
{
    delete ui;
    delete comform;
    delete comAction;
    delete sqlAction;
    delete menu1;
}

void ShowMainWindow::serialPortAction()
{

    comform->show();
    connect(comform->my_serialport,SIGNAL(readyRead()),this,SLOT(recv_serialport()));
}

void ShowMainWindow::mysqlAction()
{
    qDebug()<<"falser";
}

//串口接收的串口数据
void ShowMainWindow::recv_serialport()
{
    QByteArray comBuffer = comform->my_serialport->readAll();//接收串口的内容
    int comBuffer_len = comBuffer.length();//记录接收数据长度

    qint16 checkSum = (comBuffer[comBuffer_len-2]<<8) | (comBuffer[comBuffer_len-1]);//提取接收数据后2位的校验位

    //校验位检测
    if(qChecksum(comBuffer, comBuffer_len-2) == checkSum)
    {

        //protocolAnalysis解析出cmd，head,cmd,info

    }
    else
    {
        qDebug()<< "校验位不正确";
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
            else if(xml.name()=="updatetime")
            {
                today.updatetime = xml.readElementText();
            }
            else if(xml.name()=="wendu")
            {
                today.wendu = xml.readElementText();
            }
            else if(xml.name()=="fengli")
            {
                today.fengli = xml.readElementText();
            }
            else if(xml.name()=="shidu")
            {
                today.shidu = xml.readElementText();
            }
            else if(xml.name()=="fengxiang")
            {
                today.fengxiang = xml.readElementText();
            }
            else if(xml.name()=="sunrise_1")
            {
                today.sunrise = xml.readElementText();
            }
            else if(xml.name() == "type")
            {
                today.type = xml.readElementText();
           }
            else if(xml.name()=="sunset_1")
            {
                today.sunset = xml.readElementText();
                xml.clear();
               ui->label->setText(tr("%1").arg(today.city));
               ui->label_2->setText(tr("%1℃").arg(today.wendu));
               //ui->forecast_0_type->setPixmap(QPixmap(":/images/多云"));
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

