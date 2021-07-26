#ifndef COMMANDSHELL_H
#define COMMANDSHELL_H

#include <QObject>

#include "CommandInterface.h"

class CommandShell : public QObject, public CommandInterface
{
    Q_OBJECT
    Q_INTERFACES(CommandInterface)

public:
    static const QString NAME;

    explicit CommandShell(QObject *parent = nullptr);
    bool parse(QByteArray);   // CommandInterface
    bool process(QByteArray); // CommandInterface

signals:

};

#endif // COMMANDSHELL_H
