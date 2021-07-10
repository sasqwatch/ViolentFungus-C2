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





int main(int argc, char *argv[])
{
    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}DEBUG%{endif}%{if-info}INFOS%{endif}%{if-warning}WARNS%{endif}%{if-critical}CRITS%{endif}%{if-fatal}FATAL%{endif}] %{file}:%{line} - %{message}");

    QCoreApplication app(argc, argv);
    QCoreApplication::setOrganizationName("SogonSecurity");
    QCoreApplication::setOrganizationDomain("sogonsecurity.com");
    QCoreApplication::setApplicationName("ViolentFungus");
    QCoreApplication::setApplicationVersion("v0.1-development");
    QTextStream out(stdout);
    out << QCoreApplication::applicationName() << " " << QCoreApplication::applicationVersion()
        << " SPORE GEN STARTING." << Qt::endl << Qt::endl;

    // Parse configuration file
    QString settingsFile = QCoreApplication::applicationDirPath() + QDir::separator() + "violentfungus.ini";
    qDebug() << "settingsFile:" << settingsFile;
    QSettings settings(settingsFile, QSettings::IniFormat);


    // CLI argument provisioning
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName() + " " + QCoreApplication::applicationVersion() + " C2 - A PoC learning project by Chris Humphries (@sogonsec)");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption serviceTcpOption("service-tcp", QCoreApplication::translate("main", "Enable raw TCP service."));
    QCommandLineOption serviceTcpPortOption("service-tcp-port", QCoreApplication::translate("main", "Raw TCP service port number.")
                                       ,QCoreApplication::translate("main", "port number"));
    parser.addOption(serviceTcpOption);
    parser.addOption(serviceTcpPortOption);

    parser.process(app);


    // Set the global thread pool count
    qDebug() << "THREAD_POOL_MAX" << THREAD_POOL_MAX;
    QThreadPool::globalInstance()->setMaxThreadCount(THREAD_POOL_MAX);

    // Start services
    bool servicesStarted = false;
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
        }
        if (port < 1 || port > 65535) {
            qFatal("The raw TCP port number should be between 1 and 65535.");
        }
        serviceTcp.startService(port);
        if (serviceTcp.isListening()) {
            qInfo() << "[+] Service: raw TCP service is listening on port " << port << "." << Qt::endl;
            servicesStarted = true;
        }
        else {
            qWarning() << "[!] Service: raw TCP service is NOT listening on port " << port << "." << Qt::endl;

        }
    }

    if (servicesStarted == false) {
        out << "No services are started! You need to start a service for this software to be useful." << Qt::endl;
        exit(EXIT_FAILURE);
    }

    // Application started withqInfo() error if reached here
    out << QCoreApplication::applicationName() << " "
        << QCoreApplication::applicationVersion()
        << " SPORE GEN ACTIVE. HAVE FUN!" << Qt::endl;

    // Main loop
    return app.exec();
}
