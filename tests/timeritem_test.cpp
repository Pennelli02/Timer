//
// Created by Asus on 26/03/2025.
//


#include "timeritem_test.h"



void timeritem_test::init() {
    item=new TimerItem();
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
    item->setMusicType("/sounds/alarm.wav");

    // Creiamo uno spy per il segnale timerFinished
    QSignalSpy finishedSpy(item, &TimerItem::timerFinished);

    item->startTimer();

    // Simuliamo il passare del tempo
    QTest::qWait(1500); // Attendiamo 1.5 secondi

    //simuliamo il click dell'utente sulla finestra aperta
    QTest::qWait(100);
    QMessageBox* msgBox = item->getActiveMessageBox();
    QVERIFY(msgBox != nullptr);  // Assicurati che sia stata creata
    // Simula chiusura della finestra di avviso
    if (item->getActiveMessageBox()!= nullptr) {
        item->getActiveMessageBox()->close();
    }  // Chiudila (equivale a cliccare su "Ok")

    QVERIFY(item->isFinished1());
    QVERIFY(!item->isRunning1());
    QCOMPARE(finishedSpy.count(), 1); // Verifichiamo che il segnale sia stato emesso

    // Verifica che il messaggio sia stato correttamente rimosso dopo la chiusura
    QVERIFY(item->getActiveMessageBox() == nullptr);
}

void timeritem_test::testRepeatTimer() {
    item->setDuration(0, 0, 5);
    item->startTimer();

    // Simuliamo completamento
    QTest::qWait(5000); // Attendiamo 5 secondi

    QTRY_VERIFY(item->getActiveMessageBox() != nullptr);
    QMessageBox* msgBox = item->getActiveMessageBox();
    msgBox->accept(); // Chiudila (equivale a cliccare su "Ok")  // Chiudila (equivale a cliccare su "Ok")
    // Ripetiamo il timer
    item->repeatTimer();
    QCOMPARE(item->getRemainingSeconds(), 5);
    QVERIFY(item->isRunning1());
    QVERIFY(!item->isFinished1());
    QVERIFY(item->getRemainingSeconds() <= 5); // non deve superare il tempo iniziale
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

void timeritem_test::testMediaPlayer() {
    item->setDuration(0, 0, 1);
    item->setMusicType("sounds/alarm.wav");

    QMediaPlayer *player = item->getPlayer();
    QVERIFY(player != nullptr);  // Assicura che il player sia valido

    qDebug() << "Setting media source to:" << item->getMusicType();
    player->setSource(QUrl::fromLocalFile(item->getMusicType()));

    // Connetti segnali per debug
    connect(player, &QMediaPlayer::mediaStatusChanged, [](QMediaPlayer::MediaStatus status) {
        qDebug() << "Media status changed:" << status;
    });

    connect(player, &QMediaPlayer::playbackStateChanged, [](QMediaPlayer::PlaybackState state) {
        qDebug() << "Playback state changed:" << state;
    });

    QSignalSpy mediaSpy(player, &QMediaPlayer::mediaStatusChanged);
    QSignalSpy playbackSpy(player, &QMediaPlayer::playbackStateChanged);

    // Avvia il player
    player->play();
    QTest::qWait(100);  // Tempo per aggiornare lo stato

    // Verifica che i segnali siano stati emessi
    QTRY_VERIFY(mediaSpy.count() > 0);
    QTRY_VERIFY(playbackSpy.count() > 0);

    QCOMPARE(player->playbackState(), QMediaPlayer::PlayingState);
    QMessageBox* msgBox = item->getActiveMessageBox();
    msgBox->accept();
    QTest::qWait(1000);

    QCOMPARE(player->playbackState(), QMediaPlayer::StoppedState);


}

/*void timeritem_test::cleanup() {
    if (item) {
        item->disconnect(); // prevenire segnali indesiderati
        delete item;
        item = nullptr;
    }
}*/

//QTEST_MAIN(timeritem_test)