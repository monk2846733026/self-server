#ifndef SQL_H
#define SQL_H

#include <QObject>

class SQL : public QObject
{
    Q_OBJECT
public:
    explicit SQL(QObject *parent = nullptr);

public:
    //创建:患者信息表、预约表、医生信息表、排队表
    void createMyTables();

//    //创建表, 数据库名称、表名称
//    bool createTable(QString databasename, QString id);
//    //插入表数据，数据库名称、表名称、插入的数据，key,vavlue
//    bool insertData(QString databasename, QString id, QString key, QString value);


signals:

};

#endif // SQL_H
