#ifndef AIMINFOREQUESTPACKET_H
#define AIMINFOREQUESTPACKET_H

#include <QObject>
#include "ipacket.h"

class AimInfoRequestPacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    AimInfoRequestPacket();
    ~AimInfoRequestPacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint16 FirstAimNumber; //Номер первой цели
    quint8 AimCount;        //Количество целей

private:
};

#endif // AIMINFOREQUESTPACKET_H
