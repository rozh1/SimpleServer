#include "ImageInfoResponcePacket.h"
#include <qdatastream.h>

ImageInfoResponcePacket::ImageInfoResponcePacket()
{
    PacketId = 0xC1;
    DataBlockCount = 0;
}

ImageInfoResponcePacket::~ImageInfoResponcePacket()
{

}

QVector<QByteArray> ImageInfoResponcePacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    if (DataBlockCount == 0)
    {
        DataBlockCount = DataSize / DataBlockSize + (DataSize % DataBlockSize == 0 ? 0 : 1);
    }

    QByteArray ba;
    QDataStream out( &ba, QIODevice::WriteOnly );
    out.setByteOrder(QDataStream::BigEndian);
    out << PacketId << DataId << Width << Height << DataSize << DataBlockCount;

    vector.append(ba);

    return vector;
}

void ImageInfoResponcePacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> DataId >> Width >> Height >> DataSize >> DataBlockCount;
}


