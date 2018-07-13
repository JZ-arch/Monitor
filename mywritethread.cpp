#include "mywritethread.h"

extern QBuffer my_buf;
extern QList<QString> data_list;

MyWriteThread::MyWriteThread(QObject *parent) : QThread(parent)
{
//    timer = new QTimer(this);//报错
//    connect(timer, QTimer::timeout, this, &MyWriteThread::getData);
}

void MyWriteThread::run()
{
        timer = new QTimer();
        connect(timer, QTimer::timeout, this, &MyWriteThread::getData);
        timer->start(30);
        this->exec();
        //必须要加上事件循环exec()，并发出finished()信号。
}


//从缓存里面读取数据
void MyWriteThread::getData()
{
//    qDebug()<<"写线程";
    QString s;
    if(data_list.size()>=16){
        s = data_list.at(0);
        for(int i = 0;i<8;i++)
            data_list.removeFirst();
        qDebug()<<"定时数据："<<s;
    }

    emit sig_hr(s.toDouble()*3.5);

}


