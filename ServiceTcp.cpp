#include "ServiceTcp.h"

ServiceTcp::ServiceTcp(QObject *parent) :
    QTcpServer(parent)
{
}

void ServiceTcp::startService(quint16 port)
{
    if( listen(QHostAddress::AnyIPv4, port) )
    {
        //qDebug() << "Server: started on port " << port;
    }
    else
    {
        qFatal("Service TCP unable to start. Check the port number.");
    }
}

void ServiceTcp::incomingConnection(qintptr sock)
{
    qDebug() << "ServiceTcp::incomingConnection fired with sock #" << sock
             << ", handing off to ServiceTcpProcessor";
    ServiceTcpProcessor *client = new ServiceTcpProcessor(this);
    client->setSocket(sock);

}


