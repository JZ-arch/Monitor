#ifndef MYRIGHTWINDOW_H
#define MYRIGHTWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>


#include <custombcg.h>
#include <customlorenz.h>
#include <customecg.h>
#include <customstate.h>
#include <customsppr.h>
#include <customresp.h>
#include <customtemp.h>
#include <customnibp.h>
#include <customnibg.h>

//右边的参数显示区域
class MyRightWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyRightWindow(QWidget *parent = 0);

signals:

protected:
    void paintEvent(QPaintEvent *event);

private:
    CustomBCG *custom_bcg;//左上
    CustomLorenz *custom_lorenz;//右上
    CustomECG *custom_ecg;//第二个
    CustomState *custom_state;//最下
    CustomSpPr *custom_sppr;
    CustomResp *custom_resp;//网格左上
    CustomTemp *custom_temp;//网格右上
    CustomNibp *custom_nibp;//网格左下
    CustomNibg *custom_nibg;//网格右下

public slots:
};

#endif // MYRIGHTWINDOW_H
