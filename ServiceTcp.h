#ifndef SERVICETCP_H
#define SERVICETCP_H

#include <QTcpServer>

#include "ServiceTcpProcessor.h"


class ServiceTcp : public QTcpServer
{
    Q_OBJECT

public:
    explicit ServiceTcp(QObject *parent = 0);
    static QString NAME;
    void startService(quint16 port);

protected:
    void incomingConnection(qintptr sock);

private:
    int port;

signals:

public slots:
};

#endif // SERVICETCP_H
