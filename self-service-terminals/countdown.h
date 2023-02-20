#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QObject>
#include <QTimer>
#include <QLabel>

class CountDown : public QLabel
{
    Q_OBJECT
public:
    CountDown(QWidget *parent);
    void start();
    void restart();
    ~CountDown();

signals:
    void counttimeout();

private slots:
    void run();

private:
    QTimer *m_timer;
    int count;
};

#endif // COUNTDOWN_H
