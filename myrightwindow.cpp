#include "myrightwindow.h"

MyRightWindow::MyRightWindow(QWidget *parent) : QWidget(parent)
{
    this->setMaximumHeight(760);//固定高度=800-40
    this->setFixedSize(400,760);//宽400，高760
    custom_bcg = new CustomBCG(this);
    custom_lorenz = new CustomLorenz(this);
    custom_ecg = new CustomECG(this);
    custom_state = new CustomState(this);
    custom_sppr = new CustomSpPr(this);
    //网格布局中的四个（产生的问题：控件之间有间隔并且无法解决）
    custom_resp = new CustomResp(this);
    custom_temp = new CustomTemp(this);
    custom_nibp = new CustomNibp(this);
    custom_nibg = new CustomNibg(this);

    QHBoxLayout *layout_h = new QHBoxLayout();
    QHBoxLayout *layout_h1 = new QHBoxLayout();
    QHBoxLayout *layout_h2 = new QHBoxLayout();
    QVBoxLayout *layout_v = new QVBoxLayout(this);//主布局为垂直方向
    layout_h1->setContentsMargins(0,0,0,0);
    layout_h1->setSpacing(0);
    layout_h1->setMargin(0);
    layout_v->setContentsMargins(0,0,0,0);
    layout_v->setSpacing(0);
    layout_v->setMargin(0);
    layout_h->setContentsMargins(0,0,0,0);
    layout_h->setSpacing(0);
    layout_h->setMargin(0);
    layout_h->addWidget(custom_bcg);
    layout_h->addWidget(custom_lorenz);

    layout_h1->addWidget(custom_resp);
    layout_h1->addWidget(custom_temp);

    layout_h2->addWidget(custom_nibp);
    layout_h2->addWidget(custom_nibg);

    layout_v->addLayout(layout_h);
    layout_v->addWidget(custom_ecg);
    layout_v->addWidget(custom_sppr);
    layout_v->addLayout(layout_h1);
    layout_v->addLayout(layout_h2);
//        layout_v->addStretch();
    layout_v->addWidget(custom_state);

}


void MyRightWindow::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
//    QPen pen;
//    pen.setWidth(1);
//    pen.setColor(QColor(100, 100, 100 , 255));
//    painter.setPen(pen);
//    QRect rect = this->rect();
//    rect.setWidth(rect.width());
//    rect.setHeight(rect.height());
//    painter.drawRoundedRect(rect, 6, 6);
}
