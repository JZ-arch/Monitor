#include "mywindowtitle.h"

MyWindowTitle::MyWindowTitle(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);//水平布局
    this->setFixedSize(1280,40);
    this->setAutoFillBackground(true);//设置窗体自动填充背景
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor (58,58,58,255));
    this->setPalette(pal);

    QFont font_time("Microsoft YaHei", 18, QFont::Normal);
    //设置时间
    tv_time = new QLabel(this);
    tv_time->resize(300,36);
    tv_time->setFont(font_time);
    tv_time->setStyleSheet("QLabel{color: white}");//白色
    tv_time->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    // 定时器刷新时间
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer->start(500);

    //设置名字
    QFont font_name("Microsoft YaHei", 16, QFont::Normal);
    tv_name = new QLabel(this);
    tv_name->setText("李佳伟");
    tv_name->resize(100,36);
    tv_name->setFont(font_name);
    tv_name->setStyleSheet("QLabel{color: white}");

    //设置三个图标
    QPixmap pixmap;
    pixmap.load(":/images/statusbar/alarm.png");
    img_alarm = new QLabel(this);
    img_alarm->setFixedSize(26,26);
    img_alarm->setPixmap(pixmap);
    img_alarm->setScaledContents(true);//图片填充满整个控件（图片自适应）
    img_alarm->setAlignment(Qt::AlignCenter);//居中显示

    pixmap.load(":/images/statusbar/network.png");
    img_network = new QLabel(this);
    img_network->setFixedSize(26,26);
    img_network->setPixmap(pixmap);
    img_network->setScaledContents(true);//图片填充满整个控件（图片自适应）
    img_network->setAlignment(Qt::AlignCenter);//居中显示

    pixmap.load(":/images/statusbar/signal.png");
    img_signal = new QLabel(this);
    img_signal->setFixedSize(26,26);
    img_signal->setPixmap(pixmap);
    img_signal->setScaledContents(true);//图片填充满整个控件（图片自适应）
    img_signal->setAlignment(Qt::AlignCenter);//居中显示


    layout->setAlignment(Qt::AlignVCenter);
    layout->addSpacerItem(new QSpacerItem(20,20));//添加间距
    layout->addWidget(tv_time);
    layout->addSpacerItem(new QSpacerItem(20,20));
    layout->addWidget(tv_name);
    layout->addStretch();//添加弹簧
    layout->addWidget(img_alarm);
    layout->addSpacerItem(new QSpacerItem(20,20));
    layout->addWidget(img_network);
    layout->addSpacerItem(new QSpacerItem(20,20));
    layout->addWidget(img_signal);

    this->setLayout(layout);


}


void MyWindowTitle::UpdateTime(){
    tv_time->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
}
