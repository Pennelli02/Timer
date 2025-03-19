//
// Created by Asus on 19/03/2025.
//

#ifndef TIMER_TITLEDIALOG_H
#define TIMER_TITLEDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class TitleDIalog; }
QT_END_NAMESPACE

class TitleDIalog : public QDialog {
Q_OBJECT

public:
    explicit TitleDIalog(QWidget *parent = nullptr);

    ~TitleDIalog() override;
    const QString &getTitle() const;
    void setTitle(const QString &newTitle);

private slots:
    void saveTitle();
    void cancelDialog();

private:
    Ui::TitleDIalog *ui;
    QString title;

};


#endif //TIMER_TITLEDIALOG_H
