#ifndef SMOOTHGENERATOR_H
#define SMOOTHGENERATOR_H

#include <QObject>
#include <QPainterPath>
#include <QPoint>
#include <QList>
#include <QVector>


//根据传入的点生成圆滑曲线
class SmoothGenerator
{
public:
    SmoothGenerator();
    static QPainterPath generateSmooth(const QVector<QPoint> points);
    void getControlPoints();
};

#endif // SMOOTHGENERATOR_H
