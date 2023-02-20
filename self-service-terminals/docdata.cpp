#include "mmysql.h"
#include <QDebug>

QList<QHash<QString, QString> > MmySql::getClass1Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }

    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='神经康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
//            qDebug()<<rr.value("value").toString();
        }
//        qDebug()<<count;
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
//    qDebug()<<aa;
    return  aa;
}

QList<QHash<QString, QString> > MmySql::getClass2Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }
    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='骨伤康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
        }
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
//    qDebug()<<aa;
    return  aa;
}
QList<QHash<QString, QString> > MmySql::getClass3Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }
    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='老年康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
        }
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
    //    qDebug()<<aa;
    return  aa;
}
QList<QHash<QString, QString> > MmySql::getClass4Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }
    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='心肺康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
        }
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
    //    qDebug()<<aa;
    return  aa;
}
QList<QHash<QString, QString> > MmySql::getClass5Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }
    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='儿童康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
        }
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
    //    qDebug()<<aa;
    return  aa;
}
QList<QHash<QString, QString> > MmySql::getClass6Data()
{
    QList<QHash<QString, QString>> aa;
    QStringList tablenames;

    QString str = QString("show tables from class;");
    QSqlQuery result = m_db.exec(str);
    while(result.next())
    {
        tablenames.append(result.value("Tables_in_class").toString());
    }
    for(int index=0; index < tablenames.size(); index++)
    {
        QString ss = QString("SELECT `value` FROM class.%1 WHERE `value`='心理康复';").arg(tablenames[index]);
        QSqlQuery rr = m_db.exec(ss);
        int count=0;
        while(rr.next())
        {
            count++;
        }
        if(count)
        {
            QHash<QString, QString> tmp;
            result = m_db.exec(QString("SELECT * FROM class.`%1`;").arg(tablenames[index]));
            while(result.next())
            {
                tmp.insert(result.value("key").toString(),result.value("value").toString());
            }
            tmp.insert("tablename",tablenames[index]);
            aa.append(tmp);
        }
    }
    //    qDebug()<<aa;
    return  aa;
}
