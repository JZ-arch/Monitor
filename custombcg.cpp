#include "custombcg.h"

CustomBCG::CustomBCG(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(200,760*2/7);
    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#00FF00")); // 亮绿
    palette2.setColor(QPalette::WindowText, QColor("#158942")); // 暗绿
    QFont font1("Microsoft YaHei", 16, QFont::Medium);
    QFont font2("Microsoft YaHei", 80, QFont::Medium);
    label_ul = new QLabel(this);
    label_ru = new QLabel(this);
    label_top = new QLabel(this);
    label_bottom = new QLabel(this);
    label_tt = new QLabel(this);

    label_ul->setText("BCG");
    label_ru->setText("bpm");
    label_top->setText("120");
    label_bottom->setText("50");
    label_tt->setText("85");

    label_ul->setPalette(palette1);
    label_ru->setPalette(palette2);
    label_top->setPalette(palette2);
    label_bottom->setPalette(palette2);
    label_tt->setPalette(palette1);

    label_ul->setFont(font1);
    label_ru->setFont(font1);
    label_top->setFont(font1);
    label_bottom->setFont(font1);
    label_tt->setFont(font2);

    label_ul->setGeometry(10,10,200,30);
    label_ru->setGeometry(width()-60,10,200,30);
    label_top->setGeometry(10,70,200,30);
    label_bottom->setGeometry(10,150,200,30);
    label_tt->setGeometry(60,75,300,100);

}


void CustomBCG::paintEvent(QPaintEvent *event)
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
