#include "AimInfoRequestPacket.h"
#include <qdatastream.h>

AimInfoRequestPacket::AimInfoRequestPacket()
{
    PacketId = 0x70;
}

AimInfoRequestPacket::~AimInfoRequestPacket()
{

}

QVector<QByteArray> AimInfoRequestPacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << FirstAimNumber << AimCount;

    vector.append(ba);
    return vector;
}

void AimInfoRequestPacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> FirstAimNumber >> AimCount;
}

