#include "ImageInfoRequestPacket.h"
#include <qdatastream.h>

ImageInfoRequestPacket::ImageInfoRequestPacket()
{
    PacketId = 0xC0;
}

ImageInfoRequestPacket::~ImageInfoRequestPacket()
{

}

QVector<QByteArray> ImageInfoRequestPacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << PhotoType << AimNumber << DataBlockSize << PhotoId;

    vector.append(ba);
    return vector;
}

void ImageInfoRequestPacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> PhotoType >> AimNumber >> DataBlockSize >> PhotoId;
}

