#include "include/CommandHandler.h"

CommandHandler::CommandHandler(QObject *parent) : QObject(parent)
{

    QMap<QString,QSharedPointer<CommandInterface>> commandMap;

    // Shell
    QSharedPointer<CommandInterface> commandShell(new CommandShell());
    commandMap.insert(CommandShell::NAME, commandShell);

    // Download
    // Upload
    // Ping
    // Key
    // Info

    qDebug() << "commandMap = " << commandMap;
}
