#ifndef COUNTDOWN_H
#define COUNTDOWN_H

//#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QLabel>

/*!
 * \brief The CountDown class
 * 右上角倒计时
 */
class CountDown : public QLabel
{
    Q_OBJECT
public:
    CountDown(QWidget *parent = nullptr);
    ~CountDown();

    void start();
    void restart();

signals:
    void counttimeout();

private slots:
    void run();

private:
    QTimer *m_timer;
    int count;
};

#endif // COUNTDOWN_H
