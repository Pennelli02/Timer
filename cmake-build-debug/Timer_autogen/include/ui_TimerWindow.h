/********************************************************************************
** Form generated from reading UI file 'timerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWINDOW_H
#define UI_TIMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerWindow
{
public:
    QSpinBox *hourSpinBox;
    QLabel *hoursLabel;
    QSpinBox *minSpinBox;
    QLabel *minutesLabel;
    QSpinBox *secondsSpinBox;
    QLabel *secondsLabel;
    QPushButton *startTimer;
    QListWidget *timersList;

    void setupUi(QWidget *TimerWindow)
    {
        if (TimerWindow->objectName().isEmpty())
            TimerWindow->setObjectName("TimerWindow");
        TimerWindow->resize(1032, 722);
        hourSpinBox = new QSpinBox(TimerWindow);
        hourSpinBox->setObjectName("hourSpinBox");
        hourSpinBox->setGeometry(QRect(90, 60, 81, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        hourSpinBox->setFont(font);
        hourSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hourSpinBox->setMaximum(23);
        hoursLabel = new QLabel(TimerWindow);
        hoursLabel->setObjectName("hoursLabel");
        hoursLabel->setGeometry(QRect(90, 20, 81, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        hoursLabel->setFont(font1);
        hoursLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        minSpinBox = new QSpinBox(TimerWindow);
        minSpinBox->setObjectName("minSpinBox");
        minSpinBox->setGeometry(QRect(210, 60, 81, 61));
        minSpinBox->setFont(font);
        minSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        minSpinBox->setMaximum(59);
        minutesLabel = new QLabel(TimerWindow);
        minutesLabel->setObjectName("minutesLabel");
        minutesLabel->setGeometry(QRect(210, 20, 81, 31));
        minutesLabel->setFont(font1);
        minutesLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        secondsSpinBox = new QSpinBox(TimerWindow);
        secondsSpinBox->setObjectName("secondsSpinBox");
        secondsSpinBox->setGeometry(QRect(330, 60, 81, 61));
        secondsSpinBox->setFont(font);
        secondsSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        secondsSpinBox->setMinimum(0);
        secondsSpinBox->setMaximum(59);
        secondsLabel = new QLabel(TimerWindow);
        secondsLabel->setObjectName("secondsLabel");
        secondsLabel->setGeometry(QRect(330, 20, 81, 31));
        secondsLabel->setFont(font1);
        secondsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        startTimer = new QPushButton(TimerWindow);
        startTimer->setObjectName("startTimer");
        startTimer->setGeometry(QRect(480, 60, 81, 61));
        QFont font2;
        font2.setPointSize(12);
        startTimer->setFont(font2);
        timersList = new QListWidget(TimerWindow);
        timersList->setObjectName("timersList");
        timersList->setGeometry(QRect(40, 170, 911, 361));

        retranslateUi(TimerWindow);

        QMetaObject::connectSlotsByName(TimerWindow);
    } // setupUi

    void retranslateUi(QWidget *TimerWindow)
    {
        TimerWindow->setWindowTitle(QCoreApplication::translate("TimerWindow", "TimerWindow", nullptr));
        hoursLabel->setText(QCoreApplication::translate("TimerWindow", "Hours", nullptr));
        minutesLabel->setText(QCoreApplication::translate("TimerWindow", "Minutes", nullptr));
        secondsLabel->setText(QCoreApplication::translate("TimerWindow", "Seconds", nullptr));
        startTimer->setText(QCoreApplication::translate("TimerWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerWindow: public Ui_TimerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOW_H
