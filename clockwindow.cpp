//
// Created by Asus on 09/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClockWIndow.h" resolved

#include "clockwindow.h"
#include "ui_ClockWIndow.h"
#include <QTimer>
#include <QDateTime>

ClockWIndow::ClockWIndow(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClockWIndow), currentFormatIndex(0) {
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClockWIndow::showTime);
    timer->start(1000);  // Aggiorna ogni secondo

    connect(ui->changeFormat, &QPushButton::clicked, this, &ClockWIndow::changeDateFormat);
    changeDateFormat();
}

ClockWIndow::~ClockWIndow() {
    delete ui;
}

void ClockWIndow::showTime() {
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    if((time.second()%2)==0){
        timeText[3]=' ';
        timeText[8]=' ';
    }
    ui->ClockLabel->setText(timeText);
}

void ClockWIndow::changeDateFormat() {
    QDateTime date = QDateTime::currentDateTime();
    QString dateText;

    // Lista di formati di data
    QStringList formats = {
            "dd/MM/yyyy",          // Formato 1: giorno/mese/anno
            "dddd, dd MMMM yyyy",  // Formato 2: giorno della settimana, giorno mese anno
            "yyyy-MM-dd",          // Formato 3: anno-mese-giorno (ISO)
            "dd MMMM yyyy"         // Formato 4: giorno mese anno (con nome del mese)
    };

    // Seleziona il formato corrente
    dateText = date.toString(formats[currentFormatIndex]);

    // Aggiorna l'etichetta con la data formattata
    ui->DateLabel->setText(dateText);

    // Passa al formato successivo
    currentFormatIndex = (currentFormatIndex + 1) % formats.size();

}
