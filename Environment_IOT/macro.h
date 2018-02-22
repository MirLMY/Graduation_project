#ifndef PRASE_PROTOCOLANALYSIS_H
#define PRASE_PROTOCOLANALYSIS_H

#define HEAD                0x12

#define CMD_PERIOD_INFO     0x01
#define CMD_GET_INFO        0x02
#define CMD_SWITCH_ON       0x03
#define CMD_SWITCH_OFF      0x04

#define IP_WIND             0x05
#define IP_THERMOMETER      0x06//温度
#define IP_HYGROMETER       0x07//湿度
#define IP_INFRARED_BODY    0x08//人体红外
#define IP_PM2_5            0x09
#define IP_FIRE             0x0a
#define IP_LIGHT            0x0b

#define BAUD_2400   0
#define BAUD_4800   1
#define BAUD_9600   2
#define BAUD_115200 3

#define NONE        0
#define ODD         1
#define EVEN        2
#define MARK        3
#define SPACE       4

#define ONESTOP                 0
#define ONEANDHALFStOP          1
#define TWOSTOP                 2

#endif // PRASE_PROTOCOLANALYSIS_H

