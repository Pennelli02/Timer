//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerWindow.h" resolved

#include "timerwindow.h"
#include "ui_TimerWindow.h"


TimerWindow::TimerWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::TimerWindow) {
    ui->setupUi(this);
    setWindowTitle("Timer Manager");
    ui->timersList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->timersList->setUniformItemSizes(false);
    ui->timersList->setSpacing(5);
    ui->timersList->setStyleSheet("QListWidget { background-color: #2a2a2a; }");
    connect(ui->startTimer, &QPushButton::clicked, this, &TimerWindow::addTimer);
}

TimerWindow::~TimerWindow() {
    delete ui;
}

void TimerWindow::removeTimer(TimerItem *timer) {
    for (int i = 0; i < ui->timersList->count(); ++i) {
        QListWidgetItem *item = ui->timersList->item(i);
        if (ui->timersList->itemWidget(item) == timer) {
            activeTimers.removeOne(timer);
            delete item;
            delete timer;
            break;
        }
    }
}

void TimerWindow::addTimer() {
    int hours = ui->hourSpinBox->value();
    int minutes = ui->minSpinBox->value();
    int seconds = ui->secondsSpinBox->value();

    if (hours == 0 && minutes == 0 && seconds == 0) return; // Non aggiungere timer con 0 tempo

    TimerItem *timer = new TimerItem(this);
    timer->setDuration(hours, minutes, seconds);

    QListWidgetItem *item = new QListWidgetItem(ui->timersList);
    item->setSizeHint(QSize(ui->timersList->width() - 10, 119));

    ui->timersList->addItem(item);
    ui->timersList->setItemWidget(item, timer);
    ui->timersList->scrollToItem(item);
    activeTimers.append(timer);

    connect(timer, &TimerItem::timerDeleted, this, &TimerWindow::removeTimer);

}


