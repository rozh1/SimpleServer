#ifndef IMAGEDATAREQUESTPACKET_H
#define IMAGEDATAREQUESTPACKET_H

#include <QObject>
#include "ipacket.h"

class ImageDataRequestPacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    ImageDataRequestPacket();
    ~ImageDataRequestPacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;    //Идентификатор пакета
    quint8 PhotoId;    //Идентификатор фотографии
    quint16 DataBlockId;    //Номер блока данных

private:
};

#endif // IMAGEDATAREQUESTPACKET_H
