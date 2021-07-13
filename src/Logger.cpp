#include "include/Logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    // Check if table exists, if not create it
    Database database;
    if (! database.getDb().tables().contains( QLatin1String("log"))) {
        qCritical() << "Database is missing the 'log' table.";
    }
}

void Logger::log(QString message, QString scope, QString subject)
{
    qDebug() << "Entered Logger::log";

    Database database;

    QSqlQuery sqlQuery(database.getDb());
    sqlQuery.prepare("insert into log (message, scope, subject) values (:message, :scope, :subject)");
    sqlQuery.bindValue(":message", message);
    sqlQuery.bindValue(":scope", scope);
    sqlQuery.bindValue(":subject", subject);
    sqlQuery.exec();

    qDebug() << "Leaving Logger::log";
}

