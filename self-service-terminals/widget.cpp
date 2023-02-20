#include "widget.h"
#include "ui_widget.h"


#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_sql(nullptr)
{
    ui->setupUi(this);

    init();
    startslots();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    //数据库类
    m_sql = MmySql::getinstance();

    //时间右下角,赋初值
    ui->label_time_1->setText(QString("%1").arg(QTime::currentTime().toString()));

    //按钮同大
    ui->pushButton_start->resize(ui->stackedWidget->width(),ui->stackedWidget->height());
}

void Widget::startslots()
{
    //时间耗尽
    connect(ui->countdown,SIGNAL(counttimeout()),this,SLOT(onPage0()));
    connect(ui->pushButton_start,SIGNAL(pressed()),this,SLOT(pushbuttonStart()));
    connect(ui->pushButton_id,SIGNAL(pressed()),this,SLOT(onPage2()));
    connect(ui->pushButton_id_1,SIGNAL(pressed()),this,SLOT(onPage2()));
    connect(ui->pushButton_back_1,SIGNAL(pressed()),this,SLOT(onPage1()));
    connect(ui->pushButton_back_2,SIGNAL(pressed()),this,SLOT(onTab0()));
    connect(ui->pushButton_back_3,SIGNAL(pressed()),this,SLOT(onTab1()));
    connect(ui->pushButton_back_4,SIGNAL(pressed()),this,SLOT(onPage4()));
    connect(ui->pushButton_back_7,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_back_8,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_submit_1,SIGNAL(pressed()),this,SLOT(onTab1()));
    connect(ui->pushButton_submit_2,SIGNAL(pressed()),this,SLOT(onTab2()));
    //身份证 姓名 手机号 提交数据库
    connect(ui->pushButton_submit_3,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_number,SIGNAL(pressed()),this,SLOT(onPage4()));
    connect(ui->pushButton_register_id,SIGNAL(pressed()),this,SLOT(onPage5()));
    connect(ui->pushButton_back_5,SIGNAL(pressed()),this,SLOT(onTab2_0()));
    connect(ui->pushButton_room_1,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_room_2,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_room_3,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_room_4,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_room_5,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_room_6,SIGNAL(pressed()),this,SLOT(onTab2_1()));

    //医生消息
    ui->widget->setButtonText("就诊时间:10:00-11:30 \n 医生姓名:asd");
    connect(ui->widget,SIGNAL(onDoctorPressed()),this,SLOT(onTab2_2()));

    connect(ui->pushButton_back_6,SIGNAL(pressed()),this,SLOT(onTab2_1()));
    connect(ui->pushButton_back_15,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_back_14,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_info,SIGNAL(pressed()),this,SLOT(onPage8()));
    connect(ui->pushButton_idea,SIGNAL(pressed()),this,SLOT(onPage9()));
    connect(ui->pushButton_pay,SIGNAL(pressed()),this,SLOT(onPage6()));
    connect(ui->pushButton_submit_8,SIGNAL(pressed()),this,SLOT(onTab3_1()));
    connect(ui->pushButton_submit_5,SIGNAL(pressed()),this,SLOT(onTab3_2()));
    connect(ui->pushButton_back_10,SIGNAL(pressed()),this,SLOT(onTab3_1()));
    connect(ui->pushButton_back_9,SIGNAL(pressed()),this,SLOT(onTab3_0()));
    connect(ui->pushButton_cancel_id,SIGNAL(pressed()),this,SLOT(onPage10()));
    connect(ui->pushButton_submit_11,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_submit_7,SIGNAL(pressed()),this,SLOT(onPage11()));
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(onPage11()));
    connect(ui->pushButton_submit_4,SIGNAL(pressed()),this,SLOT(onPage12()));
    connect(ui->pushButton_submit_10,SIGNAL(pressed()),this,SLOT(onPage3()));
    connect(ui->pushButton_submit_6,SIGNAL(pressed()),this,SLOT(onPage3()));
}

void Widget::resizeEvent(QResizeEvent *event)
{
    ui->pushButton_start->resize(ui->stackedWidget->width(),ui->stackedWidget->height());


}



