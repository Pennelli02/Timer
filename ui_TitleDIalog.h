/********************************************************************************
** Form generated from reading UI file 'TitleDIalog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEDIALOG_H
#define UI_TITLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TitleDIalog
{
public:
    QLabel *DialogTitle;
    QLineEdit *titleEdit;
    QPushButton *goBackButton;
    QPushButton *saveButton;

    void setupUi(QDialog *TitleDIalog)
    {
        if (TitleDIalog->objectName().isEmpty())
            TitleDIalog->setObjectName("TitleDIalog");
        TitleDIalog->resize(931, 220);
        DialogTitle = new QLabel(TitleDIalog);
        DialogTitle->setObjectName("DialogTitle");
        DialogTitle->setGeometry(QRect(210, 10, 541, 81));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        DialogTitle->setFont(font);
        DialogTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        titleEdit = new QLineEdit(TitleDIalog);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(150, 90, 641, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        titleEdit->setFont(font1);
        titleEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        goBackButton = new QPushButton(TitleDIalog);
        goBackButton->setObjectName("goBackButton");
        goBackButton->setGeometry(QRect(40, 150, 201, 51));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        goBackButton->setFont(font2);
        saveButton = new QPushButton(TitleDIalog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(690, 150, 211, 51));
        saveButton->setFont(font2);

        retranslateUi(TitleDIalog);

        QMetaObject::connectSlotsByName(TitleDIalog);
    } // setupUi

    void retranslateUi(QDialog *TitleDIalog)
    {
        TitleDIalog->setWindowTitle(QCoreApplication::translate("TitleDIalog", "TitleDIalog", nullptr));
        DialogTitle->setText(QCoreApplication::translate("TitleDIalog", "Write your Title", nullptr));
        goBackButton->setText(QCoreApplication::translate("TitleDIalog", "Cancel", nullptr));
        saveButton->setText(QCoreApplication::translate("TitleDIalog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TitleDIalog: public Ui_TitleDIalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEDIALOG_H
