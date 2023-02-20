#include "sectime.h"
#include <QTime>

SecTime::SecTime(QWidget *parent)
    : QLabel(parent)
    , m_timer(nullptr)
{
    this->setText(QString("%1").arg(QTime::currentTime().toString()));
    this->resize(130,50);
    //开启时间定时器
    m_timer = new QTimer();
    m_timer->setInterval(1000);
    //时间显示刷新
    connect(m_timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    m_timer->start();
}

SecTime::~SecTime()
{
    delete m_timer;
    m_timer = nullptr;
}

void SecTime::onTimeOut()
{
    this->setText(QString("%1").arg(QTime::currentTime().toString()));
}
