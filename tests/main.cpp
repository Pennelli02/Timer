//
// Created by Asus on 31/03/2025.
//

#include <QtTest>
#include "timeritem_test.h"
#include "timerwindow_test.h"
#include "clockwindow_test.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv); // Per test GUI

    int result = 0;

    result |= QTest::qExec(new timerwindow_test, argc, argv);
    result |= QTest::qExec(new timeritem_test, argc, argv);
    result |= QTest::qExec(new clockwindow_test, argc, argv);

    return (result == 0) ? 0 : 1;
}