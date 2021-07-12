#include "InitializeDatabase.h"

InitializeDatabase::InitializeDatabase(QObject *parent) : QObject(parent)
{

}

void InitializeDatabase::initialize()
{
    qDebug() << "Entered InitializeDatabase::initialize";
    Database database;
    qDebug() << "Created database object";

    database.connectToDatabase();
    qDebug() << "Connected to database";


    if (database.getDb().driverName() == "QSQLITE") {

    }

    qDebug() << "connectOptions: " << database.getDb().connectOptions();
    qDebug() << "Leaving InitializeDatabase::initialize";
}
