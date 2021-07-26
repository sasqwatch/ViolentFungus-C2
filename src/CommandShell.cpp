#include "include/CommandShell.h"

const QString CommandShell::NAME = "CMD";

CommandShell::CommandShell(QObject *parent) : QObject(parent)
{

}

bool CommandShell::parse(QByteArray)
{
    bool status = false;
    return status;
}

bool CommandShell::process(QByteArray)
{
    bool status = false;
    return status;
}
