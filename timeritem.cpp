//
// Created by Asus on 10/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimerItem.h" resolved

#include <QSoundEffect>
#include "timeritem.h"
#include "ui_TimerItem.h"

TimerItem::TimerItem(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::TimerItem),
        remainingSeconds(0),
        isRunning(false), isFinished(false){

    ui->setupUi(this);
    timer = new QTimer(this);
    deleteTimer = new QTimer(this);  // Timer per rimuovere l'elemento dopo la fine
    connect(timer, &QTimer::timeout, this, &TimerItem::updateDisplay);
    connect(deleteTimer, &QTimer::timeout, this, &TimerItem::removeTimer);

}

TimerItem::~TimerItem() {
    delete ui;
    delete player;
    delete activeMessageBox;
    delete timer;
    delete deleteTimer;
}

void TimerItem::setDuration(int hours, int minutes, int seconds) {
    remainingSeconds = (hours * 3600) + (minutes * 60) + seconds;
    initialSeconds = remainingSeconds;
    updateDisplay();
}

void TimerItem::startTimer() {
    if (remainingSeconds > 0 && !isRunning) {
        timer->start(1000);
        isRunning = true;
        ui->startPauseButton->setText("Pause");
        mediaPlayerSetting();
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
        startTimer();

        int h = remainingSeconds / 3600;
        int m = (remainingSeconds % 3600) / 60;
        int s = remainingSeconds % 60;
        ui->timerLabel->setText(QString("%1:%2:%3")
                                        .arg(h, 2, 10, QChar('0'))
                                        .arg(m, 2, 10, QChar('0'))
                                        .arg(s, 2, 10, QChar('0')));

            remainingSeconds--;


    } else {
        handleTimerFinished();
    }
}

void TimerItem::handleTimerFinished() {
    timer->stop();
    isRunning = false;
    isFinished= true;
    ui->startPauseButton->setText("Repeat");

    // Mostra il messaggio di avviso
    ui->timerLabel->setText("TIMER SCADUTO!");
    ui->timerLabel->setStyleSheet("color: red; font-weight: bold;");
    playEndTimer();
    // Mostra un pop-up di avviso
    QMessageBox *msgBox =new QMessageBox;
    msgBox->setWindowTitle(title);
    msgBox->setText("Il timer è terminato!");
    msgBox->setStyleSheet("font-size:20px; font-weight: bold;");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    // Blocca il suono quando il messaggio viene chiuso
    QObject::connect(msgBox, &QMessageBox::finished, this, [=](int) {
        if (player) {
            player->stop();  // Stop the sound
        }
        // Dopo 5 secondi il timer verrà rimosso
        deleteTimer->start(5000);
        activeMessageBox = nullptr;  // ci si assicura che non ci siano memory leak
    });


    msgBox->open();

    // Riproduce un suono di avviso non personalizzabile di sistema
    activeMessageBox=msgBox;

    emit timerFinished();

}

void TimerItem::removeTimer() {
    emit timerDeleted(this);
}

void TimerItem::on_startPauseButton_clicked() {
    if(isFinished)
        repeatTimer();
    else{
        if (isRunning)
            pauseTimer();
        else
            startTimer();
    }
}

void TimerItem::on_deleteTimer_clicked() {
    emit timerDeleted(this);
}

int TimerItem::getRemainingSeconds() const {
    return remainingSeconds;
}

void TimerItem::repeatTimer() {
    deleteTimer->stop(); // Ferma la cancellazione
    remainingSeconds = initialSeconds;// Ripristina il tempo iniziale
    ui->timerLabel->setText("...waiting...");
    ui->timerLabel->setStyleSheet("color: white");
    startTimer();
    isFinished= false;
}

void TimerItem::playEndTimer() {
    player->play();
}

void TimerItem::setMusicType(const QString &musicType) {
    TimerItem::musicType = musicType;
}

void TimerItem::setTitle(const QString &title) {
    TimerItem::title=title;
}

void TimerItem::showTypeSound(const QString &labelText) {
    ui->soundLabel->setText(labelText);
}

const QString &TimerItem::getTitle() const {
    return title;
}

const QString &TimerItem::getMusicType() const {
    return musicType;
}

bool TimerItem::isRunning1() const {
    return isRunning;
}

bool TimerItem::isFinished1() const {
    return isFinished;
}

void TimerItem::setMediaPlayer(QMediaPlayer *player) {
    this->player = player;
}

QMessageBox *TimerItem::getActiveMessageBox() const {
    return activeMessageBox;
}

QMediaPlayer *TimerItem::getPlayer() const {
    return player;
}

void TimerItem::mediaPlayerSetting(){
    player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(musicType));

    audioOutput->setVolume(1.0);
}

