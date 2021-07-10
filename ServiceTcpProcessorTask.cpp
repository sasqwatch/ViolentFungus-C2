#include "ServiceTcpProcessorTask.h"
#include <QDebug>


ServiceTcpProcessorTask::ServiceTcpProcessorTask()
{
    qDebug() << "ServiceTcpProcessorTask()";
}

void ServiceTcpProcessorTask::setSocketData(QByteArray socketData) {
    this->socketData = socketData;
}

void ServiceTcpProcessorTask::run()
{
    qDebug() << "ServiceTcpProcessorTask::run() started";

    qDebug() << "socketData = " << this->socketData;

    qDebug() << "ServiceTcpProcessorTask::run() ended";

    qDebug() << "emit socketDataProcessed(this->socketData) now";
    emit socketDataProcessed(this->socketData);
}
