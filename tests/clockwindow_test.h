//
// Created by Asus on 23/03/2025.
//

#ifndef TIMER_CLOCKWINDOW_TEST_H
#define TIMER_CLOCKWINDOW_TEST_H

#include <QTest>
#include <QSignalSpy>
#include "../clockwindow.h"



class clockwindow_test: public QObject
        {
        Q_OBJECT

        private slots:
            void init();
            void cleanup();
            void testInitialState();
            void testChangeDateFormat();
            void testChangeClockFormat();
            void testCycleThroughAllDateFormats();
            void testCycleThroughAllClockFormats();
            void testTimerWindowCreation();

private:
            ClockWIndow * cw;


};


#endif //TIMER_CLOCKWINDOW_TEST_H
