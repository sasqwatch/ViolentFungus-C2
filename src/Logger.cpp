#include "include/Logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    // Check if table exists, if not create it
    Database database;
    if (! database.getDb().tables().contains( QLatin1String("log"))) {
        this->provisionDatabase();
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

void Logger::provisionDatabase()
{
    qDebug() << "Entered Logger::provisionDatabase";
    Database database;
    QString sql;


    if (database.getDb().driverName() == "QSQLITE") {
        sql = "create table log (id integer primary key autoincrement, subject text, scope varchar(255), message varchar(255), ts datetime default current_timestamp)";
    }
    else if (database.getDb().driverName() == "QPGSQL") {
        sql = "create table log (id bigserial, subject varchar(255), scope varchar(255), message text, ts timestamp default current_timestamp)";
    }
    else if (database.getDb().driverName() == "QMYSQL") {
        sql = "create table log (id bigint not null primary key auto_increment, subject varchar(255), scope varchar(255), message text, ts timestamp default current_timestamp)";
    }
    else {
        qCritical() << "Logger does not know how to provision for database type " << database.getDb().driverName();
    }

    qDebug() << "executing SQL: " << sql;
    database.getDb().exec(sql);

    qDebug() << "leaving Logger::provisionDatabase";

}
