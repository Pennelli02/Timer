//
// Created by Asus on 10/03/2025.
//

#ifndef TIMER_TIMERWINDOW_H
#define TIMER_TIMERWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TimerWindow; }
QT_END_NAMESPACE

class TimerWindow : public QWidget {
Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);

    ~TimerWindow() override;

private:
    Ui::TimerWindow *ui;
};


#endif //TIMER_TIMERWINDOW_H
