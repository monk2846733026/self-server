#include "mmysql.h"
#include <QDebug>


MmySql * MmySql::m_instance = nullptr ;

MmySql *MmySql::getinstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new MmySql();
    }
    return m_instance;
}

bool MmySql::createTable(QString databasename, QString id)
{
    QSqlQuery create;
    QString str = QString("CREATE TABLE `%1`.`%2` (\
  `key` VARCHAR(600) NOT NULL,`value` VARCHAR(600) NULL,PRIMARY KEY (`key`))\
    ENGINE = InnoDB DEFAULT CHARACTER SET = utf8 COLLATE = utf8_bin;").arg(databasename).arg(id);
    bool iscreate = create.exec(str);
    if(!iscreate)
    {
        return iscreate;
    }
    qDebug()<<"creat table :"<<iscreate;
    return iscreate;
}

bool MmySql::insertData(QString databasename, QString id, QString key, QString value)
{
    QSqlQuery insert;
    QString str = QString("INSERT INTO `%1`.`%2` (`key`, `value`) VALUES ('%3', '%4');").arg(databasename).arg(id).arg(key.data()).arg(value.data());
    //codeChange(str);
    bool isinsert = insert.exec(str);
    qDebug()<<"inster:"<<isinsert<<"--"<<key<<value;
    return isinsert;
}

QHash<QString, QString> MmySql::getAllData(QString databasename, QString id)
{
    m_hash.clear();
    QString str = QString("SELECT * FROM %1.`%2`;").arg(databasename).arg(id);
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        m_hash.insert(result.value("key").toString(),result.value("value").toString());
    }
    return m_hash;
}

MmySql::MmySql()
{
    init();
}

void MmySql::init()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setPort(3306);
    m_db.setUserName("root");
    m_db.setPassword("123456");
    bool ok = m_db.open();
    m_db.exec("SET NAMES 'UTF8'");
    qDebug()<<"is connect sql:"<<ok;

    QList<QHash<QString,QString>> a = getClass2Data();
    qDebug()<<a.size();

    //CREATE SCHEMA `class` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
    //创建数据库1.患者信息数据库 2.科室医生数据库 3.记录医院每日的信息数据库（待确定哪些数据应该每天保存）
    if(!isHaveDatabase(BASEINFO))
    {
        //数据库1
        QSqlQuery createDatabase;
        QString str = QString("CREATE SCHEMA `base_information` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;");
        bool iscreatedatabase = createDatabase.exec(str);
        qDebug()<<"iscreatedatabase `base_information`:"<<iscreatedatabase;
    }
    if(!isHaveDatabase(CLASSINFO))
    {
        //数据库2
        QSqlQuery createDatabase;
        QString str = QString("CREATE SCHEMA `class` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;");
        bool iscreatedatabase = createDatabase.exec(str);
        qDebug()<<"iscreatedatabase class:"<<iscreatedatabase;
    }
    m_hash.clear();
}

bool MmySql::isHaveDatabase(QString databasename)
{
    //判断数据库是否存在
    QString str = QString("SELECT information_schema.SCHEMATA.SCHEMA_NAME FROM information_schema.SCHEMATA where SCHEMA_NAME='%1';").arg(databasename);
    QSqlQuery result = m_db.exec(str);
    int count = 0;
    while(result.next())
    {
        count++;
    }
    qDebug()<<"count:"<<count;
    return count>0?true:false;
}

bool MmySql::isHaveTable(QString databasename, QString tablename)
{
    //判断数据库中的一张表是否存在
    QString str = QString("SELECT DISTINCT t.table_name, n.SCHEMA_NAME FROM information_schema.TABLES t, information_schema.SCHEMATA n WHERE t.table_name = '%1' AND n.SCHEMA_NAME = '%2';").arg(tablename).arg(databasename);
    QSqlQuery result = m_db.exec(str);
    int count = 0;
    while(result.next())
    {
        count++;
    }
    qDebug()<<"count:"<<count;
    return count>0?true:false;
}
