#ifndef INITIALIZESETTINGS_H
#define INITIALIZESETTINGS_H

#include <QDebug>
#include <QObject>
#include <QSettings>

class InitializeSettings : public QObject
{
    Q_OBJECT

public:
    explicit InitializeSettings(QObject *parent = nullptr);
    void initialize();

signals:

};

#endif // INITIALIZESETTINGS_H
