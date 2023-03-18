#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QMessageBox>
#define BASEINFO "base_information"
#define CLASSINFO "class"

struct RegisterId
{
    QString id; //挂号号码
    QString classname;  //科室
    QString doctorname; //医生
    RegisterId()
    {
        id="";
        classname="";
        doctorname="";
    }
};

struct Pay
{
    QString project;    //项目
    int size;   //数目
    QString unit;//单位
    QString total;//总计
    Pay()
    {
        project="";
        size=0;
        unit="";
        total="";
    }
};

#endif // DATA_H
