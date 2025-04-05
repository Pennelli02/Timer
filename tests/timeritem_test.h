//
// Created by Asus on 26/03/2025.
//

#ifndef TIMER_TIMERITEM_TEST_H
#define TIMER_TIMERITEM_TEST_H

#include <QTest>
#include <QSignalSpy>
#include "../timeritem.h"


class timeritem_test: public QObject
{
    Q_OBJECT

private slots:
   void init();
  // void cleanup();
    void testInitialization();
    void testSetDuration();
    void testStartPause();
    void testTimerFinished();
    void testRepeatTimer();
    void testDeleteSignal();
    void testAudioSetup();
    void testMediaPlayer();
private:
    TimerItem* item;
};


#endif //TIMER_TIMERITEM_TEST_H
