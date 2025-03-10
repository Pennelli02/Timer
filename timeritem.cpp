//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerItem.h" resolved

#include "timeritem.h"
#include "ui_TimerItem.h"

TimerItem::TimerItem(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::TimerItem),
        remainingSeconds(0),
        isRunning(false) {

    ui->setupUi(this);
    timer = new QTimer(this);
    deleteTimer = new QTimer(this);  // Timer per rimuovere l'elemento dopo la fine
    connect(timer, &QTimer::timeout, this, &TimerItem::updateDisplay);
    connect(deleteTimer, &QTimer::timeout, this, &TimerItem::removeTimer);
}

TimerItem::~TimerItem() {
    delete ui;
}

void TimerItem::setDuration(int hours, int minutes, int seconds) {
    remainingSeconds = (hours * 3600) + (minutes * 60) + seconds;
    updateDisplay();
    startTimer();
}

void TimerItem::startTimer() {
    if (remainingSeconds > 0 && !isRunning) {
        timer->start(1000);
        isRunning = true;
        ui->startPauseButton->setText("Pause");
    }
}

void TimerItem::pauseTimer() {
    if (isRunning) {
        timer->stop();
        isRunning = false;
        ui->startPauseButton->setText("Start");
    }
}



void TimerItem::updateDisplay() {
    if (remainingSeconds > 0) {
        remainingSeconds--;
        int h = remainingSeconds / 3600;
        int m = (remainingSeconds % 3600) / 60;
        int s = remainingSeconds % 60;
        ui->timerLabel->setText(QString("%1:%2:%3")
                                       .arg(h, 2, 10, QChar('0'))
                                       .arg(m, 2, 10, QChar('0'))
                                       .arg(s, 2, 10, QChar('0')));
    } else {
        handleTimerFinished();
    }
}
void TimerItem::handleTimerFinished() {
    timer->stop();
    isRunning = false;
    ui->startPauseButton->setText("Start");

    // Mostra il messaggio di avviso
    ui->timerLabel->setText("TIMER SCADUTO!");
    ui->timerLabel->setStyleSheet("color: red; font-weight: bold;");

    emit timerFinished(this);

    // Dopo 5 secondi il timer verrà rimosso
    deleteTimer->start(5000);
}

void TimerItem::removeTimer() {
    emit timerDeleted(this);
}

void TimerItem::on_startPauseButton_clicked() {
    if (isRunning)
        pauseTimer();
    else
        startTimer();
}

void TimerItem::on_deleteTimer_clicked() {
    emit timerDeleted(this);
}
