#include "customheartrate.h"
#include <QDebug>

static QString color1 = "#00FF00";
static QString color2 = "#02C952";
static QString color3 = "#7298FD";
static QString color4 = "#13D9DC";
static QString color5 = "#FEE902";
static QString color6 = "#FEE902";
static QString color7 = "#FFAA02";
static QVector<QString> v_colors;

//bool flag_draw,int custom_color,QString text_top,QString text_bottom
//自定义控件：心率折线图
CustomHeartRate::CustomHeartRate(QWidget *parent) : QWidget(parent)
{

}

CustomHeartRate::CustomHeartRate(bool flag_paw,int custom_color,QString text_top,QString text_bottom,int draw_method,QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(800,100);//宽800，高100
    this->x_value = width()*1/10;
    this->paint_flag = 0;
    this->per_width = width()*9/10/180;//每两个点之间的x轴间距，总长为720，总共分成60段（有61个点）
    this->my_count = 0;
    this->transf_y = 0;
    this->text_top = text_top;
    this->text_bottom = text_bottom;
    this->flag_paw = flag_paw;
    this->custom_color = custom_color;
    this->draw_method = draw_method;
    v_colors.clear();
    v_colors.append(color1);v_colors.append(color2);v_colors.append(color3);v_colors.append(color4);v_colors.append(color5);v_colors.append(color6);v_colors.append(color7);
    this->setAutoFillBackground(true);//如果放在父widget内，需要使用这句话，自动填充父控件的背景色
    tv_top = new QLabel(this);
    //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    QFont font("Microsoft YaHei", 9, QFont::Medium);
    QPalette palette = this->palette(); // 获取调色板
    palette.setColor(QPalette::WindowText, QColor(v_colors.at(this->custom_color-1))); // 设置字体颜色

    tv_top->setPalette(palette);
    if(flag_paw)//画爪子，label需要做偏移
        tv_top->setGeometry(25,7,200,24);
    else
        tv_top->setGeometry(25,1,200,24);
    tv_top->setText(this->text_top);
    tv_top->setFont(font);
    tv_top->show();

    tv_bottom = new QLabel(this);
    tv_bottom->setPalette(palette);
    if(flag_paw)
        tv_bottom->setGeometry(25,66,200,24);
    else
        tv_bottom->setGeometry(25,74,200,24);
    tv_bottom->setText(this->text_bottom);
    tv_bottom->setFont(font);
    tv_bottom->show();
}

void CustomHeartRate::paintEvent(QPaintEvent *)
{

    //qDebug()<<"x坐标："<<x_value;
    QPainter paint(this);//直接指定QPaintDevice，不用paint.begin和paint.end
    //paint=new QPainter;//如果这么写，需要setPaintDevice
    paint.setRenderHint(QPainter::Antialiasing, true);// 反走样、抗锯齿
    paint.setPen(QPen(QColor(v_colors.at(this->custom_color-1)),1,Qt::DashLine));//设置画笔的颜色、大小，DashLine：长虚线样式
    //虚线左边空出1/10，右边空出1/10，上下间距为1/10，虚线之间的间隔为height的2/5
    paint.drawLine(width()*1/10,height()*1/10,width(),height()*1/10); //虚线的坐标：从60到780，总共720
    paint.drawLine(width()*1/10,height()*1/10+height()*2/5,width(),height()*1/10+height()*2/5);
    paint.drawLine(width()*1/10,height()*1/10+height()*4/5,width(),height()*1/10+height()*4/5);

    //画左边粗的竖线
    QPen pen;
    pen.setColor(QColor(v_colors.at(this->custom_color-1)));
    pen.setWidth(3);
    paint.setPen(pen);
    paint.drawLine(width()*1/40,height()*1/10,width()*1/40,height()*1/10+height()*4/5);
    //画竖线的爪子
    if(this->flag_paw){
        paint.drawLine(width()*1/40+2,height()*1/10,width()*1/40+8,height()*1/10);
        paint.drawLine(width()*1/40+2,height()*1/10+height()*4/5,width()*1/40+8,height()*1/10+height()*4/5);
    }

    pen.setWidth(2);
    paint.setPen(pen);

    QPainterPath mPath1;
    QPainterPath mPath2;
    QPoint c1,c2;
    if(draw_method==1){//画贝塞尔曲线
        if(paint_flag==0){//data在前
            mPath1 = SmoothGenerator::generateSmooth(data);
            mPath2 = SmoothGenerator::generateSmooth(data2);
            paint.drawPath(mPath1);
            paint.drawPath(mPath2);
        }else{//data2在前
            mPath1 = SmoothGenerator::generateSmooth(data);
            mPath2 = SmoothGenerator::generateSmooth(data2);
            paint.drawPath(mPath1);
            paint.drawPath(mPath2);
        }
    }else if(draw_method==0){//画动态折线
        if(paint_flag==0){//data在前
            for(int i = 0;i<this->data.size();i++){//画data
                if(this->data.size()>=2&&i>=1){
                    paint.drawLine(data[i-1].x(),data[i-1].y(),data[i].x(),data[i].y());
                }
            }

            for(int i = 0;i<this->data2.size();i++){//画data2
                if(this->data2.size()>=2&&i>3){//留3个间距作为空白区域
                    paint.drawLine(data2[i-1].x(),data2[i-1].y(),data2[i].x(),data2[i].y());
                }
            }

        }else{//data2在前
            for(int i = 0;i<this->data2.size();i++){//画data2
                if(this->data2.size()>=2&&i>=1){
                    paint.drawLine(data2[i-1].x(),data2[i-1].y(),data2[i].x(),data2[i].y());
                }
            }
            for(int i = 0;i<this->data.size();i++){//画data
                if(this->data.size()>=2&&i>3){
                    paint.drawLine(data[i-1].x(),data[i-1].y(),data[i].x(),data[i].y());
                }
            }

        }
    }
}

void CustomHeartRate::draw()
{
    //手动刷新，使窗口重绘(触发paintEvent)
    update();
}

//my_count用来计数，如果达到了720个，那么重置为零

//收到数据后，对两个data的数据进行处理
void CustomHeartRate::receiveData(double receive_y)
{
    //画线区域：宽720，高80
    //起始坐标：(80,10)  中间坐标：(80,50)  下面左边：(80,90)
    my_count ++;
    //数据范围的最大值  对应  y的最大值
    transf_y = receive_y/50*(-1)+height()*1/10+height()*2/5;
    //width为自定义控件的宽（800）

    QPoint point(x_value,transf_y);//新传入的点
    x_value += per_width;//加上间距得到下一个点的x坐标

    if(paint_flag==0){//首先data在前
        this->data.append(point);
        if(this->data2.size()>0){
            this->data2.remove(0);
        }
    }else if(paint_flag == 1){//data2在前
        this->data2.append(point);//将数据添加到data
        if(this->data.size()>0){
            this->data.remove(0);
        }
    }

    if(my_count==181){
        x_value = width()*1/10;//重置x的坐标
        my_count = 0;//重置计数器
        if(paint_flag==0){
            paint_flag = 1;
        }else{
            paint_flag = 0;
        }
    }

    draw();

}
