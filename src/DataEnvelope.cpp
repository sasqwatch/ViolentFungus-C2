#include "DataEnvelope.h"

DataEnvelope::DataEnvelope(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataEnvelope::DataEnvelope";
    qDebug() << "Leaving DataEnvelope::DataEnvelope";
}

void DataEnvelope::consumeRawData(QByteArray rawData)
{
    qDebug() << "Entered DataEnvelope::consumeRawData";
    qDebug() << "rawData = " << rawData;
    this->setRawData(rawData);
    qDebug() << "Leaving DataEnvelope::consumeRawData";

}

QByteArray DataEnvelope::toBytes()
{
    qDebug() << "Entered DataEnvelope::toBytes";
    qDebug() << "Leaving DataEnvelope::toBytes";

    return this->rawData;


    QByteArray data;
    return data;
}

QString DataEnvelope::toString()
{
    qDebug() << "Entered DataEnvelope::toString";
    qDebug() << "Leaving DataEnvelope::toString";
    return QString::fromUtf8(this->rawData);


    QString data;
    return data;
}

const QByteArray &DataEnvelope::getRawData() const
{
    qDebug() << "Entered DataEnvelope::getRawData";
    qDebug() << "Leaving DataEnvelope::getRawData";
    return this->rawData;
}

void DataEnvelope::setRawData(const QByteArray &newRawData)
{
    qDebug() << "Entered DataEnvelope::setRawData";
    qDebug() << "Leaving DataEnvelope::setRawData";
    this->rawData = newRawData;
}
