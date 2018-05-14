#include "ImageDataResponcePacket.h"
#include <qdatastream.h>

ImageDataResponcePacket::ImageDataResponcePacket()
{
    PacketId = 0xD1;
}

ImageDataResponcePacket::~ImageDataResponcePacket()
{

}

QVector<QByteArray> ImageDataResponcePacket::GetDatagrams()
{
    QVector<QByteArray> vector;
    auto iterations = Data.size() / DataBlockSize;

    for(int i=0; i<iterations; i++)
    {
        auto lastPos = i*DataBlockSize;

        QByteArray ba;
        QDataStream out( &ba, QIODevice::WriteOnly );
        out.setByteOrder(QDataStream::BigEndian);
        out << PacketId << PhotoId << DataBlockId << Data.mid(lastPos,DataBlockSize);

        vector.append(ba);
    }

    if (Data.size() % DataBlockSize != 0)
    {
        auto len = Data.size() - iterations * DataBlockSize;
        auto lastPos = iterations*DataBlockSize;
        QByteArray ba;
        QDataStream out( &ba, QIODevice::WriteOnly );
        out.setByteOrder(QDataStream::BigEndian);
        out << PacketId << PhotoId << DataBlockId << Data.mid(lastPos,len);

        vector.append(ba);
    }

    //for(int i=Data.begin(), byteCount = 0, lastPos = 0; i != Data.end(); i++, byteCount++)
    //{
    //    if (byteCount == DataBlockSize)
    //    {
    //        byteCount = 0;
    //        lastPos = i;
    //
    //        QByteArray ba;
    //        QDataStream out( &ba, QIODevice::WriteOnly );
    //        out.setByteOrder(QDataStream::BigEndian);
    //        out << PacketId << PhotoId << DataBlockId << Data.mid(lastPos,DataBlockSize);
    //
    //        vector.append(ba);
    //    }
    //}

    return vector;
}

void ImageDataResponcePacket::SetDatagram(QByteArray data)
{
    QDataStream in( &data, QIODevice::ReadOnly );
    QByteArray inData;
    in.setByteOrder(QDataStream::BigEndian);
    in >> PacketId >> PhotoId >> DataBlockId >> inData;
    Data.append(inData);
    if (DataBlockSize < inData.size()) DataBlockSize = inData.size();
}


