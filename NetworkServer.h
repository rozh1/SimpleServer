#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QObject>
#include <QUdpSocket>
#include "ipacket.h"
#include "ImageDataRequestPacket.h"
#include "ImageDataResponcePacket.h"
#include "ImageInfoRequestPacket.h"
#include "ImageInfoResponcePacket.h"
#include "ControlRequestPacket.h"
#include "StatusPacket.h"
#include "AimInfoRequestPacket.h"
#include "AimInfoResponcePacket.h"

class NetworkServer : public QObject
{
    Q_OBJECT
public:
    explicit NetworkServer(quint16 port, QObject *parent = nullptr);
    void Send(QByteArray data, QHostAddress host, quint16 port);
    void Send(QObject *object, QHostAddress host, quint16 port);

private:
    QUdpSocket *socket;

signals:
    void PacketReceived(QByteArray data, QHostAddress sender, quint16 senderPort);
    void ImageDataRequestPacketRecieved(ImageDataRequestPacket *packet, QHostAddress sender, quint16 senderPort);
    void ImageDataResponcePacketRecieved(ImageDataResponcePacket *packet, QHostAddress sender, quint16 senderPort);
    void ImageInfoRequestPacketRecieved(ImageInfoRequestPacket *packet, QHostAddress sender, quint16 senderPort);
    void ImageInfoResponcePacketRecieved(ImageInfoResponcePacket *packet, QHostAddress sender, quint16 senderPort);
    void ControlPacketRecieved(ControlRequestPacket *packet, QHostAddress sender, quint16 senderPort);
    void StatusPacketRecieved(StatusPacket *packet, QHostAddress sender, quint16 senderPort);
    void AimInfoRequestPacketRecieved(AimInfoRequestPacket *packet, QHostAddress sender, quint16 senderPort);
    void AimInfoResponcePacketRecieved(AimInfoResponcePacket *packet, QHostAddress sender, quint16 senderPort);

private slots:
    void ReadyRead();
    void PacketReceivedHandler(QByteArray data, QHostAddress sender, quint16 senderPort);
};

#endif // NETWORKSERVER_H
