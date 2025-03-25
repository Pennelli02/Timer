//
// Created by Asus on 09/03/2025.
//

#ifndef TIMER_CLOCKWINDOW_H
#define TIMER_CLOCKWINDOW_H

#include <QWidget>
#include "timerwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ClockWIndow; }
QT_END_NAMESPACE

class ClockWIndow : public QWidget {
Q_OBJECT

public:
    explicit ClockWIndow(QWidget *parent = nullptr);


// getter per i test
    int getCurrentDateIndex() const;
    int getCurrentClockIndex() const;
    TimerWindow *getTimerWindow() const;
    QLabel* getClockLabel() const;
    QLabel* getDateLabel() const;
    QString getClockLabelText() const;
    QString getDateLabelText() const;

    ~ClockWIndow() override;
private slots:
    void showTime();
    void changeDateFormat();
    void changeClockFormat();
    void showTimerWindow();

private:
    Ui::ClockWIndow *ui;
    int currentDateIndex;
    int currentClockIndex;
    TimerWindow *timerWindow;
};


#endif //TIMER_CLOCKWINDOW_H
