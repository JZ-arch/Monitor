#include "customlorenz.h"

CustomLorenz::CustomLorenz(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(200,760*2/7);
    QPalette palette1 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#00FF00")); // 亮绿
    QFont font1("Microsoft YaHei", 9, QFont::Medium);
    tv_name = new QLabel(this);
    tv_name->setText("Lorenz-RR");
    tv_name->setPalette(palette1);
    tv_name->setFont(font1);
    tv_name->move(5,0);

}

void CustomLorenz::paintEvent(QPaintEvent *event)
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

    //画网格线
    painter.drawLine(0,height()-width(),width(),height()-width());
    painter.drawLine(0,height()-width()*4/5,width(),height()-width()*4/5);
    painter.drawLine(0,height()-width()*3/5,width(),height()-width()*3/5);
    painter.drawLine(0,height()-width()*2/5,width(),height()-width()*2/5);
    painter.drawLine(0,height()-width()*1/5,width(),height()-width()*1/5);
    painter.drawLine(0,height(),width(),height());

    painter.drawLine(width()*1/5,height()-width(),width()*1/5,height());
    painter.drawLine(width()*2/5,height()-width(),width()*2/5,height());
    painter.drawLine(width()*3/5,height()-width(),width()*3/5,height());
    painter.drawLine(width()*4/5,height()-width(),width()*4/5,height());
    painter.drawLine(width()*5/5,height()-width(),width()*5/5,height());
}
