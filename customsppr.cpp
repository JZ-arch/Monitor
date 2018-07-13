#include "customsppr.h"

CustomSpPr::CustomSpPr(QWidget *parent) : QWidget(parent)
{
     this->setFixedSize(400,760*1/7);
     sp_left1 = new QLabel(this);
     sp_left2 = new QLabel(this);
     sp_left3 = new QLabel(this);
     sp_percent = new QLabel(this);
     sp_content = new QLabel(this);

     pr_left = new QLabel(this);
     pr_right = new QLabel(this);
     pr_content = new QLabel(this);

     this->setFixedSize(400,760*1/7);
     QPalette palette1 = this->palette(); // 获取调色板
     QPalette palette2 = this->palette(); // 获取调色板
     palette1.setColor(QPalette::WindowText, QColor("#13D9D8")); // 亮蓝
     palette2.setColor(QPalette::WindowText, QColor("#1F9694")); // 暗蓝
     QFont font1("Microsoft YaHei", 15, QFont::Medium);
     QFont font2("Microsoft YaHei", 50, QFont::Medium);

     sp_left1->setText("SpO2");
     sp_left2->setText("100");
     sp_left3->setText("90");
     sp_percent->setText("%");
     pr_left->setText("PR");
     pr_right->setText("bpm");
     sp_content->setText("98");
     pr_content->setText("85");

     sp_left1->setFont(font1);
     sp_left2->setFont(font1);
     sp_left3->setFont(font1);
     sp_percent->setFont(font1);
     pr_left->setFont(font1);
     pr_right->setFont(font1);
     sp_content->setFont(font2);
     pr_content->setFont(font2);

     sp_left1->setPalette(palette1);
     sp_left2->setPalette(palette2);
     sp_left3->setPalette(palette2);
     sp_percent->setPalette(palette2);
     pr_left->setPalette(palette1);
     pr_right->setPalette(palette2);
     sp_content->setPalette(palette1);
     pr_content->setPalette(palette1);

     sp_left1->move(5,2);
     sp_left2->move(8,30);
     sp_left3->move(8,75);
     sp_percent->move(180,2);
     pr_left->move(210,2);
     pr_right->move(width()-60,2);
     sp_content->move(80,20);
     pr_content->move(260,20);
}


void  CustomSpPr::paintEvent(QPaintEvent *event)
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
