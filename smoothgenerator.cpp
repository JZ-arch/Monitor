#include "smoothgenerator.h"



SmoothGenerator::SmoothGenerator()
{

}

//生成圆滑的曲线
QPainterPath SmoothGenerator::generateSmooth(const QVector<QPoint> points)
{
    QPainterPath path;
    if(points.size() == 1){
        path.moveTo(points[0]);
    }else if(points.size() == 2){//只有两个点
        path.moveTo(points[0]);
        QPointF c1 = QPointF(
                    points.at(1).x()-(points.at(1).x()-points.at(0).x())/4,
                    points.at(1).y()-(points.at(1).y()-points.at(0).y())/4
                    );
        path.quadTo(c1,points.at(1));
    }else if(points.size()>=3){
        QPainterPath path(points[0]);
        for (int i = 0; i < points.size()-1; i=i+1) {
            QPointF c1,c2;
            if(i == 0){
                c1 = QPointF(
                            points.at(i).x()+(points.at(i+1).x()-points.at(i).x())/4,
                            points.at(i).y()+(points.at(i+1).y()-points.at(i).y())/4
                            );
                c2 = QPointF(
                            points.at(i+1).x()-(points.at(i+2).x()-points.at(i).x())/4,
                            points.at(i+1).y()-(points.at(i+2).y()-points.at(i).y())/4
                            );
            }else if(i == points.size()-2){//倒数第二个点
                c1 = QPointF(
                            points.at(i).x()+(points.at(i+1).x()-points.at(i-1).x())/4,
                            points.at(i).y()+(points.at(i+1).y()-points.at(i-1).y())/4
                            );
                c2 = QPointF(
                            points.at(i+1).x()-(points.at(i+1).x()-points.at(i).x())/4,
                            points.at(i+1).y()-(points.at(i+1).y()-points.at(i).y())/4
                            );
            }else{
                c1 = QPointF(
                            points.at(i).x()+(points.at(i+1).x()-points.at(i-1).x())/4,
                            points.at(i).y()+(points.at(i+1).y()-points.at(i-1).y())/4
                            );
                c2 = QPointF(
                            points.at(i+1).x()-(points.at(i+2).x()-points.at(i).x())/4,
                            points.at(i+1).y()-(points.at(i+2).y()-points.at(i).y())/4
                            );

            }
             path.cubicTo(c1, c2, points.at(i+1));
        }
        return path;

    }

    return path;


}
