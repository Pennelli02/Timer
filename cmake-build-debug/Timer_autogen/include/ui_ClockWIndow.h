/********************************************************************************
** Form generated from reading UI file 'clockwindow.ui'
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
    QPushButton *openTimer;
    QPushButton *clockFormat;
    QPushButton *openAllarm;

    void setupUi(QWidget *ClockWIndow)
    {
        if (ClockWIndow->objectName().isEmpty())
            ClockWIndow->setObjectName("ClockWIndow");
        ClockWIndow->resize(1194, 597);
        DateLabel = new QLabel(ClockWIndow);
        DateLabel->setObjectName("DateLabel");
        DateLabel->setGeometry(QRect(200, 30, 801, 101));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        DateLabel->setFont(font);
        DateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClockLabel = new QLabel(ClockWIndow);
        ClockLabel->setObjectName("ClockLabel");
        ClockLabel->setGeometry(QRect(130, 180, 901, 181));
        QFont font1;
        font1.setPointSize(60);
        font1.setBold(true);
        ClockLabel->setFont(font1);
        ClockLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        changeFormat = new QPushButton(ClockWIndow);
        changeFormat->setObjectName("changeFormat");
        changeFormat->setGeometry(QRect(30, 490, 181, 61));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        changeFormat->setFont(font2);
        openTimer = new QPushButton(ClockWIndow);
        openTimer->setObjectName("openTimer");
        openTimer->setGeometry(QRect(950, 490, 201, 61));
        openTimer->setFont(font2);
        clockFormat = new QPushButton(ClockWIndow);
        clockFormat->setObjectName("clockFormat");
        clockFormat->setGeometry(QRect(250, 490, 181, 61));
        clockFormat->setFont(font2);
        openAllarm = new QPushButton(ClockWIndow);
        openAllarm->setObjectName("openAllarm");
        openAllarm->setGeometry(QRect(700, 490, 201, 61));
        openAllarm->setFont(font2);

        retranslateUi(ClockWIndow);

        QMetaObject::connectSlotsByName(ClockWIndow);
    } // setupUi

    void retranslateUi(QWidget *ClockWIndow)
    {
        ClockWIndow->setWindowTitle(QCoreApplication::translate("ClockWIndow", "ClockWIndow", nullptr));
        DateLabel->setText(QCoreApplication::translate("ClockWIndow", "Date", nullptr));
        ClockLabel->setText(QCoreApplication::translate("ClockWIndow", "Clock", nullptr));
        changeFormat->setText(QCoreApplication::translate("ClockWIndow", "Format Date ", nullptr));
        openTimer->setText(QCoreApplication::translate("ClockWIndow", "Start Timer", nullptr));
        clockFormat->setText(QCoreApplication::translate("ClockWIndow", "Format Clock", nullptr));
        openAllarm->setText(QCoreApplication::translate("ClockWIndow", "Start Allarm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWIndow: public Ui_ClockWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWINDOW_H
