#include "DataEnvelope.h"

DataEnvelope::DataEnvelope(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataEnvelope::DataEnvelope";
    qDebug() << "Leaving DataEnvelope::DataEnvelope";
}

void DataEnvelope::consumeRawData(QByteArray data)
{
    qDebug() << "Entered DataEnvelope::consumeRawData";
    qDebug() << "rawData = " << data;
    this->setData(data);
    qDebug() << "Leaving DataEnvelope::consumeRawData";

}

QByteArray DataEnvelope::getData()
{
    qDebug() << "Entered DataEnvelope::getRawData";
    qDebug() << "Leaving DataEnvelope::getRawData";
    return this->data;
}

void DataEnvelope::setData(QByteArray newData)
{
    qDebug() << "Entered DataEnvelope::setRawData";
    qDebug() << "Leaving DataEnvelope::setRawData";
    this->data = newData;
}
