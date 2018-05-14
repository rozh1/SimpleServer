#include "AimInfoResponcePacket.h"
#include <qdatastream.h>

AimInfoResponcePacket::AimInfoResponcePacket()
{
    PacketId = 0x70;
}

AimInfoResponcePacket::~AimInfoResponcePacket()
{

}

QVector<QByteArray> AimInfoResponcePacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << FirstAimNumber << AimCount;
    foreach (AimData aim, Aims) {
        out << aim.Type << aim.Latitude << aim.Longitude << aim.Altitude << aim.Time;
    }

    vector.append(ba);
    return vector;
}

void AimInfoResponcePacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> FirstAimNumber >> AimCount;
    while(in.status() == QDataStream::Ok)
    {
        AimData aim;
        in >> aim.Type >> aim.Latitude >> aim.Longitude >> aim.Altitude >> aim.Time;
        Aims.append(aim);
    }
}

