#ifndef DATATRANSMOGRIFIER_H
#define DATATRANSMOGRIFIER_H

#include <QObject>

class DataTransmogrifier : public QObject
{
    Q_OBJECT

public:
    explicit DataTransmogrifier(QObject *parent = nullptr);

    // Encode/Decode: modify data using whatever methods are needed
    QByteArray encode(QByteArray);
    QByteArray decode(QByteArray);

    // Compress/decompress using whatever method is configured
    QByteArray compress(QByteArray);
    QByteArray decompress(QByteArray);

    // Encrypt/decrypt using whatever symmetric encryption is configured
    QByteArray encryptSymmetric(QByteArray);
    QByteArray decryptSymmetric(QByteArray);

    // Encrypt/decrypt using whatever asymmetric encryption is configured
    QByteArray encryptAsymmetric(QByteArray);
    QByteArray decryptAsymmetric(QByteArray);

signals:

};

#endif // DATATRANSMOGRIFIER_H
