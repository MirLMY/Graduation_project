#include "protocolanalysis.h"

ProtocolAnalysis::ProtocolAnalysis(QByteArray buffer,int len, QObject *parent) : QObject(parent)
{
    protocolBuffer = buffer;
    lenth = len;
    infoLen = len-5;
    protocolInfo = new quint8(PROTOCOLINFO_SIZE);
    memset(protocolInfo,0,PROTOCOLINFO_SIZE);
}

ProtocolAnalysis::~ProtocolAnalysis()
{
    delete protocolInfo;
}

quint8 ProtocolAnalysis::bufferToHead()
{

    return protocolBuffer[0];

}

quint8 ProtocolAnalysis::bufferToCmd()
{

    return protocolBuffer[1];

}
quint8 ProtocolAnalysis::bufferToIp()
{

    return protocolBuffer[2];

}
quint8* ProtocolAnalysis::bufferToInfo()
{

    for(int i = 3;i < lenth;i++)
    {
        protocolInfo[i-3] = protocolBuffer[i];
    }
    return protocolInfo;

}
