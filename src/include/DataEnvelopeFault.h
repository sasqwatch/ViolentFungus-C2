#ifndef DATAENVELOPEFAULT_H
#define DATAENVELOPEFAULT_H

#include <QObject>
#include <QDebug>


/*
 * Is included as part of DataEnvelope
 */
class DataEnvelopeFault : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelopeFault(QObject *parent = nullptr);

signals:

};

#endif // DATAENVELOPEFAULT_H
