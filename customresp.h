#ifndef CUSTOMRESP_H
#define CUSTOMRESP_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomResp : public QWidget
{
    Q_OBJECT
public:
    explicit CustomResp(QWidget *parent = 0);

signals:

protected:
    void paintEvent(QPaintEvent *event);

public slots:

private:
    QLabel *label_ul;//左上
    QLabel *label_ru;//右上
    QLabel *label_top;//上
    QLabel *label_bottom;//下
    QLabel *label_tt;//实时
};

#endif // CUSTOMRESP_H
