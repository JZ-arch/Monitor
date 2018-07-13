#include "myleftwindow.h"

extern QList<QString> data_list;

MyLeftWindow::MyLeftWindow(QWidget *parent) : QWidget(parent)
{
    this->setMaximumHeight(760);//固定高度=800-40
    this->setFixedSize(800,760);//宽800，高760
    this->setAutoFillBackground(true);//设置窗体自动填充背景
    QVBoxLayout *layout_v = new QVBoxLayout(this);
    layout_v->setContentsMargins(0,0,0,0);
    layout_v->setMargin(0);
    layout_v->setSpacing(0);
    heart_rate1 = new CustomHeartRate(0,1,"X1","1mv",0,this);
    heart_rate2 = new CustomHeartRate(0,2,"X2","1mv",0,this);
    heart_rate3 = new CustomHeartRate(0,3,"","1mv",0,this);
    heart_rate4 = new CustomHeartRate(1,4,"Pleth","",0,this);
    heart_rate5 = new CustomHeartRate(1,5,"X1","",1,this);
    heart_rate6 = new CustomHeartRate(1,6,"X2","",0,this);
    heart_rate7 = new CustomHeartRate(1,7,"STATE","",0,this);
    thread_read = new MyReadThread(this);
    thread_write = new MyWriteThread(this);

    layout_v->setContentsMargins(0,0,0,0);//默认：各个控件之间上下左右会有11px的间距
    layout_v->addWidget(heart_rate1);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate2);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate3);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate4);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate5);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate6);
    layout_v->addStretch();
    layout_v->addWidget(heart_rate7);
    this->setLayout(layout_v);

    start_timer(30);//生成随机数据,30ms一次
    test_hr();
    test_hx();
    connect(this,&MyLeftWindow::sig_hr1,heart_rate1,&CustomHeartRate::receiveData);
    connect(this,&MyLeftWindow::sig_hr2,heart_rate2,&CustomHeartRate::receiveData);
    connect(this,&MyLeftWindow::sig_hr3,heart_rate3,&CustomHeartRate::receiveData);
    connect(this,&MyLeftWindow::sig_hr4,heart_rate4,&CustomHeartRate::receiveData);
    connect(thread_write,&MyWriteThread::sig_hr,heart_rate5,&CustomHeartRate::receiveData);
    connect(this,&MyLeftWindow::sig_hr6,heart_rate6,&CustomHeartRate::receiveData);
    connect(this,&MyLeftWindow::sig_hr7,heart_rate7,&CustomHeartRate::receiveData);
}

void MyLeftWindow::test_hr()
{

//    thread_read->start();
//    thread_write->start();
}


void MyLeftWindow::test_hx()
{

    thread_read->start();
    thread_write->start();
}

void MyLeftWindow::start_timer(int duration)
{
    QTimer *timer = new QTimer(this);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr1);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr2);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr3);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr4);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr5);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr6);
    connect(timer, QTimer::timeout, this, &MyLeftWindow::send_hr7);
    timer->start(duration);
}

void MyLeftWindow::send_hr1()
{
    //产生-700到1700的随机数
    //[low,up]: (rand()%(up-low+1)) + low
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr1(random);
}

void MyLeftWindow::send_hr2()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr2(random);
}

void MyLeftWindow::send_hr3()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr3(random);
}

void MyLeftWindow::send_hr4()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr4(random);
}

void MyLeftWindow::send_hr5()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr5(random);
}

void MyLeftWindow::send_hr6()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr6(random);
}

void MyLeftWindow::send_hr7()
{
    int random = (rand()%(1600-(-700)+1)) + (-700);
    emit sig_hr7(random);
}

void MyLeftWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(QColor(100, 100, 100 , 255));
    pen.setWidth(1);
    paint.setPen(pen);
    paint.drawLine(width()*1/40, height()/7, width(), height()/7);
    paint.drawLine(width()*1/40, height()*2/7, width(), height()*2/7);
    paint.drawLine(width()*1/40, height()*3/7, width(), height()*3/7);
    paint.drawLine(width()*1/40, height()*4/7, width(), height()*4/7);
    paint.drawLine(width()*1/40, height()*5/7, width(), height()*5/7);
    paint.drawLine(width()*1/40, height()*6/7, width(), height()*6/7);

}
