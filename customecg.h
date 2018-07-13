#ifndef CUSTOMECG_H
#define CUSTOMECG_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomECG: public QWidget
{
    Q_OBJECT
public:
    explicit CustomECG(QWidget *parent = 0);
signals:
protected:
    void paintEvent(QPaintEvent *event);

private:
    QLabel *label_ul;//左上
    QLabel *label_ru;//右上
    QLabel *label_top;//上
    QLabel *label_bottom;//下
    QLabel *label_tt;//实时
    QLabel *label_lr;//右下
};

#endif // CUSTOMECG_H
