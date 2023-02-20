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

void Doctor::setButtonText(QString text)
{
    ui->pushButton->setText(text);
}

void Doctor::init()
{
    ui->pushButton->move(0,0);
    ui->pushButton->resize(this->size());

    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(pushbuttonPressed()));
}

void Doctor::pushbuttonPressed()
{
    emit onDoctorPressed();
}

void Doctor::resizeEvent(QResizeEvent *event)
{
    ui->pushButton->resize(this->size());
}
