#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mmysql.h"
#include <QString>
#include <QTime>
#include "data.h"
#include "doctor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void init();
    void startslots();

    void getclass1data();
    void getclass2data();
    void getclass3data();
    void getclass4data();
    void getclass5data();
    void getclass6data();

private slots:
    void pushbuttonStart();
    void onSubmit();
    void onPage0();
    void onPage1();
    void onPage2();
    void onPage3();
    void onPage4();
    void onPage5();
    void onPage6();
    void onPage8();
    void onPage9();
    void onPage10();
    void onPage11();
    void onPage12();
    void onTab0();
    void onTab1();
    void onTab2();
    void onTab2_0();
    void onTab2_1();
    void onTab2_1_0();
    void onTab2_1_1();
    void onTab2_1_2();
    void onTab2_1_3();
    void onTab2_1_4();
    void onTab2_1_5();
    void onTab2_2();
    void onTab3_0();
    void onTab3_1();
    void onTab3_2();



private:
    Ui::Widget *ui;
    MmySql *m_sql;
    QString user_id;
    QString user_name;
    QHash<QString, QString> m_doc;
    QList<Doctor*>m_class1;
    QList<Doctor*>m_class2;
    QList<Doctor*>m_class3;
    QList<Doctor*>m_class4;
    QList<Doctor*>m_class5;
    QList<Doctor*>m_class6;



    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

};
#endif // WIDGET_H
