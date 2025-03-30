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

void timerwindow_test::testAddTimer()
{
    // Trova i widget
    QPushButton* startButton = window->findChild<QPushButton*>("startTimer");
    QVERIFY(startButton != nullptr);  // Assicura che il pulsante esista

    QSpinBox* hourBox = window->findChild<QSpinBox*>("hourSpinBox");
    QSpinBox* minBox = window->findChild<QSpinBox*>("minSpinBox");
    QSpinBox* secBox = window->findChild<QSpinBox*>("secondsSpinBox");
    QVERIFY(hourBox && minBox && secBox);

    // Imposta valori
    hourBox->setValue(0);
    minBox->setValue(1);
    secBox->setValue(30);

    // Simula click
    QTest::mouseClick(startButton, Qt::LeftButton);

    // Verifica che il timer sia stato aggiunto
    QListWidget* list = window->findChild<QListWidget*>("timersList");
    QVERIFY(list != nullptr);
    QCOMPARE(list->count(), 1);

    qDebug() << "testiamo anche che il caso in cui l'utente inserisca un timer di 00:00:00";
    hourBox->setValue(0);
    minBox->setValue(0);
    secBox->setValue(0);

    QTest::mouseClick(startButton, Qt::LeftButton);
    QCOMPARE(list->count(), 1); // controlliamo che non sia stato inserito
}

void timerwindow_test::testRemoveTimer()
{
    QListWidget* list = window->findChild<QListWidget*>("timersList");
    QVERIFY(list != nullptr);

    // Trova i widget
    QPushButton* startButton = window->findChild<QPushButton*>("startTimer");
    QVERIFY(startButton != nullptr);  // Assicura che il pulsante esista

    QSpinBox* hourBox = window->findChild<QSpinBox*>("hourSpinBox");
    QSpinBox* minBox = window->findChild<QSpinBox*>("minSpinBox");
    QSpinBox* secBox = window->findChild<QSpinBox*>("secondsSpinBox");
    QVERIFY(hourBox && minBox && secBox);

    // Imposta valori
    hourBox->setValue(0);
    minBox->setValue(1);
    secBox->setValue(30);

    // Simula click
    QTest::mouseClick(startButton, Qt::LeftButton);

    QCOMPARE(list->count(), 1);

    QListWidgetItem* item = list->item(0);
    TimerItem* timer = qobject_cast<TimerItem*>(list->itemWidget(item));
    QVERIFY(timer != nullptr);

    // Crea uno spy per verificare il segnale
    QSignalSpy spy(timer, &TimerItem::timerDeleted);
    QVERIFY(spy.isValid());  // Verifica che la connessione sia valida

    timer->removeTimer();

    // Aspetta fino a 1 secondo per vedere se il segnale viene emesso

    QCOMPARE(spy.count(), 1);
    QCOMPARE(list->count(), 0);
}

void timerwindow_test::testSelectSound()
{
    QPushButton* soundButton = window->findChild<QPushButton*>("menuButton");
    QVERIFY(soundButton != nullptr);

    // Memorizza il testo iniziale
    QString initialText = soundButton->text();

    // Testa direttamente la funzione senza aprire il menu
    window->selectSoundOption(0); // 0 = Default alarm

    // Verifiche
    QCOMPARE(soundButton->text(), QString("Default alarm"));
    QCOMPARE(window->getSoundType(), QString("sounds/alarm.wav"));
    QVERIFY(soundButton->text() != initialText);
}

//QTEST_MAIN(timerwindow_test)