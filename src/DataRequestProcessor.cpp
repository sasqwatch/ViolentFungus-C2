#include "DataRequestProcessor.h"

DataRequestProcessor::DataRequestProcessor(QObject *parent) : QObject(parent)
{
    qDebug() << "Entered DataRequestProcessor::DataRequestProcessor";

    // Check if table exists, if not create it
    Database database;
    if (! database.getDb().tables().contains( QLatin1String("request_response"))) {
        this->provisionDatabase();
    }

    qDebug() << "Leaving DataRequestProcessor::DataRequestProcessor";
}

void DataRequestProcessor::provisionDatabase()
{
    qDebug() << "Entered DataRequestProcessor::provisionDatabase";
    Database database;
    QString sql;

    if (database.getDb().driverName() == "QSQLITE") {
        sql = "create table request_response (id integer primary key autoincrement, request blob, response blob, ts datetime default current_timestamp)";
    }
    else if (database.getDb().driverName() == "QPGSQL") {
        sql = "create table request_response (id bigserial, request bytea, response bytea, ts timestamp default current_timestamp)";
    }
    else if (database.getDb().driverName() == "QMYSQL") {
        sql = "create table request_response (id bigint not null primary key auto_increment, request blob, response blob, ts timestamp default current_timestamp)";
    }
    else {
        qCritical() << "Logger does not know how to provision for database type " << database.getDb().driverName();
    }

    qDebug() << "executing SQL: " << sql;
    database.getDb().exec(sql);

    qDebug() << "leaving DataRequestProcessor::provisionDatabase";

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
    dataEnvelopeBytes = dataEnvelope.toBytes();

    qDebug() << "Calling responseData = dataTransmogrifier.encode(dataEnvelopeBytes)";
    responseData = dataTransmogrifier.encode(dataEnvelopeBytes);

    qDebug() << "Leaving DataRequestProcessor::processRequest";
    return responseData;
}
