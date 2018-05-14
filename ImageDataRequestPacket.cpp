#include "ImageDataRequestPacket.h"
#include <qdatastream.h>

ImageDataRequestPacket::ImageDataRequestPacket()
{
    PacketId = 0xD0;
}

ImageDataRequestPacket::~ImageDataRequestPacket()
{

}

QVector<QByteArray> ImageDataRequestPacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << PhotoId << DataBlockId;

    vector.append(ba);
    return vector;
}

void ImageDataRequestPacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> PhotoId >> DataBlockId;
}

