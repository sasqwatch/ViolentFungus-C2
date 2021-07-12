#ifndef INITIALIZEDATABASE_H
#define INITIALIZEDATABASE_H

#include <QObject>


#include "Database.h"

/* Include classes that have database stuff, so obstanciation of them creates the database table(s) */
#include "Logger.h"
#include "DataRequestProcessor.h"

class InitializeDatabase : public QObject
{
    Q_OBJECT

public:
    explicit InitializeDatabase(QObject *parent = nullptr);
    void initialize();

signals:

};

#endif // INITIALIZEDATABASE_H
