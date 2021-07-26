#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

#include <QtPlugin>

class CommandInterface
{
public:
    virtual bool parse(QByteArray) = 0;
    virtual bool process(QByteArray) = 0;
};

#define CommandInterface_iid "com.sogonsecurity.CommandInterface"

Q_DECLARE_INTERFACE(CommandInterface, CommandInterface_iid)

#endif // COMMANDINTERFACE_H
