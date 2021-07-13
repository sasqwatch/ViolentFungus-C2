#ifndef DATAREQUESTPROCESSOR_H
#define DATAREQUESTPROCESSOR_H

#include <QObject>
#include <QDebug>

#include "Database.h"
#include "DataEnvelope.h"
#include "DataTransmogrifier.h"

class DataRequestProcessor : public QObject
{
    Q_OBJECT

public:
    explicit DataRequestProcessor(QObject *parent = nullptr);

    const QByteArray &getData() const;
    void setData(const QByteArray &newData);

    QByteArray processRequest(QByteArray);
    void log(QByteArray request, QByteArray response);

signals:

private:
    QByteArray data;

};

#endif // DATAREQUESTPROCESSOR_H
