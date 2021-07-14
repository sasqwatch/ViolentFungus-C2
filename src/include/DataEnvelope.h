#ifndef DATAENVELOPE_H
#define DATAENVELOPE_H

#include <QObject>
#include <QDebug>

#include "DataEnvelopeBody.h"
#include "DataEnvelopeFault.h"
#include "DataEnvelopeHeader.h"


/*
 * DataEnvelope is made up of a Header (required), Body (optional), and Fault (optional) components.
 *
 * It is what is transferred back and forth between all server(s) and agents/clients. I modeled it after
 * SOAP, but without the verbosity and complexity (hopefully).
 *
 * Its raw bytes will be what is transferred, chunking handled by DataEnvelopeChunker, even if only one
 * chunk.
 */

class DataEnvelope : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelope(QObject *parent = nullptr);

    // Consume a raw data QByteArray and populate the header, body, and fault objects.
    void consumeRawData(QByteArray rawData);

    QByteArray getData();
    void setData(QByteArray data);

    // Just make them public and work on them directly, no need for extra abstraction
    DataEnvelopeHeader dataEnvelopeHeader;
    DataEnvelopeBody dataEnvelopeBody;
    DataEnvelopeFault dataEnvelopeFault;

signals:

private:
    QByteArray data;

};

#endif // DATAENVELOPE_H
