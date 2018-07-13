#include "mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QWidget(parent)
{

    this->setFixedSize(1280,800);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor (40,41,45,255));
    this->setPalette(pal);
    window_title = new MyWindowTitle(this);
    window_left = new MyLeftWindow(this);
    window_right = new MyRightWindow(this);

    QVBoxLayout *layout_v = new QVBoxLayout(this);//主布局为垂直布局
    layout_v->setContentsMargins(0,0,0,0);//默认：各个控件之间上下左右会有11px的间距
    layout_v->setMargin(0);
    layout_v->setSpacing(0);
    QHBoxLayout *layout_h_title = new QHBoxLayout();
    layout_h_title->setContentsMargins(0,0,0,0);
    layout_h_title->setMargin(0);
    layout_h_title->setSpacing(0);
    layout_h_title->addWidget(window_title);
    QHBoxLayout *layout_h_content = new QHBoxLayout();//水平布局分为 左右两块
    layout_h_content->setContentsMargins(0,0,0,0);
    layout_h_content->setMargin(0);//控制左右间距
    layout_h_content->setSpacing(0);//控制上下间距
    layout_h_content->addSpacerItem(new QSpacerItem(12,0));
    layout_h_content->addWidget(window_left);
    layout_h_content->addStretch();//左右之间添加弹簧
    layout_h_content->addWidget(window_right);

    layout_v->addLayout(layout_h_title);
    layout_v->addLayout(layout_h_content);
    this->setLayout(layout_v);
}

MyMainWindow::~MyMainWindow()
{

}
