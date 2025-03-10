//
// Created by Asus on 10/03/2025.
//

#ifndef TIMER_TIMERITEM_H
#define TIMER_TIMERITEM_H

#include <QWidget>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class TimerItem; }
QT_END_NAMESPACE

class TimerItem : public QWidget {
Q_OBJECT



public:
    explicit TimerItem(QWidget *parent = nullptr);
    void setDuration(int hours, int minutes, int seconds);
    ~TimerItem() override;
signals:
    void timerDeleted(TimerItem *timer);
    void timerFinished(TimerItem *timer);

private slots:
    void startTimer();
    void pauseTimer();
    void updateDisplay();
    void handleTimerFinished();
    void removeTimer();
    void on_startPauseButton_clicked();
    void on_deleteTimer_clicked();

private:
    Ui::TimerItem *ui;
    QTimer *timer;
    QTimer *deleteTimer;
    int remainingSeconds;
    bool isRunning;
};


#endif //TIMER_TIMERITEM_H
