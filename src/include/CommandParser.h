#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QObject>

class CommandParser : public QObject
{
    Q_OBJECT
public:
    explicit CommandParser(QObject *parent = nullptr);

signals:

};

#endif // COMMANDPARSER_H
