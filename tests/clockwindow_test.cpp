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

    QString initialFormat= cw->getFormatsDate()[cw->getCurrentDateIndex()];
    QCOMPARE(initialFormat, cw->getFormatsDate()[0]); // controlliamo che abbia effettivamente preso il primo formato

    // Cambia il formato
    cw->testAccess_changeDateFormat();

    // Verifica che il formato sia cambiato
    QString newFormat=cw->getFormatsDate()[cw->getCurrentDateIndex()];

    // verifichiamo che il formato della data sia cambiato
    QVERIFY(initialFormat!=newFormat);

    // Verifica che l'indice sia incrementato
    QCOMPARE(cw->getCurrentDateIndex(), 1);
    QCOMPARE(newFormat, cw->getFormatsDate()[1]); // controlliamo che abbia preso il formato successivo
}

void clockwindow_test::testChangeClockFormat() {
    // Salva il formato corrente
    QString initFormat= cw->getFormatsCLock()[cw->getCurrentClockIndex()];
    QCOMPARE(initFormat, cw->getFormatsCLock()[0]); // controlliamo che abbia effettivamente preso il primo formato
    // Cambia il formato
    cw->testAccess_changeClockFormat();

    QString newFormat=cw->getFormatsCLock()[cw->getCurrentClockIndex()];

    // verifichiamo che il formato della data sia cambiato
    QVERIFY(initFormat!=newFormat);

    // Verifica che l'indice sia incrementato
    QCOMPARE(cw->getCurrentClockIndex(), 1);
    QCOMPARE(newFormat, cw->getFormatsCLock()[1]); // controlliamo che abbia preso il formato successivo

}

void clockwindow_test::testCycleThroughAllDateFormats() {
// Verifica che dopo 4 cambiamenti si torni al formato iniziale date
    QString initialDate = cw->getFormatsDate()[cw->getCurrentDateIndex()];

    for (int i = 0; i < cw->getFormatsDate().length(); i++) {
        cw->testAccess_changeDateFormat();
    }
    QString newDate= cw->getFormatsDate()[cw->getCurrentDateIndex()];

    // Dopo 4 cambiamenti, dovremmo essere tornati all'indice 0
    QCOMPARE(cw->getCurrentDateIndex(), 0);
    QCOMPARE(initialDate, newDate);
}
void clockwindow_test::testCycleThroughAllClockFormats(){
    // Verifica che dopo 4 cambiamenti si torni al formato iniziale clock
    QString initClockFormat= cw->getFormatsCLock()[cw->getCurrentClockIndex()];

    for (int i = 0; i < cw->getFormatsCLock().length(); ++i) {
        cw->testAccess_changeClockFormat();
    }
    QString newCLockFormat= cw->getFormatsCLock()[cw->getCurrentClockIndex()];

    QCOMPARE(cw->getCurrentClockIndex(), 0);
    QCOMPARE(initClockFormat, newCLockFormat);
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