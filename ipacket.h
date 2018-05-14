#ifndef IPACKET_H
#define IPACKET_H

#include <QVector>
#include <QByteArray>

class IPacket
{

public:
    virtual QVector<QByteArray> GetDatagrams() = 0;
    virtual void SetDatagram(QByteArray data) = 0;
};

Q_DECLARE_INTERFACE(IPacket, "IPacketId")

#endif // IPACKET_H
