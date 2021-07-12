#include "DataTransmogrifier.h"

DataTransmogrifier::DataTransmogrifier(QObject *parent) : QObject(parent)
{

}

QByteArray DataTransmogrifier::encode(QByteArray data)
{
    return data;


    QByteArray newData;
    newData = this->compress(data);
    return newData;
}

QByteArray DataTransmogrifier::decode(QByteArray data)
{
    return data;


    QByteArray newData;
    newData = this->decompress(data);
    return newData;
}

QByteArray DataTransmogrifier::compress(QByteArray data)
{
    QByteArray newData;
    newData = qCompress(data, 9);

    return newData;
}

QByteArray DataTransmogrifier::decompress(QByteArray data)
{
    QByteArray newData;
    newData = qUncompress(data);

    return newData;
}

QByteArray DataTransmogrifier::encryptSymmetric(QByteArray data)
{
    return data;
}

QByteArray DataTransmogrifier::decryptSymmetric(QByteArray data)
{
    return data;
}

QByteArray DataTransmogrifier::encryptAsymmetric(QByteArray data)
{
    return data;
}

QByteArray DataTransmogrifier::decryptAsymmetric(QByteArray data)
{
    return data;
}
