#ifndef SECTIME_H
#define SECTIME_H

#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QWidget>

class SecTime : public QLabel
{
    Q_OBJECT
public:
    SecTime(QWidget *parent);
    ~SecTime();

private slots:
    void onTimeOut();

private:
    QTimer *m_timer;
};

#endif // SECTIME_H
