#ifndef MMYSQL_H
#define MMYSQL_H

#include <QHash>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "data.h"

class MmySql : public QObject
{
    Q_OBJECT
public:
    static MmySql* getinstance();

    /*基础信息*/
    bool createTable(QString databasename, QString id);
    bool insertData(QString databasename, QString id, QString key, QString value);

    QHash<QString,QString> getAllData(QString databasename,QString id);

    //获取神经康复科室所有医生数据
    QList<QHash<QString,QString>> getClass1Data();
    //骨伤康复
    QList<QHash<QString,QString>> getClass2Data();
    //老年康复
    QList<QHash<QString,QString>> getClass3Data();
    //心肺康复
    QList<QHash<QString,QString>> getClass4Data();
    //儿童康复
    QList<QHash<QString,QString>> getClass5Data();
    //心理康复
    QList<QHash<QString,QString>> getClass6Data();

private:
    MmySql();
    void init();
    bool isHaveDatabase(QString databasename);
    bool isHaveTable(QString databasename, QString tablename);

private:
    QSqlDatabase m_db;
    static MmySql *m_instance;
    QHash<QString,QString>m_hash;

};

#endif // MMYSQL_H
