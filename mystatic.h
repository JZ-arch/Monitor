#ifndef MYSTATIC_H
#define MYSTATIC_H

#include <QByteArray>
#include <QBuffer>

//全局类、用来存放全局变量
//.h里面声名，.cpp文件里面定义
QBuffer my_buf;
class MyStatic
{
public:
    MyStatic();

};

#endif // MYSTATIC_H
