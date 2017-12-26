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

signals:
private:
    QByteArray protocolBuffer;
    int lenth;

public slots:
    QByteArray bufferToJson();
};

#endif // PROTOCOLANALYSIS_H
