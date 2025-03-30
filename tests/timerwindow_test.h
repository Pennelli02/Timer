//
// Created by Asus on 28/03/2025.
//

#ifndef TIMER_TIMERWINDOW_TEST_H
#define TIMER_TIMERWINDOW_TEST_H

#include <QtTest>
#include <QSignalSpy>
#include <QPushButton>
#include "../timerwindow.h"

class timerwindow_test : public QObject
{
Q_OBJECT

private slots:
    void init();
    void cleanup();
    void testInitialState();
    void testAddTimer();
    void testRemoveTimer();
    void testSelectSound();

private:
    TimerWindow* window;
};


#endif //TIMER_TIMERWINDOW_TEST_H
