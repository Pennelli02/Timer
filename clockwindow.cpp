//
// Created by Asus on 09/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClockWIndow.h" resolved

#include "clockwindow.h"
#include "ui_ClockWIndow.h"
#include <QTimer>
#include <QDateTime>

ClockWIndow::ClockWIndow(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClockWIndow), currentDateIndex(0), currentClockIndex(0), timerWindow(nullptr) {
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClockWIndow::showTime);
    timer->start(1000);  // Aggiorna ogni secondo

    connect(ui->changeFormat, &QPushButton::clicked, this, &ClockWIndow::changeDateFormat);
    connect(ui->clockFormat, &QPushButton::clicked, this, &ClockWIndow::changeClockFormat);
    connect(ui->openTimer, &QPushButton::clicked, this, &ClockWIndow::showTimerWindow);
    showDate();
}

ClockWIndow::~ClockWIndow() {
    delete ui;
    delete timerWindow;
}

void ClockWIndow::showTime() {
    QTime time = QTime::currentTime();
    QString timeText = time.toString(formatsCLock[currentClockIndex]);

    switch (currentClockIndex) {
        case 0:
            if((time.second()%2)==0){
                timeText[3]=' ';
                timeText[8]=' ';
            }
            break;
        case 1:
            if((time.second()%2)==0){
                timeText[2]=' ';
                timeText[5]=' ';
            }
            break;
        case 2:
            if((time.second()%2)==0)
                timeText[2]=' ';
            break;
        case 3:
            if((time.second()%2)==0)
                timeText[2]=' ';
            break;
    }
    ui->ClockLabel->setText(timeText);
}

void ClockWIndow::changeDateFormat() {
    // Passa al formato successivo
    currentDateIndex = (currentDateIndex + 1) % formatsDate.length();
    showDate();
}

void ClockWIndow::changeClockFormat() {
 currentClockIndex=(currentClockIndex+1)% formatsCLock.length(); // 4 formati
 showTime();
}

void ClockWIndow::showTimerWindow() {
    if (!timerWindow) {
        timerWindow = new TimerWindow();
    }
    timerWindow->show();
}



int ClockWIndow::getCurrentDateIndex() const {
    return currentDateIndex;
}

int ClockWIndow::getCurrentClockIndex() const {
    return currentClockIndex;
}

TimerWindow *ClockWIndow::getTimerWindow() const {
    return timerWindow;
}

QLabel *ClockWIndow::getClockLabel() const {
    return ui->ClockLabel;
}

QLabel *ClockWIndow::getDateLabel() const {
    return ui->DateLabel;
}

QString ClockWIndow::getClockLabelText() const {
    return ui->ClockLabel->text();
}

QString ClockWIndow::getDateLabelText() const {
    return ui->DateLabel->text();
}

void ClockWIndow::showDate() {
    QDateTime date = QDateTime::currentDateTime();
    QString dateText;

    // Seleziona il formato corrente
    dateText = date.toString(formatsDate[currentDateIndex]);

    // Aggiorna l'etichetta con la data formattata
    ui->DateLabel->setText(dateText);
}
// per il testing
const QStringList &ClockWIndow::getFormatsDate() const {
    return formatsDate;
}

const QStringList &ClockWIndow::getFormatsCLock() const {
    return formatsCLock;
}

