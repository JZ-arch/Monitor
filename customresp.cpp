#include "customresp.h"

CustomResp::CustomResp(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(250,760*1/7);

    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#FDED04")); // 亮黄
    palette2.setColor(QPalette::WindowText, QColor("#AA9C21")); // 暗黄
    QFont font1("Microsoft YaHei", 15, QFont::Medium);
    QFont font2("Microsoft YaHei", 44, QFont::Medium);
    label_ul = new QLabel(this);
    label_top = new QLabel(this);
    label_bottom = new QLabel(this);
    label_tt = new QLabel(this);

    label_ul->setText("RESP");
    label_top->setText("30");
    label_bottom->setText("8");
    label_tt->setText("19");

    label_ul->setPalette(palette1);
    label_top->setPalette(palette2);
    label_bottom->setPalette(palette2);
    label_tt->setPalette(palette1);

    label_ul->setFont(font1);
    label_top->setFont(font1);
    label_bottom->setFont(font1);
    label_tt->setFont(font2);

    label_ul->move(5,5);
    label_top->move(8,30);
    label_bottom->move(10,70);
    label_tt->move(85,20);

}

void CustomResp::paintEvent(QPaintEvent *event)
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
