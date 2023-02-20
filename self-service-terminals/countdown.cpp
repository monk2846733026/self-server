#include "countdown.h"

CountDown::CountDown(QWidget *parent):m_timer(nullptr)
  , count (300)
{
    count = 300;

    m_timer = new QTimer();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(run()));
}

void CountDown::start()
{
    this->setText("300");
    m_timer->start(1000);
}

void CountDown::restart()
{
    count = 300;
}

CountDown::~CountDown()
{
    if(m_timer!=nullptr)
    {
        delete  m_timer;
        m_timer = nullptr;
    }
}

void CountDown::run()
{
    if(count!=0)
    {
        count--;
    }
    else if(count == 0)
    {
        emit counttimeout();
        this->setText("");
        m_timer->stop();
    }
    QString num = QString::number(count);
    this->setText(num);
}
