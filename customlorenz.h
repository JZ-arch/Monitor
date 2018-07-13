#ifndef CUSTOMLORENZ_H
#define CUSTOMLORENZ_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomLorenz : public QWidget
{
    Q_OBJECT
public:
    explicit CustomLorenz(QWidget *parent = 0);

signals:

public slots:
private:
    QLabel *tv_name;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CUSTOMLORENZ_H
