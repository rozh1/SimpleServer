#ifndef PACKETPROCESSOR_H
#define PACKETPROCESSOR_H

#include <QObject>
#include <QHostAddress>
#include "ImageDataRequestPacket.h"
#include "NetworkServer.h"

class PacketProcessor : public QObject
{
    Q_OBJECT

public:
    PacketProcessor(NetworkServer *networkServer);

private:
    NetworkServer *_networkServer;

signals:

public slots:
    //Получен запрос картинки
    void ImageDataRequestPacketRecieved(ImageDataRequestPacket *packet, QHostAddress sender, quint16 senderPort);
};

#endif // PACKETPROCESSOR_H
