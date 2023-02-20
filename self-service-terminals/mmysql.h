#ifndef MMYSQL_H
#define MMYSQL_H

#include <QHash>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class MmySql : public QObject
{
    Q_OBJECT
public:
    static MmySql* getinstance();

    /*基础信息*/
    bool createTable(QString databasename, QString id);
    bool insertData(QString databasename, QString id, QString key, QString value);
    QHash<QString,QString> getAllData(QString databasename,QString id);

private:
    MmySql();
    void init();

private:
    QSqlDatabase m_db;
    static MmySql *m_instance;
    QHash<QString,QString>m_hash;
};

#endif // MMYSQL_H
