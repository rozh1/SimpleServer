#include "packetprocessor.h"
#include <QObject>
#include <QHostAddress>
#include "ImageDataRequestPacket.h"
#include "ImageDataResponcePacket.h"

PacketProcessor::PacketProcessor(NetworkServer *networkServer)
{
    _networkServer = networkServer;
}


void PacketProcessor::ImageDataRequestPacketRecieved(ImageDataRequestPacket *packet, QHostAddress sender, quint16 senderPort)
{
    ImageDataResponcePacket imageDataResponcePacket;
    imageDataResponcePacket.DataBlockId = packet->DataBlockId;
    imageDataResponcePacket.PhotoId = packet->PhotoId;
    imageDataResponcePacket.DataBlockSize = 5;
    QByteArray ba;
    ba.append("Hello WORLD!!!");
    imageDataResponcePacket.Data = ba;

    _networkServer->Send(&imageDataResponcePacket, sender, senderPort);
}
