#ifndef STOPWATCHWIDGET_H
#define STOPWATCHWIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
class StopwatchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StopwatchWidget(QWidget *parent = nullptr);
    ~StopwatchWidget();

private slots:
    void startStopButtonClicked();
    void resetBtnClicked();

private:
    QTime currentTime;
    QTimer timer;
    QPushButton *startStopButton;
    QPushButton *resetBtn;
    QVBoxLayout *layout;
    QLabel *display_label;

    void updateDisplay();
};

#endif // STOPWATCHWIDGET_H
