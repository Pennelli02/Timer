/********************************************************************************
** Form generated from reading UI file 'ClockWIndow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWINDOW_H
#define UI_CLOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockWIndow
{
public:
    QLabel *DateLabel;
    QLabel *ClockLabel;
    QPushButton *changeFormat;
    QPushButton *pushButton;
    QPushButton *clockFormat;

    void setupUi(QWidget *ClockWIndow)
    {
        if (ClockWIndow->objectName().isEmpty())
            ClockWIndow->setObjectName("ClockWIndow");
        ClockWIndow->resize(1111, 488);
        DateLabel = new QLabel(ClockWIndow);
        DateLabel->setObjectName("DateLabel");
        DateLabel->setGeometry(QRect(300, 20, 521, 71));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        DateLabel->setFont(font);
        DateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClockLabel = new QLabel(ClockWIndow);
        ClockLabel->setObjectName("ClockLabel");
        ClockLabel->setGeometry(QRect(130, 160, 851, 111));
        QFont font1;
        font1.setPointSize(50);
        font1.setBold(true);
        ClockLabel->setFont(font1);
        ClockLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        changeFormat = new QPushButton(ClockWIndow);
        changeFormat->setObjectName("changeFormat");
        changeFormat->setGeometry(QRect(40, 350, 181, 61));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        changeFormat->setFont(font2);
        pushButton = new QPushButton(ClockWIndow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 350, 201, 61));
        pushButton->setFont(font2);
        clockFormat = new QPushButton(ClockWIndow);
        clockFormat->setObjectName("clockFormat");
        clockFormat->setGeometry(QRect(260, 350, 181, 61));
        clockFormat->setFont(font2);

        retranslateUi(ClockWIndow);

        QMetaObject::connectSlotsByName(ClockWIndow);
    } // setupUi

    void retranslateUi(QWidget *ClockWIndow)
    {
        ClockWIndow->setWindowTitle(QCoreApplication::translate("ClockWIndow", "ClockWIndow", nullptr));
        DateLabel->setText(QCoreApplication::translate("ClockWIndow", "Date", nullptr));
        ClockLabel->setText(QCoreApplication::translate("ClockWIndow", "Clock", nullptr));
        changeFormat->setText(QCoreApplication::translate("ClockWIndow", "Format Date ", nullptr));
        pushButton->setText(QCoreApplication::translate("ClockWIndow", "Start Timer", nullptr));
        clockFormat->setText(QCoreApplication::translate("ClockWIndow", "Format Clock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWIndow: public Ui_ClockWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWINDOW_H
