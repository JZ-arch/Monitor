#include "myreadthread.h"

//读线程
//主要做的操作：从TXT文件中不断读取信号，并将读取到的数据 放到 数据缓冲池（QBuffer）

extern QBuffer my_buf;
extern QList<QString> data_list;
MyReadThread::MyReadThread(QObject *parent) : QThread(parent)
{

}


//30ms读取一行数据
void MyReadThread::run()
{
    //用buf来构造一个缓存，
    QString path = ":/data/hr.txt";
    QFile file(path);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"打开文件失败！";
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        if(data_list.size()>=1000)
        {
            if(this->isRunning()){
//                this->wait(1000);
//                qDebug()<<"读线程等待一秒";
                continue;
            }
        }

        QString lineString = in.readLine();
        data_list.append(lineString);
//        qDebug()<<""<<data_list(0);

    }
}
