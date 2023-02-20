#ifndef DOCTOR_H
#define DOCTOR_H

#include <QWidget>

namespace Ui {
class Doctor;
}

class Doctor : public QWidget
{
    Q_OBJECT

public:
    explicit Doctor(QWidget *parent = nullptr);
    ~Doctor();

    void setButtonText(QString text);

private:
    void init();
private slots:
    void pushbuttonPressed();
signals:
    void onDoctorPressed();

private:
    Ui::Doctor *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // DOCTOR_H
