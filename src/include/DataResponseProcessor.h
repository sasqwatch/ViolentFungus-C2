#ifndef DATARESPONSEPROCESSOR_H
#define DATARESPONSEPROCESSOR_H

#include <QObject>

#include "DataEnvelope.h"
#include "DataTransmogrifier.h"

class DataResponseProcessor : public QObject
{
    Q_OBJECT

public:
    explicit DataResponseProcessor(QObject *parent = nullptr);

    const QByteArray &getData() const;
    void setData(const QByteArray &newData);

    QByteArray createResponseFromRequest(QByteArray);

signals:

private:
    QByteArray data;

};

#endif // DATARESPONSEPROCESSOR_H
