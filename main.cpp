#include <iostream>

#include "clockwindow.h"
#include <QApplication>
#include <QStyleFactory>
int main(int argc, char *argv[])
{
    // parametrizzazione dell'applicazione con metodi statici
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    // costruzione dell'oggetto applicazione, che gestisce anche
    // gli argomenti da riga di comando
    QApplication a(argc, argv);
    // inizializzazione della finestra principale
    ClockWIndow w;
    w.show();
    // punto di inizio dell'event loop del thread GUI (o thread principale)
    return a.exec();
}
