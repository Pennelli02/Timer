//
// Created by Asus on 09/03/2025.
//

#ifndef TIMER_CLOCKWINDOW_H
#define TIMER_CLOCKWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ClockWIndow; }
QT_END_NAMESPACE

class ClockWIndow : public QWidget {
Q_OBJECT

public:
    explicit ClockWIndow(QWidget *parent = nullptr);

    ~ClockWIndow() override;
private slots:
    void showTime();
    void changeDateFormat();
    void changeClockFormat();

private:
    Ui::ClockWIndow *ui;
    int currentDateIndex;
    int currentClockIndex;
};


#endif //TIMER_CLOCKWINDOW_H
