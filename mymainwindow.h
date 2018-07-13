#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QWidget>
#include <mywindowtitle.h>
#include <myleftwindow.h>
#include <myrightwindow.h>

class MyMainWindow : public QWidget
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
private:
    MyWindowTitle *window_title;//标题栏
    MyLeftWindow *window_left;//左边画线区域
    MyRightWindow *window_right;//左边画线区域

};

#endif // MYMAINWINDOW_H
