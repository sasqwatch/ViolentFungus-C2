#include "InitializeSettings.h"

InitializeSettings::InitializeSettings(QObject *parent) : QObject(parent)
{

}

void InitializeSettings::initialize()
{
    qDebug() << "Entered InitializeSettings::initialize";
    QSettings settings;

    settings.setValue("system/thread_pool_max", "auto");
    settings.setValue("system/domain", "auto");

    settings.setValue("database/type", "sqlite");
    settings.setValue("database/sqlite_filename", "violentfungus.db");

    settings.setValue("service/tcp", false);
    settings.setValue("service/udp", false);
    settings.setValue("service/dns_udp", false);
    settings.setValue("service/dns_https", false);
    settings.setValue("service/ftp", false);
    settings.setValue("service/https", false);
    settings.setValue("service/icmp", false);
    settings.setValue("service/smtp", false);
    settings.setValue("service/snmp", false);

    settings.setValue("tcp/port", 31101);

    settings.setValue("udp/port", 31102);

    settings.setValue("dns_udp/port", 53);

    settings.setValue("dns_https/port", 443);

    settings.setValue("ftp/port", 21);

    settings.setValue("https/port", 443);

    settings.setValue("smtp/port", 25);

    settings.setValue("snmp/port", 161);

    settings.setValue("encryption/symmetric", false);
    settings.setValue("encryption/symmetric_algorithm", "auto");
    settings.setValue("encryption/asymmetric", false);
    settings.setValue("encryption/asymmetric_algorithm", "auto");
    settings.setValue("encryption/asymmetric_key_private", "auto");
    settings.setValue("encryption/asymmetric_key_public", "auto");

    settings.setValue("compression/level", 9);

    qDebug() << "syncing settings";
    settings.sync();

    qDebug() << "Leaving InitializeSettings::initialize";
}
