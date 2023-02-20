#include "widget.h"
#include "ui_widget.h"


#include <QTime>

void Widget::getclass1data()
{
    m_class1.clear();
    QList<QHash<QString, QString>> data = m_sql->getClass1Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_4->insertWidget(ui->verticalLayout_4->count()-1,doctor);
        m_class1.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
void Widget::getclass2data()
{
    m_class2.clear();
    QList<QHash<QString, QString> > data = m_sql->getClass2Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_20->insertWidget(ui->verticalLayout_20->count()-1,doctor);
        m_class2.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
void Widget::getclass3data()
{
    m_class3.clear();
    QList<QHash<QString, QString> > data = m_sql->getClass3Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_21->insertWidget(ui->verticalLayout_21->count()-1,doctor);
        m_class3.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
void Widget::getclass4data()
{
    m_class4.clear();
    QList<QHash<QString, QString> > data = m_sql->getClass4Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_22->insertWidget(ui->verticalLayout_22->count()-1,doctor);
        m_class4.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
void Widget::getclass5data()
{
    m_class5.clear();
    QList<QHash<QString, QString> > data = m_sql->getClass5Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_23->insertWidget(ui->verticalLayout_23->count()-1,doctor);
        m_class5.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
void Widget::getclass6data()
{
    m_class6.clear();
    QList<QHash<QString, QString> > data = m_sql->getClass6Data();
    for(int index = 0; index<data.size();index++)
    {
        Doctor *doctor = new Doctor();
        doctor->setButtonText(data.at(index).value("就诊时间"),data.at(index).value("姓名"));
        ui->verticalLayout_24->insertWidget(ui->verticalLayout_24->count()-1,doctor);
        m_class6.append(doctor);
        connect(doctor,&Doctor::onDoctorPressed,this,[=](){
            onTab2_2();
            ui->label_classname->setText(data.at(index).value("所属科室"));
            ui->label_seetime->setText(QTime::currentTime().toString());
            ui->label_doctorname->setText(data.at(index).value("姓名"));
            m_doc = data.at(index);
        });
    }
}
