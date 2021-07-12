#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSettings>
#include <QtSql>


class Database : public QObject
{
    Q_OBJECT

public:
    explicit Database(QObject *parent = nullptr);
    bool connectToDatabase();
    const QSqlDatabase getDb();
    void setDb(QSqlDatabase newDb);

protected:
    QString generateUniqueName(QString name);
    QSqlDatabase db;
    QString name;

signals:


};

#endif // DATABASE_H
