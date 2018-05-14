#ifndef IMAGEINFOREQUESTPACKET_H
#define IMAGEINFOREQUESTPACKET_H

#include <QObject>
#include "ipacket.h"

class ImageInfoRequestPacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    ImageInfoRequestPacket();
    ~ImageInfoRequestPacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint8 PhotoType;       //Тип фотографии
    quint16 AimNumber;      //Номер цели
    quint16 DataBlockSize;  //Размер блока данных
    quint8 PhotoId;         //Идентификатор фотографии


private:
};

#endif // IMAGEINFOREQUESTPACKET_H
