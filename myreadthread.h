#ifndef MYREADTHREAD_H
#define MYREADTHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QBuffer>
#include <QTimer>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>

//#include <mystatic.h>

//读线程
class MyReadThread : public QThread
{
    Q_OBJECT
public:
    explicit MyReadThread(QObject *parent = 0);

protected:
    void run();//线程处理函数（函数的执行体）
    //不能直接调用，通过对象的.start()方法间接调用此方法

signals:

public:


public slots:
};

#endif // MYREADTHREAD_H
