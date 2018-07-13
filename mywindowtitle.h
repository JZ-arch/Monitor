#ifndef MYWINDOWTITLE_H
#define MYWINDOWTITLE_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QPalette>
#include <QFont>
#include <QDateTime>
#include <QTimer>
#include <QLayout>
#include <QPixmap>

class MyWindowTitle : public QWidget
{
    Q_OBJECT
private:
     QLabel *tv_time; //日期和时间
     QLabel *tv_name; // 名字
     QLabel *img_alarm; //闹钟图标
     QLabel *img_network; //网络
     QLabel *img_signal; //信号图标
public:
    explicit MyWindowTitle(QWidget *parent = 0);

signals:

public slots:
    void UpdateTime();
};

#endif // MYWINDOWTITLE_H
