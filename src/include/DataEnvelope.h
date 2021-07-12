#ifndef DATAENVELOPE_H
#define DATAENVELOPE_H

#include <QObject>
#include <QDebug>

#include "DataEnvelopeBody.h"
#include "DataEnvelopeFault.h"
#include "DataEnvelopeHeader.h"


class DataEnvelope : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelope(QObject *parent = nullptr);
    void consumeRawData(QByteArray rawData);
    QByteArray toBytes();
    QString toString();

    const QByteArray &getRawData() const;
    void setRawData(const QByteArray &newRawData);

signals:

private:
    DataEnvelopeHeader dataEnvelopeHeader;
    DataEnvelopeBody dataEnvelopeBody;
    DataEnvelopeFault dataEnvelopeFault;
    QByteArray rawData;

};

#endif // DATAENVELOPE_H
