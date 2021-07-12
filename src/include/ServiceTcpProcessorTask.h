#ifndef SERVICETCPPROCESSORTASK_H
#define SERVICETCPPROCESSORTASK_H

#include <QDebug>
#include <QObject>
#include <QRunnable>

#include "DataRequestProcessor.h"
#include "DataTransmogrifier.h"

class ServiceTcpProcessorTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ServiceTcpProcessorTask();
    void setRequestData(QByteArray requestData);

signals:
    // notify to the main thread when we're done
    void socketDataProcessed(QByteArray);

protected:
    void run();
    QByteArray requestData;

private:

};

#endif // SERVICETCPPROCESSORTASK_H
