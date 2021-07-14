#ifndef DATAENVELOPECHUNKER_H
#define DATAENVELOPECHUNKER_H

#include <QObject>

class DataEnvelopeChunker : public QObject
{
    Q_OBJECT

public:
    explicit DataEnvelopeChunker(QObject *parent = nullptr);

protected:

    qint16 dataBytePosition; // current position in the data
    qint16 dataChunkId; // id for record in the database in table data_chunk
    bool isTransferred;
    bool isAcknowledged;
    QByteArray data;

signals:

};

#endif // DATAENVELOPECHUNKER_H
