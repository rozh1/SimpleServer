#ifndef IMAGEINFORESPONCEPACKET_H
#define IMAGEINFORESPONCEPACKET_H

#include <QObject>
#include "ipacket.h"

class ImageInfoResponcePacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    ImageInfoResponcePacket();
    ~ImageInfoResponcePacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint8 DataId;          //Идентификатор данных
    quint16 Width;          //Ширина фотографии
    quint16 Height;         //Высота фотографии
    quint32 DataSize;       //Общий размер данных
    quint16 DataBlockCount; //Количество блоков данных (если не 0, то расчитается от DataBlockSize)

    quint16 DataBlockSize;  //Размер блока данных (SZ)

private:
};

#endif // IMAGEINFORESPONCEPACKET_H
