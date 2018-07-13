#include "customtemp.h"

CustomTemp::CustomTemp(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(150,760*1/7);
    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    QPalette palette3 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#FEFEFE")); // 亮白
    palette2.setColor(QPalette::WindowText, QColor("#FF5007")); // 红色
    palette3.setColor(QPalette::WindowText, QColor("#939395")); // 暗白
    QFont font1("Microsoft YaHei", 16, QFont::Medium);//大
    QFont font2("Microsoft YaHei", 14, QFont::Medium);//小
    tv_left1 = new QLabel(this);
    tv_left2 = new QLabel(this);
    tv_left3 = new QLabel(this);
    tv_right1 = new QLabel(this);
    tv_right2 = new QLabel(this);
    tv_right3 = new QLabel(this);

    tv_left1->setText("TEMP");
    tv_left2->setText("37.3℃");
    tv_left3->setText("37.1℃");
    tv_right1->setText("TIME");
    tv_right2->setText("11:06");
    tv_right3->setText("11:02");

    tv_left1->setPalette(palette1);
    tv_left2->setPalette(palette2);
    tv_left3->setPalette(palette3);
    tv_right1->setPalette(palette1);
    tv_right2->setPalette(palette2);
    tv_right3->setPalette(palette3);

    tv_left1->setFont(font1);
    tv_left2->setFont(font1);
    tv_left3->setFont(font2);
    tv_right1->setFont(font1);
    tv_right2->setFont(font1);
    tv_right3->setFont(font2);

    tv_left1->move(5,2);
    tv_left2->move(5,40);
    tv_left3->move(5,80);
    tv_right1->move(85,2);
    tv_right2->move(85,40);
    tv_right3->move(85,80);
}

void CustomTemp::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(100, 100, 100 , 255));
    painter.setPen(pen);
    QRect rect = this->rect();
    rect.setWidth(rect.width());
    rect.setHeight(rect.height());
    painter.drawRoundedRect(rect, 6, 6);
}
