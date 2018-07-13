#include "customstate.h"


//最下面的状态
CustomState::CustomState(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,760*1/7);
    QPalette palette1 = this->palette(); // 获取调色板
    QPalette palette2 = this->palette(); // 获取调色板
    palette1.setColor(QPalette::WindowText, QColor("#FBAE00")); // 亮黄
    palette2.setColor(QPalette::WindowText, QColor("#158942")); // 暗绿
    QFont font1("Microsoft YaHei", 16, QFont::Medium);
    QFont font2("Microsoft YaHei", 32, QFont::Medium);
    label_tip = new QLabel(this);
    label_state = new QLabel(this);

    label_tip->setPalette(palette1);
    label_state->setPalette(palette1);

    label_tip->setText("STATE");
    label_state->setText("体 动");

    label_tip->setFont(font1);
    label_state->setFont(font2);

    label_tip->move(5,2);
    label_state->move(150,30);

}

void CustomState::paintEvent(QPaintEvent *event)
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
