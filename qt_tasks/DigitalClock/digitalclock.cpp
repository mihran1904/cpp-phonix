#include "digitalclock.h"
#include "ui_digitalclock.h"
#include "clockWidget.h"
#include "stopwatchWidget.h"
#include <QTabWidget>
#include <QVBoxLayout>
DigitalClock::DigitalClock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DigitalClock)
{
    ui->setupUi(this);
    QTabWidget *tabWidget = new QTabWidget(this);

    ClockWidget *clockWidget = new ClockWidget(tabWidget);
    StopwatchWidget *stopwatchWidget = new StopwatchWidget(tabWidget);

    tabWidget->addTab(clockWidget, "Clock");
    tabWidget->addTab(stopwatchWidget, "Stopwatch");

    setCentralWidget(tabWidget);

}




DigitalClock::~DigitalClock()
{
    //killTimer(timerId);
    delete ui;
}
