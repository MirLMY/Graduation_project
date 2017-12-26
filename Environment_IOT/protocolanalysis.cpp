#include "protocolanalysis.h"

ProtocolAnalysis::ProtocolAnalysis(QByteArray buffer,int len, QObject *parent) : QObject(parent)
{
    protocolBuffer = buffer;
    lenth = len;
}

ProtocolAnalysis::~ProtocolAnalysis()
{

}

QByteArray ProtocolAnalysis::bufferToJson()
{
    quint8 protocolHead = protocolBuffer[0];
    quint8 protocolCmd = protocolBuffer[1];
    quint8 protocolIp = protocolBuffer[2];

    QJsonObject json;
    json.insert("head",protocolHead);
    json.insert("cmd",protocolCmd);
    json.insert("ip",protocolIp);

    QJsonDocument document;
    document.setObject(json);
    QByteArray sendJsonBuffer = document.toJson(QJsonDocument::Compact);
    qDebug()<<sendJsonBuffer;
    return sendJsonBuffer;

}
