#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mmysql.h"
#include <QString>
#include <QTime>
#include "data.h"

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

private slots:
    void pushbuttonStart();
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
    void onTab2_2();
    void onTab3_0();
    void onTab3_1();
    void onTab3_2();



private:
    Ui::Widget *ui;
    MmySql *m_sql;
    QString user_id;


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

};
#endif // WIDGET_H
