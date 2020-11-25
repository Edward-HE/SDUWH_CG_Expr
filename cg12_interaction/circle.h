//Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H
#include <QObject>
#include <QPainter>
#include <QPoint>

class Circle {
private:
    QPoint center; //圆心
    int radius; //圆半径
public:
    Circle();
    Circle(QPoint center, int radius);
    void setCircle(QPoint center, int radius); //通过中心和半径设置圆
    void setCenter(QPoint center); //设置圆心
    void setRadius(int radius); //设置半径
    QPoint getCenter(); //获取圆心
    int getRadius(); //获取半径
    void draw(QPainter* pt); //绘制圆
    bool ptInCircle(QPoint point); //判断点是否在圆内
};

#endif // CIRCLE_H
