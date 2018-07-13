#ifndef MYWRITETHREAD_H
#define MYWRITETHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QBuffer>
#include <QTimer>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>

//#include "mystatic.h" 不应该再引用头文件了

class MyWriteThread : public QThread
{
    Q_OBJECT
public:
    explicit MyWriteThread(QObject *parent = 0);
    void getData();

signals:
    sig_hr(double);//将数据发送到主窗口
public slots:
//    do_getdata();

protected:
    void run();

private:
    QTimer *timer;
};

#endif // MYWRITETHREAD_H
