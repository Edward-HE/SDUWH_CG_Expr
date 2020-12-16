#ifndef GRID_H
#define GRID_H
#include <QObject>
#include <QPoint>
#include <QRect>
#include <QPainter>
#include <QColor>
#include <QPen>


class Grid
{
private:
    QColor color;//网格线颜色
    int xspacing;//网格水平间距
    int yspacing;//网格垂直间距
    QRect size;//网格范围，客户空间大小

public:
    Grid();
    Grid(int xspacing, int yspacing, QColor color, QRect size);
       QRect getSize();
       void setSpacing(int xspacing, int yspacing);//设置网格间距
       int getXSpacing();//返回水平间距
       int getYSpacing();//返回垂直间距
       void setColor(QColor color);//设置网格线颜色
       void setSize(QRect size);
       void draw(QPainter* pt);
       QPoint getClosestPoint(QPoint point);//获取离指定点最近的网点

};

#endif // GRID_H
