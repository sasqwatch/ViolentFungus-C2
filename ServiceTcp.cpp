#include "ServiceTcp.h"


QString ServiceTcp::NAME = "Raw TCP Service";


ServiceTcp::ServiceTcp(QObject *parent) :
    QTcpServer(parent)
{
}

void ServiceTcp::startService(quint16 port)
{
    if( listen(QHostAddress::AnyIPv4, port) )
    {
    }
    else
    {
        QTextStream out(stdout);
        qCritical().nospace().noquote() << ServiceTcp::NAME + ": unable to start: " << errorString();
    }
}

void ServiceTcp::incomingConnection(qintptr sock)
{
    qDebug() << "ServiceTcp::incomingConnection fired with sock #" << sock
             << ", handing off to ServiceTcpProcessor";
    ServiceTcpProcessor *client = new ServiceTcpProcessor(this);
    client->setSocket(sock);

}


