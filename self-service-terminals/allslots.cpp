#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTime>

void Widget::pushbuttonStart()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->countdown->start();
}

void Widget::onPage0()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->countdown->restart();
}
void Widget::onPage1()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->countdown->restart();
}

void Widget::onPage2()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->countdown->restart();
}

void Widget::onPage3()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->countdown->restart();
}

void Widget::onSubmit()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->countdown->restart();

    user_id = ui->lineEdit_id->text();
    user_name = ui->lineEdit_name->text();
    m_sql->createTable(BASEINFO,user_id);
    m_sql->insertData(BASEINFO,user_id,"姓名",ui->lineEdit_name->text());
    int year = QDate::currentDate().toString("yyyy-MM-dd").left(4).toInt();
    int age = year - user_id.left(10).right(4).toInt();
    m_sql->insertData(BASEINFO,user_id,"年龄",QString::number(age));
    int sex = user_id.right(2).left(1).toInt();
    m_sql->insertData(BASEINFO,user_id,"性别",QString("%1").arg(sex%2>0?"女":"男"));
    m_sql->insertData(BASEINFO,user_id,"手机号",ui->lineEdit_phone->text());
    m_sql->createtablepay(BASEINFO,user_id);

}

void Widget::onPage4()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->countdown->restart();
}

void Widget::onPage5()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->countdown->restart();
}
void Widget::onPage6()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->countdown->restart();
    tablepayshow();
}

void Widget::onPage7()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->countdown->restart();
}
void Widget::onPage8()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->countdown->restart();
}
void Widget::onPage9()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->countdown->restart();
}
void Widget::onPage10()
{
    bool ok = m_sql->backregisterid(BASEINFO,user_id);
    if(ok)
    {
        ui->stackedWidget->setCurrentIndex(10);
        ui->countdown->restart();
    }
}
void Widget::onPage11()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->countdown->restart();
}
void Widget::onPage12()
{

    int index = m_sql->getAllData(CLASSINFO,m_doc.value("tablename")).size()-2;
    bool ok = m_sql->insertData(CLASSINFO,m_doc.value("tablename"),QString::number(index),user_name);
    if(ok)
    {
        RegisterId data;
        data.id = QString::number(index);
        data.classname = m_doc.value("所属科室");
        data.doctorname = m_doc.value("姓名");
        bool ko = m_sql->createRegisterTable(BASEINFO,user_id+"register",data);
        if(ko)
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->countdown->restart();
            Pay paydata;
            paydata.project="挂号";
            paydata.size=1;
            paydata.unit="5/人";
            paydata.total="5";
            m_sql->createtablepay(BASEINFO,user_id+"pay");
            m_sql->inserttablepay(BASEINFO,user_id+"pay",paydata);
        }
    }
}

void Widget::onTab0()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->countdown->restart();
}

void Widget::onTab1()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->countdown->restart();
}

void Widget::onTab2()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->countdown->restart();
}

void Widget::onTab2_0()
{
    ui->tabWidget_2->setCurrentIndex(0);
    ui->countdown->restart();
}

void Widget::onTab2_1()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->countdown->restart();
}
void Widget::onTab2_1_0()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->countdown->restart();
}
void Widget::onTab2_1_1()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->countdown->restart();
}
void Widget::onTab2_1_2()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->countdown->restart();
}
void Widget::onTab2_1_3()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(3);
    ui->countdown->restart();
}
void Widget::onTab2_1_4()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->countdown->restart();
}
void Widget::onTab2_1_5()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(5);
    ui->countdown->restart();
}

void Widget::onTab2_2()
{
    ui->tabWidget_2->setCurrentIndex(2);
    ui->countdown->restart();
}
void Widget::onTab3_0()
{
    ui->tabWidget_3->setCurrentIndex(0);
    ui->countdown->restart();
}

void Widget::onTab3_1()
{
    ui->tabWidget_3->setCurrentIndex(1);
    ui->countdown->restart();
}

void Widget::onTab3_2()
{
    ui->tabWidget_3->setCurrentIndex(2);
    ui->countdown->restart();
}
