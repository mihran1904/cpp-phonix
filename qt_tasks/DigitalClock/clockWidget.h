#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class ClockWidget : public QWidget {
    Q_OBJECT
public:
    explicit ClockWidget(QWidget *parent = nullptr);

private slots:
    void updateClock();
    void toggleTimeFormat();

private:
    QLabel *clockLabel;
    QPushButton *toggleButton;
    QTimer *timer;
    bool use12HourFormat;

    void updateTimeFormat();
};

#endif // CLOCKWIDGET_H
