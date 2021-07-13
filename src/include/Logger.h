#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>

#include "Database.h"

class Logger : public QObject
{
    Q_OBJECT

public:
    explicit Logger(QObject *parent = nullptr);
    void log(QString message, QString scope, QString subject);

signals:

};

#endif // LOGGER_H
