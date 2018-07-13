#ifndef CUSTOMSTATE_H
#define CUSTOMSTATE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QString>

class CustomState : public QWidget
{
    Q_OBJECT
public:
    explicit CustomState(QWidget *parent = 0);

signals:
protected:
    void paintEvent(QPaintEvent *event);
private:
     QLabel *label_tip;
     QLabel *label_state;//状态显示


public slots:
};

#endif // CUSTOMSTATE_H
