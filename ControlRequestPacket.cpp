#include "ControlRequestPacket.h"
#include <qdatastream.h>

ControlRequestPacket::ControlRequestPacket()
{
    PacketId = 0x50;
}

ControlRequestPacket::~ControlRequestPacket()
{

}

QVector<QByteArray> ControlRequestPacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << SetCamera << SetResolution << SetFPS << SetOpticalZoom << SetDigitalZoom;

    vector.append(ba);
    return vector;
}

void ControlRequestPacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> SetCamera >> SetResolution >> SetFPS >> SetOpticalZoom >> SetDigitalZoom;
}

