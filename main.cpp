#include <QCoreApplication>
#include <NetworkServer.h>
#include <ImageDataRequestPacket.h>
#include <packetprocessor.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NetworkServer server(1234);
    PacketProcessor packetProcessor(&server);
    QObject::connect(&server,&NetworkServer::ImageDataRequestPacketRecieved,&packetProcessor,&PacketProcessor::ImageDataRequestPacketRecieved);

    //QByteArray data;
    //data.append("qwer");
    //server.Send(data, QHostAddress::LocalHost, 1234);
    ImageDataRequestPacket pb;
    pb.PhotoId = 12;
    pb.DataBlockId = 1;
    server.Send(&pb, QHostAddress::LocalHost, 1234);

    return a.exec();
}
