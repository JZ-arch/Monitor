#ifndef CUSTOMHEARTRATE_H
#define CUSTOMHEARTRATE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>
#include <QPainterPath>

#include <smoothgenerator.h>


class CustomHeartRate : public QWidget
{

    const int DRAW_LINE = 0;//画直线
    const int DRAW_BESSEL = 1;//画贝塞尔曲线

    Q_OBJECT
public:
    explicit CustomHeartRate(QWidget *parent = 0);
    explicit CustomHeartRate(bool flag_paw,int custom_color,QString text_top,QString text_bottom,int draw_method,QWidget *parent = 0);
    void draw();//根据纵坐标开始绘图
    //virtual void setParameter(bool,int,QString,QString);
    //设置参数，四个分别为：是否画爪子，颜色，竖线上下的文字。
signals:

private:
    //窗口绘图，需要重写该事件
    void paintEvent(QPaintEvent*);
    QVector<QPoint> data;//纵坐标数据（第一条）
    QVector<QPoint> data2;//纵坐标数据（第二条）
    QLabel * tv_top;//上面的label
    QLabel * tv_bottom;//下面的label

    bool flag_paw;//是否画竖线的爪子（0：不画，1：画）
    int custom_color;//QVector的下标，设置颜色(颜色对应color1到color7)
    QString text_top;//上面的文字
    QString text_bottom;//下面的文字

    int x_value;//用来记录每一个时刻的点的x坐标
    int paint_flag;//为0：data在前，为1：data2在前
    int per_width;//每个点之间横坐标的间距
    int my_count;//用来记录点的个数（第几个点）
    int transf_y;//原始数据经过转换之后的纵坐标
    int draw_method;//画图方式（0:画直线，1画贝塞尔曲线）

public slots:
    void receiveData(double);  //接收传递过来的数据的槽
};

#endif // CUSTOMHEARTRATE_H
