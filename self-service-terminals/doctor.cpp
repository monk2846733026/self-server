#include "doctor.h"
#include "ui_doctor.h"

Doctor::Doctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Doctor)
{
    ui->setupUi(this);

    init();
}

Doctor::~Doctor()
{
    delete ui;
}

void Doctor::setButtonText(QString time,QString name)
{
    ui->label_name->setText(name);
    ui->label_time->setText(time);
}

void Doctor::init()
{
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(pushbuttonPressed()));
}

void Doctor::pushbuttonPressed()
{
    emit onDoctorPressed();
}

