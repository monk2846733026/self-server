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
//    m_db.setDatabaseName(BASEINFO);
    m_db.setUserName("root");
    m_db.setPassword("123456");

    bool ok = m_db.open();
    m_db.exec("SET NAMES 'UTF8'");
    qDebug()<<"is connect sql:"<<ok;

    m_hash.clear();
}
