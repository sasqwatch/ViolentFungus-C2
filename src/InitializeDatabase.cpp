#include "InitializeDatabase.h"

InitializeDatabase::InitializeDatabase(QObject *parent) : QObject(parent)
{

}

void InitializeDatabase::initialize()
{
    qDebug() << "Entered InitializeDatabase::initialize";
    Database database;
    qDebug() << "Created database object";


    if (database.getDb().driverName() == "QSQLITE") {
        qDebug() << "In SQLite provisioning...";

        // Create tables by instantiating

        Logger logger;
        logger.log("Entered InitializeDatabase::initialize, probably provisioning the table for the first time", "InitializeDatabase::initialize", "InitializeDatabase::initialize");

        // Store the request and response
        DataRequestProcessor dataRequestProcessor;

        qDebug() << "Done SQLite Provisioning";
    }

    qDebug() << "Leaving InitializeDatabase::initialize";
}
