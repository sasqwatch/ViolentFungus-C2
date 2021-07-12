#ifndef SERVICETCPPROCESSOR_H
#define SERVICETCPPROCESSOR_H

#include <QObject>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>

#include "ServiceTcpProcessorTask.h"


class ServiceTcpProcessor : public QObject
{
    Q_OBJECT

public:
    explicit ServiceTcpProcessor(QObject *parent = nullptr);

    void setSocket(int);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();

    void socketDataProcessed(QByteArray);

private:
    QTcpSocket *socket;

};

#endif // SERVICETCPPROCESSOR_H
