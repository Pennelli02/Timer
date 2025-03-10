//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerWindow.h" resolved

#include "timerwindow.h"
#include "ui_TimerWindow.h"


TimerWindow::TimerWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::TimerWindow) {
    ui->setupUi(this);
    setWindowTitle("Gestione Timer");
}

TimerWindow::~TimerWindow() {
    delete ui;
}

