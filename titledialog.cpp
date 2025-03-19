//
// Created by Asus on 19/03/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TitleDIalog.h" resolved

#include "titledialog.h"
#include "ui_TitleDIalog.h"


TitleDIalog::TitleDIalog(QWidget *parent) :
         QDialog(parent), ui(new Ui::TitleDIalog) {
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &TitleDIalog::saveTitle);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TitleDIalog::cancelDialog);
}

TitleDIalog::~TitleDIalog() {
    delete ui;
}

const QString &TitleDIalog::getTitle() const {
    return title;
}

void TitleDIalog::saveTitle() {
    title = ui->titleEdit->text(); // Salva il titolo inserito
    accept(); // Chiude il dialogo e ritorna QDialog::Accepted
}
void TitleDIalog::cancelDialog() {
    reject(); // Chiude il dialogo senza salvare (QDialog::Rejected)
}
void TitleDIalog::setTitle(const QString &newTitle) {
    title = newTitle;
    ui->titleEdit->setText(title);  // Mostra il titolo corrente nel campo di testo
}
