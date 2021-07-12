#ifndef INITIALIZEDATABASE_H
#define INITIALIZEDATABASE_H

#include <QObject>

#include "Database.h"

class InitializeDatabase : public QObject
{
    Q_OBJECT
public:
    explicit InitializeDatabase(QObject *parent = nullptr);
    void initialize();

signals:

};

#endif // INITIALIZEDATABASE_H
