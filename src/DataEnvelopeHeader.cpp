#include "DataEnvelopeHeader.h"

DataEnvelopeHeader::DataEnvelopeHeader(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataEnvelopeHeader::DataEnvelopeHeader";
    qDebug() << "Leaving DataEnvelopeHeader::DataEnvelopeHeader";
}

const QMap<QString, QByteArray> &DataEnvelopeHeader::getHeaders() const
{
    qDebug() << "Entered DataEnvelopeHeader::getHeaders";
    qDebug() << "Leaving DataEnvelopeHeader::getHeaders";
    return this->headers;
}


QList<QString> DataEnvelopeHeader::getKeysByValue(QByteArray value)
{
    qDebug() << "Entered DataEnvelopeHeader::getKeysByValue";
    qDebug() << "value = " << value;
    qDebug() << "Leaving DataEnvelopeHeader::getKeysByValue";
    return this->headers.keys(value);
}
QByteArray DataEnvelopeHeader::getValueByKey(QString key)
{
    qDebug() << "Entered DataEnvelopeHeader::getValueByKey";
    qDebug() << "key = " << key;
    qDebug() << "Leaving DataEnvelopeHeader::getValueByKey";
    return this->headers.value(key);
}

void DataEnvelopeHeader::add(QString key, QByteArray value)
{
    qDebug() << "Entered DataEnvelopeHeader::addHeader";
    qDebug() << "key = " << key;
    qDebug() << "value = " << value;
    qDebug() << "Leaving DataEnvelopeHeader::addHeader";
    this->headers.insert(key, value);
}

void DataEnvelopeHeader::remove(QString key)
{
    qDebug() << "Entered DataEnvelopeHeader::removeHeaderByKey";
    qDebug() << "key = " << key;
    this->headers.remove(key);
    qDebug() << "Leaving DataEnvelopeHeader::removeHeaderByKey";
}
