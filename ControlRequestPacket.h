#ifndef CONTROLREQUESTPACKET_H
#define CONTROLREQUESTPACKET_H

#include <QObject>
#include "ipacket.h"

class ControlRequestPacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    ControlRequestPacket();
    ~ControlRequestPacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;        //Идентификатор пакета
    quint8 SetCamera;       //Выбор активной камеры
    quint8 SetResolution;   //Разрешающая способность видео
    quint8 SetFPS;          //Частота смены кадров
    quint8 SetOpticalZoom;  //Оптическое увеличение
    quint8 SetDigitalZoom;  //Цифровое увеличение

private:
};

#endif // CONTROLREQUESTPACKET_H
