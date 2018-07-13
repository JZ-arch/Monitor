#ifndef CICLEBUFFER_H
#define CICLEBUFFER_H
#define _SIZE_ = 500;//缓冲区大小为500个数据

#include <QList>
#include <QString>


//圆形缓冲池，采用队列（FIFO）
QList<QString> data_list;
class CicleBuffer
{
public:
    CicleBuffer();
    bool isFull();//判断缓冲池是否为满
    bool isEmpty();//判断缓冲池是否为空

    bool writeData();//写数据
    QString readData();//读数据

private:

};

#endif // CICLEBUFFER_H
