//
// Created by Asus on 10/03/2025.
//

#ifndef TIMER_TIMERITEM_H
#define TIMER_TIMERITEM_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class TimerItem; }
QT_END_NAMESPACE

class TimerItem : public QWidget {
Q_OBJECT



public:
    explicit TimerItem(QWidget *parent = nullptr);
    void setDuration(int hours, int minutes, int seconds);
    // metodi resi pubblici per i testing
    void startTimer();
    void pauseTimer();
    void repeatTimer();
    void removeTimer();
    QMessageBox* getActiveMessageBox() const;
    void setMediaPlayer(QMediaPlayer* player);
    void setMusicType(const QString &musicType);
    int getRemainingSeconds() const;
    ~TimerItem() override;
    void showTypeSound(const QString  &labelText);
    void setTitle(const QString &title);
    const QString &getMusicType() const;
    const QString &getTitle() const;
    bool isFinished1() const;
    bool isRunning1() const;

    QMediaPlayer *getPlayer() const;

signals:
    void timerDeleted(TimerItem *timer);
    void timerFinished(TimerItem *timer);

private slots:
    void playEndTimer();
    void updateDisplay();
    void handleTimerFinished();
    void mediaPlayerSetting();
    void on_startPauseButton_clicked();
    void on_deleteTimer_clicked();



private:
    QString title;
    QString musicType;
    Ui::TimerItem *ui;
    QTimer *timer;
    QTimer *deleteTimer;
    QMediaPlayer *player;
    int remainingSeconds;
    bool isRunning;
    bool isFinished;
    int initialSeconds;
    QMessageBox* activeMessageBox = nullptr;


};


#endif //TIMER_TIMERITEM_H
