#include "NetworkServer.h"
#include <QDebug>

NetworkServer::NetworkServer(quint16 port, QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);

    socket->bind(port);
    qDebug() << "Start Listen on port " << port;

    connect(socket,SIGNAL(readyRead()),this,SLOT(ReadyRead()));
    connect(this,SIGNAL(PacketReceived(QByteArray,QHostAddress,quint16)),this, SLOT(PacketReceivedHandler(QByteArray,QHostAddress,quint16)));
}

void NetworkServer::Send(QByteArray data, QHostAddress host, quint16 port)
{
    qDebug() << "Send " << data.size() << " bytes to " << host.toString() << ":" << port;
    socket->writeDatagram(data,host,port);
}

void NetworkServer::Send(QObject *object, QHostAddress host, quint16 port)
{
    IPacket* packet = qobject_cast<IPacket*>(object);
    if (packet) {
        auto data = packet->GetDatagrams();
        foreach (auto datagram, data) {
            Send(datagram, host, port);
        }
    } else {
        qErrnoWarning("Неправильный тип пакета");
    }
}

void NetworkServer::ReadyRead()
{
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);

    emit PacketReceived(Buffer, sender, senderPort);
}

void NetworkServer::PacketReceivedHandler(QByteArray data, QHostAddress sender, quint16 senderPort)
{
    if (data.size() > 0)
    {
        quint8 firstbyte = data[0];
        qDebug() << "Получен пакет " << QString().number(firstbyte,16).prepend("0x");
        switch (firstbyte) {
            case 0xD0:
            {
                auto imageDataRequestPacket = new ImageDataRequestPacket();
                imageDataRequestPacket->SetDatagram(data);
                emit ImageDataRequestPacketRecieved(imageDataRequestPacket, sender, senderPort);
                break;
            }
            case 0xD1:
            {
                auto imageDataResponcePacket = new ImageDataResponcePacket();
                imageDataResponcePacket->SetDatagram(data);
                emit ImageDataResponcePacketRecieved(imageDataResponcePacket, sender, senderPort);
                break;
            }
            case 0xC0:
            {
                auto imageInfoRequestPacket = new ImageInfoRequestPacket();
                imageInfoRequestPacket->SetDatagram(data);
                emit ImageInfoRequestPacketRecieved(imageInfoRequestPacket, sender, senderPort);
                break;
            }
            case 0xC1:
            {
                auto imageInfoResponcePacket = new ImageInfoResponcePacket();
                imageInfoResponcePacket->SetDatagram(data);
                emit ImageInfoResponcePacketRecieved(imageInfoResponcePacket, sender, senderPort);
                break;
            }
            case 0x50:
            {
                auto controlRequestPacket = new ControlRequestPacket();
                controlRequestPacket->SetDatagram(data);
                emit ControlPacketRecieved(controlRequestPacket, sender, senderPort);
                break;
            }
            case 0x51:
            {
                auto statusPacket = new StatusPacket();
                statusPacket->SetDatagram(data);
                emit StatusPacketRecieved(statusPacket, sender, senderPort);
                break;
            }
            case 0x70:
            {
                auto aimInfoRequestPacket = new AimInfoRequestPacket();
                aimInfoRequestPacket->SetDatagram(data);
                emit AimInfoRequestPacketRecieved(aimInfoRequestPacket, sender, senderPort);
                break;
            }
            case 0x71:
            {
                auto aimInfoResponcePacket = new AimInfoResponcePacket();
                aimInfoResponcePacket->SetDatagram(data);
                emit AimInfoResponcePacketRecieved(aimInfoResponcePacket, sender, senderPort);
                break;
            }
            default:
            {
                qWarning() << "Неизвестный тип пакета " << QString().number(firstbyte,16).prepend("0x");
                break;
            }
        }
    }
    else
    {
        qWarning() << "Получен пустой пакет";
    }
}
