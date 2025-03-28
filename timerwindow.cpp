//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerWindow.h" resolved

#include "timerwindow.h"
#include "ui_TimerWindow.h"
#include "titledialog.h"


TimerWindow::TimerWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::TimerWindow) {
    ui->setupUi(this);
    setWindowTitle("Timer Manager");
    soundType="sounds/alarm.wav";
    genericTitle="Timer";
    ui->timersList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->timersList->setUniformItemSizes(false);
    ui->timersList->setSpacing(5);
    ui->timersList->setStyleSheet("QListWidget { background-color: #2a2a2a; }");
    connect(ui->startTimer, &QPushButton::clicked, this, &TimerWindow::addTimer);
    connect(ui->menuButton, &QPushButton::clicked, this, &TimerWindow::selectSound);
    connect(ui->titleButton, &QPushButton::clicked, this, &TimerWindow::showTitleEditor);
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
    QAction *opzione5 = menu.addAction("Siren");
    QAction *opzione6 = menu.addAction("Bonus");
    QAction *opzione7=menu.addAction("Estate");
    QAction *opzione8=menu.addAction("DragonBall");

    // Mostrare il menu accanto al pulsante quando viene premuto
    QAction *selezionato = menu.exec(ui->menuButton->mapToGlobal(QPoint(0, ui->menuButton->height())));

    // Percorso base per i file audio
    QString soundsPath = "sounds/";

    // Verifica quale opzione è stata selezionata
    if (selezionato == opzione1) {
        soundType = soundsPath + "alarm.wav";
        ui->menuButton->setText("Default alarm");
    } else if (selezionato == opzione2) {
        soundType = soundsPath + "rooster-crowing.wav";
        ui->menuButton->setText("Rooster crowing");
    } else if (selezionato == opzione3) {
        soundType = soundsPath + "retro-game.wav";
        ui->menuButton->setText("Retro game");
    } else if (selezionato == opzione4) {
        soundType = soundsPath + "slot-machine.wav";
        ui->menuButton->setText("Slot machine");
    } else if(selezionato == opzione5) {
        soundType = soundsPath + "siren.wav";
        ui->menuButton->setText("Siren");
    } else if(selezionato == opzione6) {
        soundType = soundsPath + "la fine.mp3";
        ui->menuButton->setText("Bonus");
    }else if (selezionato==opzione7){
        soundType=soundsPath+ "cinotti.mpeg";
        ui->menuButton->setText("Estate");
    }else if (selezionato==opzione8){
        soundType=soundsPath+ "dan_dan_kokoro.mp3";
        ui->menuButton->setText("DragonBall");
}
}

void TimerWindow::addTimer() {
    int hours = ui->hourSpinBox->value();
    int minutes = ui->minSpinBox->value();
    int seconds = ui->secondsSpinBox->value();

    if (hours == 0 && minutes == 0 && seconds == 0) return; // Non aggiungere timer con 0 tempo

    TimerItem *timer = new TimerItem(this);
    timer->setMusicType(soundType);
    timer->showTypeSound(ui->menuButton->text());
    timer->setTitle(genericTitle);
    timer->setDuration(hours, minutes, seconds);
    timer->startTimer();
    QListWidgetItem *item = new QListWidgetItem(ui->timersList);
    item->setSizeHint(QSize(ui->timersList->width() - 10, 119));


    ui->timersList->addItem(item);
    ui->timersList->setItemWidget(item, timer);
    ui->timersList->scrollToItem(item);

    activeTimers.append(timer);
    genericTitle="Timer";
    connect(timer, &TimerItem::timerDeleted, this, &TimerWindow::removeTimer);

}

void TimerWindow::showTitleEditor() {
    TitleDIalog dialog(this);
    dialog.setTitle(genericTitle);
    if (dialog.exec() == QDialog::Accepted) {
        genericTitle = dialog.getTitle(); // Ottieni il titolo aggiornato
    }
}


