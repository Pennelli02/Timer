//
// Created by Asus on 09/03/2025.
//

#ifndef TIMER_CLOCKWINDOW_H
#define TIMER_CLOCKWINDOW_H

#include <QWidget>
#include "timerwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ClockWIndow; }
QT_END_NAMESPACE

class ClockWIndow : public QWidget {
Q_OBJECT

public:
    explicit ClockWIndow(QWidget *parent = nullptr);
    void testAccess_changeDateFormat() { changeDateFormat(); }
    void testAccess_changeClockFormat() { changeClockFormat(); }
    void testAccess_showTimerWindow() { showTimerWindow(); }
// getter per i test
    int getCurrentDateIndex() const;
    int getCurrentClockIndex() const;
    TimerWindow *getTimerWindow() const;
    QLabel* getClockLabel() const;
    QLabel* getDateLabel() const;
    QString getClockLabelText() const;
    QString getDateLabelText() const;

    ~ClockWIndow() override;
private slots:
    void showTime();
    void changeDateFormat();
    void changeClockFormat();
    void showTimerWindow();
    void showDate();
private:
    Ui::ClockWIndow *ui;
    int currentDateIndex;
    int currentClockIndex;
    TimerWindow *timerWindow;
    QStringList formats = {
            "dd/MM/yyyy",          // Formato 1: giorno/mese/anno
            "dddd, dd MMMM yyyy",  // Formato 2: giorno della settimana, giorno mese anno
            "yyyy-MM-dd",          // Formato 3: anno-mese-giorno (ISO)
            "dd MMMM yyyy"         // Formato 4: giorno mese anno (con nome del mese)
    };
};


#endif //TIMER_CLOCKWINDOW_H
