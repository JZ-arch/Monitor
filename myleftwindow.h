#ifndef MYLEFTWINDOW_H
#define MYLEFTWINDOW_H

#include <QWidget>
#include <QTimer>
#include "myreadthread.h"
#include "customheartrate.h"
#include "mywritethread.h"

//左边的绘图区域、包含7条绘图曲线
class MyLeftWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyLeftWindow(QWidget *parent = 0);

    void test_hr();
    void test_hx();//呼吸


    void send_hr1();
    void send_hr2();
    void send_hr3();
    void send_hr4();
    void send_hr5();
    void send_hr6();
    void send_hr7();
    void start_timer(int duration);

private:
    CustomHeartRate *heart_rate1;//第一条心率折线图
    CustomHeartRate *heart_rate2;
    CustomHeartRate *heart_rate3;
    CustomHeartRate *heart_rate4;
    CustomHeartRate *heart_rate5;//第五条呼吸曲线图
    CustomHeartRate *heart_rate6;
    CustomHeartRate *heart_rate7;

    MyReadThread *thread_read;//读取数据
    MyWriteThread *thread_write;//发送数据


protected:
    void paintEvent(QPaintEvent *event);

signals:
    void sig_hr1(double);//接收定时器的槽
    void sig_hr2(double);//接收定时器的槽
    void sig_hr3(double);//接收定时器的槽
    void sig_hr4(double);//接收定时器的槽
    void sig_hr5(double);//接收定时器的槽
    void sig_hr6(double);//接收定时器的槽
    void sig_hr7(double);//接收定时器的槽

public slots:

};

#endif // MYLEFTWINDOW_H
