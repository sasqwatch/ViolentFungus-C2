#ifndef DATAENVELOPEHEADER_H
#define DATAENVELOPEHEADER_H

#include <QObject>
#include <QDebug>

/*
 * Is included as part of DataEnvelope, think of it like HTTP headers.
 *
 * <header key>: <header value>
 * header key is a string, header value is a byte array
 *
 */
class DataEnvelopeHeader : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelopeHeader(QObject *parent = nullptr);

    const QMap<QString, QByteArray> &getHeaders() const;
    void setHeaders(const QMap<QString, QByteArray> &newHeaders);

    void add(QString key, QByteArray value);
    void remove(QString key);

    QList<QString> getKeysByValue(QByteArray value);
    QByteArray getValueByKey(QString key);

protected:
    QMap<QString, QByteArray> headers;

signals:

};

#endif // DATAENVELOPEHEADER_H
