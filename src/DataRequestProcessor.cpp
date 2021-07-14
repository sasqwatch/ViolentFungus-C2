#include "DataRequestProcessor.h"

DataRequestProcessor::DataRequestProcessor(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataRequestProcessor::DataRequestProcessor";

    // Check if table exists, if not create it
    Database database;
    if (! database.getDb().tables().contains( QLatin1String("request_response"))) {
        qCritical() << "Database is missing the 'request_response' table.";
    }

    qDebug() << "Leaving DataRequestProcessor::DataRequestProcessor";
}


void DataRequestProcessor::log(QByteArray request, QByteArray response)
{
    qDebug() << "Entered DataRequestProcessor::log";

    Database database;

    QSqlQuery sqlQuery(database.getDb());
    sqlQuery.prepare("insert into request_response (request, response) values (:request, :response)");
    sqlQuery.bindValue(":request", request);
    sqlQuery.bindValue(":response", response);
    sqlQuery.exec();

    qDebug() << "Leaving DataRequestProcessor::log";
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
    dataEnvelopeBytes = dataEnvelope.getData();

    qDebug() << "Calling responseData = dataTransmogrifier.encode(dataEnvelopeBytes)";
    responseData = dataTransmogrifier.encode(dataEnvelopeBytes);

    qDebug() << "Leaving DataRequestProcessor::processRequest";
    return responseData;
}
