#ifndef PROTOCOLANALYSIS_H
#define PROTOCOLANALYSIS_H

#include <QObject>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

#define PROTOCOLINFO_SIZE 20

class ProtocolAnalysis : public QObject
{
    Q_OBJECT
public:
    explicit ProtocolAnalysis(QByteArray buffer,int len,QObject *parent = 0);
    ~ProtocolAnalysis();
    quint8 *protocolInfo;

signals:
private:
    QByteArray protocolBuffer;
    int lenth;

public slots:
    quint8 bufferToHead();
    quint8 bufferToCmd();
    quint8 bufferToIp();
    quint8 *bufferToInfo();
};

#endif // PROTOCOLANALYSIS_H
