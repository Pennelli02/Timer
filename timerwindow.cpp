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
    soundType="/sounds/alarm.wav";
    ui->timersList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->timersList->setUniformItemSizes(false);
    ui->timersList->setSpacing(5);
    ui->timersList->setStyleSheet("QListWidget { background-color: #2a2a2a; }");
    connect(ui->startTimer, &QPushButton::clicked, this, &TimerWindow::addTimer);
    connect(ui->menuButton, &QPushButton::clicked, this, &TimerWindow::selectSound);
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

void TimerWindow::selectSound() {
// Creazione del menu a tendina
    QMenu menu(this);

    // Aggiunta delle opzioni al menu
    QAction *opzione1 = menu.addAction("Default alarm");
    QAction *opzione2 = menu.addAction("Rooster crowing");
    QAction *opzione3 = menu.addAction("Retro game");
    QAction *opzione4 = menu.addAction("Slot machine");

    // Mostrare il menu accanto al pulsante quando viene premuto
    QAction *selezionato = menu.exec(ui->menuButton->mapToGlobal(QPoint(0, ui->menuButton->height())));

    // Verifica quale opzione è stata selezionata
    if (selezionato == opzione1) {
        soundType="/sounds/alarm.wav";
    } else if (selezionato == opzione2) {
        soundType="/sounds/rooster-crowing.wav";
    }else if (selezionato==opzione3){
        soundType="/sounds/retro-game.wav";
    } else if (selezionato==opzione4){
        soundType="/sounds/slot-machine.wav";
    }
}

void TimerWindow::addTimer() {
    int hours = ui->hourSpinBox->value();
    int minutes = ui->minSpinBox->value();
    int seconds = ui->secondsSpinBox->value();

    if (hours == 0 && minutes == 0 && seconds == 0) return; // Non aggiungere timer con 0 tempo

    TimerItem *timer = new TimerItem(this);
    timer->setMusicType(soundType);
    timer->setDuration(hours, minutes, seconds);
    QListWidgetItem *item = new QListWidgetItem(ui->timersList);
    item->setSizeHint(QSize(ui->timersList->width() - 10, 119));

    ui->timersList->addItem(item);
    ui->timersList->setItemWidget(item, timer);
    ui->timersList->scrollToItem(item);
    activeTimers.append(timer);

    connect(timer, &TimerItem::timerDeleted, this, &TimerWindow::removeTimer);

}


