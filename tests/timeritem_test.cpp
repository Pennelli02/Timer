//
// Created by Asus on 26/03/2025.
//

#include <QSignalSpy>
#include "timeritem_test.h"



void timeritem_test::init() {
    item=new TimerItem();
}

void timeritem_test::cleanUp() {
    delete item;
    item= nullptr;
}

void timeritem_test::testInitialization()
{
    QVERIFY(item != nullptr);
    QCOMPARE(item->getRemainingSeconds(), 0);
    QVERIFY(!item->isRunning1());
    QVERIFY(!item->isFinished1());
    QVERIFY(item->getTitle().isEmpty());
    QVERIFY(item->getMusicType().isEmpty());

}

void timeritem_test::testSetDuration() {
    item->setDuration(1, 30, 15); // 1 ora, 30 minuti, 15 secondi
    QCOMPARE(item->getRemainingSeconds(), 5414);
}

void timeritem_test::testStartPause() {
    item->setDuration(0, 0, 5);

    // Test avvio
    item->startTimer();
    QVERIFY(item->isRunning1());

    // Test pausa
    item->pauseTimer();
    QVERIFY(!item->isRunning1());
    //nel far partire il timer si perde un secondo
    QCOMPARE(item->getRemainingSeconds(), 4);
}

void timeritem_test::testTimerFinished()
{
    item->setDuration(0, 0, 1);
    item->setTitle("Test Timer");
    item->setMusicType(":/sounds/alarm.wav");

    // Creiamo uno spy per il segnale timerFinished
    QSignalSpy finishedSpy(item, &TimerItem::timerFinished);

    item->startTimer();

    // Simuliamo il passare del tempo
    QTest::qWait(1500); // Attendiamo 1.5 secondi

    QVERIFY(item->isFinished1());
    QVERIFY(!item->isRunning1());
    QCOMPARE(finishedSpy.count(), 1); // Verifichiamo che il segnale sia stato emesso
}

void timeritem_test::testRepeatTimer() {
    item->setDuration(0, 0, 10);
    item->startTimer();

    // Simuliamo completamento
    QTest::qWait(10000); // Attendiamo 10 secondi

    // Ripetiamo il timer
    item->repeatTimer();
    QCOMPARE(item->getRemainingSeconds(), 10);
    QVERIFY(item->isRunning1());
    QVERIFY(!item->isFinished1());
}

void timeritem_test::testDeleteSignal()
{
    QSignalSpy deletedSpy(item, &TimerItem::timerDeleted);

    // Simuliamo click sul pulsante delete
    item->removeTimer();

    QCOMPARE(deletedSpy.count(), 1); // Verifichiamo che il segnale sia stato emesso
}

void timeritem_test::testAudioSetup()
{
    QString soundPath = "/sounds/alarm.wav";
    item->setMusicType(soundPath);
    QCOMPARE(item->getMusicType(), soundPath);

    // Nota: Testare effettivamente la riproduzione audio richiederebbe un mock non so se sia necessario
    // Qui verifichiamo solo che il path sia stato impostato correttamente
}
QTEST_MAIN(timeritem_test)