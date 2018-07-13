#ifndef CUSTOMSPPR_H
#define CUSTOMSPPR_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomSpPr : public QWidget
{
    Q_OBJECT
public:
    explicit CustomSpPr(QWidget *parent = 0);

signals:
protected:
    void paintEvent(QPaintEvent *event);
    QLabel *sp_left1;
    QLabel *sp_left2;
    QLabel *sp_left3;
    QLabel *sp_percent;
    QLabel *sp_content;

    QLabel *pr_left;
    QLabel *pr_right;
    QLabel *pr_content;


public slots:
};

#endif // CUSTOMSPPR_H
