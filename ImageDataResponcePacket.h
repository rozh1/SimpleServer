#ifndef IMAGEDATARERESPONCETPACKET_H
#define IMAGEDATARERESPONCETPACKET_H

#include <QObject>
#include "ipacket.h"

class ImageDataResponcePacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    ImageDataResponcePacket();
    ~ImageDataResponcePacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint8 PhotoId;         //Идентификатор фотографии
    quint16 DataBlockId;    //Номер блока данных
    QByteArray Data;        //Байты блока данных

    quint16 DataBlockSize;  //Размер блока данных (SZ)

private:
};

#endif // IMAGEDATAREQUESTPACKET_H
