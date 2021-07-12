#ifndef DATAENVELOPEHEADER_H
#define DATAENVELOPEHEADER_H

#include <QObject>
#include <QDebug>

/*
 * Is included as part of DataEnvelope
 */
class DataEnvelopeHeader : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelopeHeader(QObject *parent = nullptr);

signals:

};

#endif // DATAENVELOPEHEADER_H
