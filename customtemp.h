#ifndef CUSTOMTEMP_H
#define CUSTOMTEMP_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomTemp : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTemp(QWidget *parent = 0);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent *event);

private:
    QLabel *tv_left1;
    QLabel *tv_left2;
    QLabel *tv_left3;
    QLabel *tv_right1;
    QLabel *tv_right2;
    QLabel *tv_right3;
};

#endif // CUSTOMTEMP_H
