#include "DataRequestProcessor.h"

DataRequestProcessor::DataRequestProcessor(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataRequestProcessor::DataRequestProcessor";
    qDebug() << "Leaving DataRequestProcessor::DataRequestProcessor";
}

const QByteArray &DataRequestProcessor::getData() const
{
    qDebug() << "Entered DataRequestProcessor::getData";
    qDebug() << "Leaving DataRequestProcessor::getData";
    return this->data;
}

void DataRequestProcessor::setData(const QByteArray &newData)
{
    qDebug() << "Entered DataRequestProcessor::setData";
    qDebug() << "newData = " << newData;
    qDebug() << "Leaving DataRequestProcessor::setData";
    this->data = newData;
}

QByteArray DataRequestProcessor::processRequest(QByteArray requestData)
{
    qDebug() << "Entered DataRequestProcessor::processRequest";
    QByteArray responseDataDecoded;
    QByteArray responseData;
    QByteArray dataEnvelopeBytes;
    DataTransmogrifier dataTransmogrifier;
    DataEnvelope dataEnvelope;

    // Decode raw data, building a request envelope
    // Return a response envelope
    qDebug() << "Calling dataTransmogrifier.decode(requestData)";
    responseDataDecoded = dataTransmogrifier.decode(requestData);

    qDebug() << "Calling dataEnvelope.consumeRawData(responseDataDecoded)";
    dataEnvelope.consumeRawData(responseDataDecoded);

    qDebug() << "Calling dataEnvelopeBytes = dataEnvelope.toBytes()";
    dataEnvelopeBytes = dataEnvelope.toBytes();

    qDebug() << "Calling responseData = dataTransmogrifier.encode(dataEnvelopeBytes)";
    responseData = dataTransmogrifier.encode(dataEnvelopeBytes);

    qDebug() << "Leaving DataRequestProcessor::processRequest";
    return responseData;
}
