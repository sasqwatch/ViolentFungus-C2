#include "ServiceTcpProcessor.h"

ServiceTcpProcessor::ServiceTcpProcessor(QObject *parent) :
    QObject(parent)
{
}


void ServiceTcpProcessor::setSocket(int sock)
{
    // make a new socket
    socket = new QTcpSocket(this);

    qDebug() << "A new socket created";

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(sock);

    qDebug() << " Client connected at " << sock;
}

// asynchronous - runs separately from the thread we created
void ServiceTcpProcessor::connected()
{
    qDebug() << "Client connected event";
}

// asynchronous
void ServiceTcpProcessor::disconnected()
{
    qDebug() << "Client disconnected";
}

// Our main thread of execution
// This happening via main thread
// Our code running in our thread not in Qthread
// That's why we're getting the thread from the pool

void ServiceTcpProcessor::readyRead()
{
    qDebug() << "ServiceTcpProcessor::readyRead()";
    QByteArray socketData = socket->readAll();
    qDebug() << "Got this socket data: " << socketData;

    // Time consumer
    ServiceTcpProcessorTask *serviceTcpProcessorTask = new ServiceTcpProcessorTask();
    serviceTcpProcessorTask->setAutoDelete(true);
    serviceTcpProcessorTask->setRequestData(socketData);
    connect(serviceTcpProcessorTask, SIGNAL(socketDataProcessed(QByteArray)), // ProcessorTask
            this, SLOT(socketDataProcessed(QByteArray)),            // Processor
            Qt::QueuedConnection);

    qDebug() << "Starting a new task using a thread from the QThreadPool";
    QThreadPool::globalInstance()->start(serviceTcpProcessorTask);

}

// After a task performed a time consuming task.
// We grab the result here, and send it to client
void ServiceTcpProcessor::socketDataProcessed(QByteArray socketData)
{
    qDebug() << "ServiceTcpProcessor::socketDataProcessed writing socketData to socket";
    socket->write(socketData);
}
