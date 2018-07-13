#ifndef CUSTOMNIBP_H
#define CUSTOMNIBP_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>


class CustomNibp : public QWidget
{
    Q_OBJECT
public:
    explicit CustomNibp(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:\
    QLabel *label_ul;//左上
    QLabel *label_ru;//右上
    QLabel *label_content1;//内容
    QLabel *label_content2;//内容
    QLabel *label_lr;//右下

};

#endif // CUSTOMNIBP_H
