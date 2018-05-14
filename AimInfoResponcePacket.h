#ifndef AIMINFORESPONCEPACKET_H
#define AIMINFORESPONCEPACKET_H

#include <QObject>
#include "ipacket.h"

class AimInfoResponcePacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    AimInfoResponcePacket();
    ~AimInfoResponcePacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint16 FirstAimNumber; //Номер первой цели в пачке
    quint8 AimCount;        //Количество целей

    struct AimData {
        quint16 Type;       //Тип цели
        quint32 Latitude;   //Широта цели
        quint32 Longitude;  //Долгота цели
        quint16 Altitude;   //Высота цели
        quint32 Time;       //Время полётное обнаружения цели
    };

    QVector<AimData> Aims;  //цели

private:
};

#endif // AIMINFORESPONCEPACKET_H
