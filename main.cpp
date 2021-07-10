#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QList>
#include <QListIterator>
#include <QSettings>
#include <QtSql>
#include <QString>
#include <QTextStream>

#include "ServiceTcp.h"

#ifndef THREAD_POOL_MAX
#define THREAD_POOL_MAX 100
#endif

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setOrganizationName("SogonSecurity");
    QCoreApplication::setOrganizationDomain("sogonsecurity.com");
    QCoreApplication::setApplicationName("ViolentFungus");
    QCoreApplication::setApplicationVersion("0.1");
    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line} - %{message}");
    QTextStream out(stdout);

    // Parse configuration file
    QString settingsFile = QCoreApplication::applicationDirPath() + QDir::separator() + "violentfungus.ini";
    qDebug() << "settingsFile: " << settingsFile;
    QSettings settings(settingsFile, QSettings::IniFormat);


    // CLI argument provisioning
    QCommandLineParser parser;
    parser.setApplicationDescription("ViolentFungus C2 - A PoC learning project by Chris Humphries (@sogonsec)");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption serviceTcpOption("service-tcp", QCoreApplication::translate("main", "Enable raw TCP service."));
    QCommandLineOption serviceTcpPortOption("service-tcp-port", QCoreApplication::translate("main", "Raw TCP service port number.")
                                       ,QCoreApplication::translate("main", "port number"));
    parser.addOption(serviceTcpOption);
    parser.addOption(serviceTcpPortOption);

    parser.process(app);


    // Set the global thread pool count
    QThreadPool::globalInstance()->setMaxThreadCount(THREAD_POOL_MAX);

    // Start services
    ServiceTcp serviceTcp;
    if (parser.isSet(serviceTcpOption) || settings.value("service/tcp").toBool()) {
        if (parser.isSet(serviceTcpOption)) {
            qDebug() << "Enabling raw TCP service via command line argument (--service-tcp).";
        } else if (settings.value("service/tcp").toBool()) {
            qDebug() << "Enabling raw TCP service via configuration file (service/tcp).";
        } else {
            qDebug() << "Impossible location";
        }
        // Start the service
        quint16 port = settings.value("tcp/port").toInt();
        if (parser.isSet(serviceTcpPortOption)) {
            port = parser.value(serviceTcpPortOption).toInt();
            qDebug() << "Using port number from command line argument (--service-tcp-port).";
            if (port < 1 || port > 65535) {
                qFatal("--service-tcp-port provided and it should be a number between 1 and 65535.");
            }
        } else if (port > 0 && port <= 65535) {
            qDebug() << "Using port number from the configuration file (tcp/port).";
        }

        serviceTcp.startService(port);
        if (serviceTcp.isListening()) {
            out << "[+] Service: raw TCP service is listening on port " << port << "." << Qt::endl;
        }
        else {
            out << "[!] Service: raw TCP service is NOT listening on port " << port << "." << Qt::endl;

        }
    }



    qDebug() << "Entering main loop!";
    return app.exec();
}
