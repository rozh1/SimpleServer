#include "StatusPacket.h"
#include <qdatastream.h>

StatusPacket::StatusPacket()
{
    PacketId = 0x51;
}

StatusPacket::~StatusPacket()
{

}

QVector<QByteArray> StatusPacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << Camera << Resolution << FPS << OpticalZoom << DigitalZoom << CameraMode;

    vector.append(ba);
    return vector;
}

void StatusPacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> Camera >> Resolution >> FPS >> OpticalZoom >> DigitalZoom >> CameraMode;
}

