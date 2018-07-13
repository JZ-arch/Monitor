#include "customnibg.h"

CustomNibg::CustomNibg(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(150,760*1/7);

    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#FEFEFE")); // 亮白
    palette2.setColor(QPalette::WindowText, QColor("#939395")); // 暗白
    QFont font1("Microsoft YaHei", 14, QFont::Medium);
    QFont font2("Microsoft YaHei", 28, QFont::Medium);
    QFont font3("Microsoft YaHei", 12, QFont::Medium);

    label_ul = new QLabel(this);
    label_ru = new QLabel(this);
    label_content1 = new QLabel(this);
    label_lr = new QLabel(this);

    label_ul->setText("NIBG");
    label_ru->setText("mg/dL");
    label_content1->setText("97");
    label_lr->setText("13:01");

    label_ul->setPalette(palette1);
    label_ru->setPalette(palette2);
    label_content1->setPalette(palette1);
    label_lr->setPalette(palette2);

    label_ul->setFont(font1);
    label_ru->setFont(font3);
    label_content1->setFont(font2);
    label_lr->setFont(font3);

    label_ul->move(10,10);
    label_ru->move(width()-55,10);
    label_content1->move(55,40);
    label_lr->move(width()-50,height()-25);
}


void CustomNibg::paintEvent(QPaintEvent *event)
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
