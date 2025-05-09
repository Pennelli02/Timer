//
// Created by Asus on 10/03/2025.
//

#ifndef TIMER_TIMERWINDOW_H
#define TIMER_TIMERWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QListWidget>
#include "timeritem.h"
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class TimerWindow; }
QT_END_NAMESPACE

class TimerWindow : public QWidget {
Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);
    QString getSoundType() const { return soundType; }
    void selectSound();
    void selectSoundOption(int index);
    ~TimerWindow() override;
private slots:
    void addTimer();       // Aggiunge un nuovo timer
    void removeTimer(TimerItem *timer);// Rimuove un timer
    void showTitleEditor();
private:
    QString genericTitle;
    QString soundType;
    Ui::TimerWindow *ui;
    QList<TimerItem*> activeTimers; // Lista dei timer attivi
};


#endif //TIMER_TIMERWINDOW_H
