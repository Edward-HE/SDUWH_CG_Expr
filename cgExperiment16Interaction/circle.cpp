//Circle.cpp
#include "circle.h"

Circle::Circle()
{
}

Circle::Circle(QPoint center, int radius)
{
    this->center = center;
    this->radius = radius;
}

//设置圆
void Circle::setCircle(QPoint center, int radius)
{
    this->center = center;
    this->radius = radius;
}

//设置圆心
void Circle::setCenter(QPoint center)
{
    this->center = center;
}

//设置半径
void Circle::setRadius(int radius)
{
    this->radius = radius;
}

//获取圆心
QPoint Circle::getCenter()
{
    return center;
}

//获取半径
int Circle::getRadius()
{
    return radius;
}

//绘制圆
void Circle::draw(QPainter* pt)
{
    pt->drawEllipse(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius);
}

//判断指定的点是否在圆内
bool Circle::ptInCircle(QPoint point)
{
    return (point.x() - center.x()) * (point.x() - center.x()) + (point.y() - center.y()) * (point.y() - center.y()) <= radius * radius;
}
