#ifndef STATUSPACKET_H
#define STATUSPACKET_H

#include <QObject>
#include "ipacket.h"

class StatusPacket : public QObject, public IPacket
{
    Q_OBJECT
    Q_INTERFACES(IPacket)

public:
    StatusPacket();
    ~StatusPacket();
    QVector<QByteArray> GetDatagrams();
    void SetDatagram(QByteArray data);

    quint8 PacketId;     //Идентификатор пакета
    quint8 Camera;       //Выбор активной камеры
    quint8 Resolution;   //Разрешающая способность видео
    quint8 FPS;          //Частота смены кадров
    quint8 OpticalZoom;  //Оптическое увеличение
    quint8 DigitalZoom;  //Цифровое увеличение
    quint8 CameraMode;   //Поддерживаемые режимы работы активной камеры

private:
};

#endif // STATUSPACKET_H
