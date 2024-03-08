#include "stopwatchWidget.h"

StopwatchWidget::StopwatchWidget(QWidget *parent)
    : QWidget(parent)
{
    currentTime = QTime(0, 0);
    display_label = new QLabel("00:00:00:000");
    display_label->setStyleSheet("font-size: 30px");
    startStopButton = new QPushButton("Start");
    layout = new QVBoxLayout(this);
    layout->addWidget(display_label);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(30);
    layout->addWidget(startStopButton);
    resetBtn = new QPushButton("Reset");
    layout->addWidget(resetBtn);
    connect(resetBtn,&QPushButton::clicked,this,&StopwatchWidget::resetBtnClicked);
    connect(startStopButton, &QPushButton::clicked, this, &StopwatchWidget::startStopButtonClicked);
    connect(&timer, &QTimer::timeout, this, &StopwatchWidget::updateDisplay);
}

StopwatchWidget::~StopwatchWidget()
{
}
void StopwatchWidget::resetBtnClicked() {
    timer.stop();
    currentTime = QTime(0,0,0,0);
    updateDisplay();
    startStopButton->setText("Start");
    display_label->setText("00:00:00:000");
}
void StopwatchWidget::startStopButtonClicked()
{
    if (timer.isActive()) {
        timer.stop();
        startStopButton->setText("Start");
    } else {
        timer.start(0);  // Update every second
        startStopButton->setText("Stop");
    }
}

void StopwatchWidget::updateDisplay()
{
    currentTime = currentTime.addMSecs(1);
    // Update your display here with the current time
    display_label->setText(currentTime.toString("hh:mm:ss:zzz"));
}
