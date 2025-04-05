//
// Created by Asus on 23/03/2025.
//


#include "clockwindow_test.h"

void clockwindow_test::init() {
    // Setup che viene eseguito prima di ogni test
    cw = new ClockWIndow();
}

void clockwindow_test::cleanup() {
    // Pulizia dopo ogni test
    delete cw;
    cw = nullptr;
}

void clockwindow_test::testInitialState() {
    // Verifica che l'orologio sia inizializzato correttamente
    QVERIFY(cw != nullptr);
    QVERIFY(cw->getClockLabel() != nullptr);
    QVERIFY(cw->getDateLabel() != nullptr);

    // Verifica che gli indici interni siano inizializzati a 0
    QCOMPARE(cw->getCurrentDateIndex(), 0);
    QCOMPARE(cw->getCurrentClockIndex(), 0);
}

void clockwindow_test::testChangeDateFormat() {
// Salva il formato corrente
    QString initialDate = cw->getDateLabelText();

    // Cambia il formato
    cw->testAccess_changeDateFormat();

    // Verifica che il formato sia cambiato
    QString newDate = cw->getDateLabelText();
    QVERIFY(initialDate != newDate);

    // Verifica che l'indice sia incrementato
    QCOMPARE(cw->getCurrentDateIndex(), 1);
}

void clockwindow_test::testChangeClockFormat() {
    // Salva il formato corrente
    QString initialTime = cw->getClockLabelText();

    // Cambia il formato
    cw->testAccess_changeClockFormat();

    QString newTime= cw->getClockLabelText();
    QVERIFY(initialTime != newTime);
    // Verifica che l'indice sia incrementato
    QCOMPARE(cw->getCurrentClockIndex(), 1);
}

void clockwindow_test::testCycleThroughAllDateFormats() {
// Verifica che dopo 4 cambiamenti si torni al formato iniziale
    QString initialDate = cw->getDateLabelText();

    for (int i = 0; i < 4; i++) {
        cw->testAccess_changeDateFormat();
    }
    QString newDate= cw->getDateLabelText();

    // Dopo 4 cambiamenti, dovremmo essere tornati all'indice 0
    QCOMPARE(cw->getCurrentDateIndex(), 0);
}

void clockwindow_test::testTimerWindowCreation() {
    // Verifica che la finestra timer sia nullptr all'inizio
    QVERIFY(cw->getTimerWindow() == nullptr);

    // Mostra la finestra timer
    cw->testAccess_showTimerWindow();

    // Verifica che la finestra timer sia stata creata
    QVERIFY(cw->getTimerWindow() != nullptr);
}
//QTEST_MAIN(clockwindow_test)