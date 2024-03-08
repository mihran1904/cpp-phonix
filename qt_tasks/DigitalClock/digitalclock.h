#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QMainWindow>

#include <QTableWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class DigitalClock;
}
QT_END_NAMESPACE

class DigitalClock : public QMainWindow
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);
    ~DigitalClock();
private:
    //void onToggleBtnPush();
    //void timerEvent(QTimerEvent *event);

private:
    Ui::DigitalClock *ui;



};
#endif // DIGITALCLOCK_H
