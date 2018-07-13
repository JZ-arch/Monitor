#include "ciclebuffer.h"

CicleBuffer::CicleBuffer()
{
//    QList data_list;
}

bool CicleBuffer::writeData()
{
    if(data_list.size()>=500)
        return false;
    else
        return true;
}

QString CicleBuffer::readData()
{
    QString s = data_list.at(0);
    data_list.removeAt(0);
}
