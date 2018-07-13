#ifndef CUSTOMNIBG_H
#define CUSTOMNIBG_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomNibg : public QWidget
{
    Q_OBJECT
public:
    explicit CustomNibg(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *label_ul;//左上
    QLabel *label_ru;//右上
    QLabel *label_content1;//内容
    QLabel *label_lr;//右下

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CUSTOMNIBG_H
