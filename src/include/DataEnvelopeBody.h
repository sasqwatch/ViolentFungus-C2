#ifndef DATAENVELOPEBODY_H
#define DATAENVELOPEBODY_H

#include <QObject>
#include <QDebug>


/*
 * Is included as part of DataEnvelope
 */
class DataEnvelopeBody : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelopeBody(QObject *parent = nullptr);

signals:


};

#endif // DATAENVELOPEBODY_H
