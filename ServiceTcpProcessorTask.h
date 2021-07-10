#ifndef SERVICETCPPROCESSORTASK_H
#define SERVICETCPPROCESSORTASK_H

#include <QObject>
#include <QRunnable>

class ServiceTcpProcessorTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    ServiceTcpProcessorTask();
    void setSocketData(QByteArray);

signals:
    // notify to the main thread when we're done
    void socketDataProcessed(QByteArray);

protected:
    void run();

private:
    QByteArray socketData;
};

#endif // SERVICETCPPROCESSORTASK_H
