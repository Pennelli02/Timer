/********************************************************************************
** Form generated from reading UI file 'timeritem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERITEM_H
#define UI_TIMERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerItem
{
public:
    QLabel *timerLabel;
    QPushButton *startPauseButton;
    QPushButton *deleteTimer;
    QLabel *soundLabel;

    void setupUi(QWidget *TimerItem)
    {
        if (TimerItem->objectName().isEmpty())
            TimerItem->setObjectName("TimerItem");
        TimerItem->resize(882, 125);
        timerLabel = new QLabel(TimerItem);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setGeometry(QRect(30, 10, 321, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        timerLabel->setFont(font);
        startPauseButton = new QPushButton(TimerItem);
        startPauseButton->setObjectName("startPauseButton");
        startPauseButton->setGeometry(QRect(310, 30, 101, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        startPauseButton->setFont(font1);
        deleteTimer = new QPushButton(TimerItem);
        deleteTimer->setObjectName("deleteTimer");
        deleteTimer->setGeometry(QRect(500, 30, 101, 61));
        deleteTimer->setFont(font1);
        soundLabel = new QLabel(TimerItem);
        soundLabel->setObjectName("soundLabel");
        soundLabel->setGeometry(QRect(650, 30, 181, 61));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        soundLabel->setFont(font2);
        soundLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TimerItem);

        QMetaObject::connectSlotsByName(TimerItem);
    } // setupUi

    void retranslateUi(QWidget *TimerItem)
    {
        TimerItem->setWindowTitle(QCoreApplication::translate("TimerItem", "TimerItem", nullptr));
        timerLabel->setText(QCoreApplication::translate("TimerItem", "Timer clock", nullptr));
        startPauseButton->setText(QCoreApplication::translate("TimerItem", "Pause", nullptr));
        deleteTimer->setText(QCoreApplication::translate("TimerItem", "Delete", nullptr));
        soundLabel->setText(QCoreApplication::translate("TimerItem", "sound", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerItem: public Ui_TimerItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERITEM_H
