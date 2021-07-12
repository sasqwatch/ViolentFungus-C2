#include "DataResponseProcessor.h"

DataResponseProcessor::DataResponseProcessor(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataResponseProcessor::DataResponseProcessor";
    qDebug() << "Leaving DataResponseProcessor::DataResponseProcessor";
}

const QByteArray &DataResponseProcessor::getData() const
{
    qDebug() << "Entered DataResponseProcessor::getData";
    qDebug() << "Leaving DataResponseProcessor::getData";
    return this->data;
}

void DataResponseProcessor::setData(const QByteArray &newData)
{
    qDebug() << "Entered DataResponseProcessor::setData";
    qDebug() << "newData = " << newData;
    qDebug() << "Leaving DataResponseProcessor::setData";
    this->data = newData;
}

/*
 *  Note: the data passed in should already be decoded from DataTransmogrifier
 */
QByteArray DataResponseProcessor::createResponseFromRequest(QByteArray requestData)
{
    qDebug() << "Entered DataResponseProcessor::createResponseFromRequest";
    qDebug() << "requestData = " << requestData;
    QByteArray responseData;

    // Actually handle the request somehow
    responseData = requestData;

    qDebug() << "Leaving DataResponseProcessor::createResponseFromRequest";
    return responseData;
}
