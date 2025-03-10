//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerItem.h" resolved

#include "timeritem.h"
#include "ui_TimerItem.h"


TimerItem::TimerItem(QWidget *parent) :
        QWidget(parent), ui(new Ui::TimerItem), remainingSeconds(0),
        isRunning(false) {
    ui->setupUi(this);
    // Ensure that text is visible on dark background
    ui->timerLabel->setStyleSheet("color: white;");
    ui->startPauseButton->setStyleSheet("background-color: #555555; color: white;");
    ui->deleteTimer->setStyleSheet("background-color: #555555; color: white;");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimerItem::updateDisplay);
    connect(ui->startPauseButton, &QPushButton::clicked, this, &TimerItem::on_startPauseButton_clicked);
    connect(ui->deleteTimer, &QPushButton::clicked, this, &TimerItem::on_deleteTimer_clicked);
}

TimerItem::~TimerItem() {
    delete ui;
}

void TimerItem::setDuration(int hours, int minutes, int seconds) {
    remainingSeconds = (hours * 3600) + (minutes * 60) + seconds;
    startTimer();
    updateDisplay();
}
void TimerItem::startTimer() {
    if (remainingSeconds > 0 ) {
        timer->start(1000);
        isRunning = true;
        ui->startPauseButton->setText("Pause");
    }
}
void TimerItem::pauseTimer() {
        timer->stop();
        isRunning = false;
        ui->startPauseButton->setText("Start");

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
        timer->stop();
        isRunning = false;
        ui->startPauseButton->setText("Start");
        emit timerFinished(this);
    }
}
void TimerItem::on_startPauseButton_clicked() {
        if (timer->isActive()) {
            // Il timer è attivo, quindi lo fermiamo
            timer->stop();
            ui->startPauseButton->setText("Start");
            isRunning = false;
        } else {
            // Il timer è fermo, quindi lo avviamo
            if (remainingSeconds > 0) {
                timer->start(1000);
                ui->startPauseButton->setText("Pause");
                isRunning = true;
            }
        }
    }


void TimerItem::on_deleteTimer_clicked() {
    emit timerDeleted(this);
}

