//
// Created by Asus on 28/03/2025.
//


#include <QSpinBox>
#include "timerwindow_test.h"
void timerwindow_test::init()
{
    window = new TimerWindow();
    window->show();
}

void timerwindow_test::cleanup()
{
    delete window;
}

void timerwindow_test::testInitialState()
{
    // Verifica lo stato iniziale della finestra
    QVERIFY(window != nullptr);
    QCOMPARE(window->windowTitle(), QString("Timer Manager"));
    QCOMPARE(window->findChild<QListWidget*>("timersList")->count(), 0);
    QCOMPARE(window->findChild<QSpinBox*>("hourSpinBox")->value(), 0);
    QCOMPARE(window->findChild<QSpinBox*>("minSpinBox")->value(), 0);
    QCOMPARE(window->findChild<QSpinBox*>("secondsSpinBox")->value(), 0);
}

//void timerwindow_test::testAddTimer()
//{
//    // Imposta valori di test
//    window->findChild<QSpinBox*>("hourSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("minSpinBox")->setValue(1);
//    window->findChild<QSpinBox*>("secondsSpinBox")->setValue(30);
//
//    // Simula click sul pulsante di aggiunta timer
//    QTest::mouseClick(window->findChild<QPushButton*>("startTimer"), Qt::LeftButton);
//
//    // Verifica che il timer sia stato aggiunto
//    QCOMPARE(window->findChild<QListWidget*>("timersList")->count(), 1);
//
//    // Verifica che non venga aggiunto un timer con durata 0
//    window->findChild<QSpinBox*>("hourSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("minSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("secondsSpinBox")->setValue(0);
//    QTest::mouseClick(window->findChild<QPushButton*>("startTimer"), Qt::LeftButton);
//    QCOMPARE(window->findChild<QListWidget*>("timersList")->count(), 1);
//}
//
//void timerwindow_test::testRemoveTimer()
//{
//    // Aggiungi un timer
//    window->findChild<QSpinBox*>("hourSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("minSpinBox")->setValue(1);
//    window->findChild<QSpinBox*>("secondsSpinBox")->setValue(0);
//    QTest::mouseClick(window->findChild<QPushButton*>("startTimer"), Qt::LeftButton);
//
//    // Ottieni il timer aggiunto
//    QListWidget* list = window->findChild<QListWidget*>("timersList");
//    QListWidgetItem* item = list->item(0);
//    TimerItem* timer = qobject_cast<TimerItem*>(list->itemWidget(item));
//
//    // Crea uno spy per il segnale di rimozione
//    QSignalSpy spy(timer, &TimerItem::timerDeleted);
//
//    // Simula la rimozione
//    timer->removeTimer();
//
//    // Verifica che il timer sia stato rimosso
//    QCOMPARE(spy.count(), 1);
//    QCOMPARE(list->count(), 0);
//}
//
//void timerwindow_test::testSelectSound()
//{
//    // Simula click sul pulsante del menu
//    QPushButton* soundButton = window->findChild<QPushButton*>("menuButton");
//    QTest::mouseClick(soundButton, Qt::LeftButton);
//
//    // Verifica che il menu sia visibile (test indiretto)
//    QMenu* menu = soundButton->findChild<QMenu*>();
//    QVERIFY(menu != nullptr);
//
//    // Nota: Per testare la selezione effettiva, dovresti simulare la selezione di un'azione
//    // Questo è più complesso e potrebbe richiedere l'uso di QTest::keyClick o simili
//}
//
//void timerwindow_test::testTitleEditor()
//{
//    // Imposta un titolo di test
//    QString testTitle = "Test Timer";
//
//    // Simula click sul pulsante del titolo
//    QTest::mouseClick(window->findChild<QPushButton*>("titleButton"), Qt::LeftButton);
//
//    // Nota: Per testare completamente la dialog, dovresti:
//    // 1. Creare un mock della dialog
//    // 2. Simulare l'input dell'utente
//    // 3. Verificare che il titolo sia stato aggiornato
//
//    // Questo è un test semplificato che verifica solo l'apertura della dialog
//    QVERIFY(window->findChild<QDialog*>() != nullptr);
//}
//
//void timerwindow_test::testTimerIntegration()
//{
//    // Test di integrazione tra TimerWindow e TimerItem
//
//    // Configura un mock player
//    window->findChild<QPushButton*>("menuButton")->setText("Test Sound");
//    window->setSoundType(":/sounds/test.wav");
//
//    // Aggiungi un timer breve
//    window->findChild<QSpinBox*>("hourSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("minSpinBox")->setValue(0);
//    window->findChild<QSpinBox*>("secondsSpinBox")->setValue(1);
//    QTest::mouseClick(window->findChild<QPushButton*>("startTimer"), Qt::LeftButton);
//
//    // Ottieni il timer
//    QListWidget* list = window->findChild<QListWidget*>("timersList");
//    TimerItem* timer = qobject_cast<TimerItem*>(list->itemWidget(list->item(0)));
//    timer->setMediaPlayer(mockPlayer); // Inietta il mock
//
//    // Avvia il timer e attendi il completamento
//    timer->startTimer();
//    QTest::qWait(1500); // 1.5 secondi per sicurezza
//
//    // Verifica che il player sia stato attivato
//    QVERIFY(mockPlayer->wasPlayCalled());
//}
//QTEST_MAIN(timerwindow_test)