#include "customecg.h"

CustomECG::CustomECG(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,760*1/7);
    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#7597FF")); // 亮紫
    palette2.setColor(QPalette::WindowText, QColor("#6681D0")); // 暗紫
    QFont font1("Microsoft YaHei", 16, QFont::Medium);
    QFont font2("Microsoft YaHei", 60, QFont::Medium);
    label_ul = new QLabel(this);
    label_ru = new QLabel(this);
    label_top = new QLabel(this);
    label_bottom = new QLabel(this);
    label_tt = new QLabel(this);
    label_lr = new QLabel(this);

    label_ul->setText("ECG");
    label_ru->setText("bpm");
    label_top->setText("120");
    label_bottom->setText("50");
    label_tt->setText("85");
    label_lr->setText("ST段压低");

    label_ul->setPalette(palette1);
    label_ru->setPalette(palette2);
    label_top->setPalette(palette2);
    label_bottom->setPalette(palette2);
    label_tt->setPalette(palette1);
    label_lr->setPalette(palette1);

    label_ul->setFont(font1);
    label_ru->setFont(font1);
    label_top->setFont(font1);
    label_bottom->setFont(font1);
    label_tt->setFont(font2);
    label_lr->setFont(font1);

    label_ul->move(5,2);
    label_ru->move(width()-60,2);
    label_top->move(5,30);
    label_bottom->move(5,80);
    label_tt->move(140,10);
    label_lr->move(width()-100,75);
}

void CustomECG::paintEvent(QPaintEvent *event)
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
