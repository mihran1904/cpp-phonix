#include "clockWidget.h"
#include <QDateTime>
#include <QVBoxLayout>

ClockWidget::ClockWidget(QWidget *parent) : QWidget(parent), use12HourFormat(true) {
    clockLabel = new QLabel(this);
    clockLabel->setAlignment(Qt::AlignCenter);
    clockLabel->setStyleSheet("font-size: 30px");
    toggleButton = new QPushButton("Toggle Format", this);
    connect(toggleButton, &QPushButton::clicked, this, &ClockWidget::toggleTimeFormat);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClockWidget::updateClock);
    timer->start(1000); // Update every second

    updateTimeFormat();
    updateClock();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(clockLabel);
    layout->addWidget(toggleButton);
    setLayout(layout);
}

void ClockWidget::updateClock() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = (use12HourFormat) ? currentTime.toString("hh:mm:ss AP") : currentTime.toString("HH:mm:ss");
    clockLabel->setText(timeString);
}

void ClockWidget::toggleTimeFormat() {
    use12HourFormat = !use12HourFormat;
    updateTimeFormat();
    updateClock();
}

void ClockWidget::updateTimeFormat() {
    toggleButton->setText(use12HourFormat ? "Toggle to 24-hour" : "Toggle to 12-hour");
}
