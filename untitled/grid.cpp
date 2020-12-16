#include "grid.h"

Grid::Grid()
{
    xspacing = 50;
    yspacing = 50;
    color = Qt::blue;
}

Grid::Grid(int xspacing, int yspacing, QColor color, QRect size)
{
    this->xspacing = xspacing;
    this->yspacing = yspacing;
    this->color = color;
    this->size = size;
}

//设置网格线颜色
void Grid::setColor(QColor color)
{
    this->color = color;
}

//设置网格间距
void Grid::setSpacing(int xspacing, int yspacing)
{
    this->xspacing = xspacing;
    this->yspacing = yspacing;
}

void Grid::setSize(QRect size)
{
    this->size = size;
}
//返回水平间距
int Grid::getXSpacing()
{
    return xspacing;
}
//返回垂直间距
int Grid::getYSpacing()
{
    return yspacing;
}

QRect Grid::getSize()
{
    return size;
}

//绘制网格
void Grid::draw(QPainter* pt)
{
    pt->save();
    pt->setPen(color);

    //绘制水平线
    for (int i = 0; i<size.height()/yspacing + 1; i++)
    {
        int y = i*yspacing;
        pt->drawLine(QPoint(size.left(),y), QPoint(size.right(),y));
    }

    //绘制垂直线
    for (int j = 0; j<size.width()/xspacing + 1; j++)
    {
        int x = j*xspacing;
        pt->drawLine(QPoint(x, size.top()), QPoint(x, size.bottom()));
    }

    pt->restore();
}

//返回离指定点最近的网点(两条网线的交点)
QPoint Grid::getClosestPoint(QPoint point)
{
    int m = size.width()/xspacing*xspacing;
    int n = size.height()/yspacing*yspacing;

    if (point.x() <= (size.left() - xspacing / 2))
        point.setX(size.left());
    if (point.x() >= (m + xspacing / 2))
        point.setX(m);
    if (point.y() <= (size.top() - yspacing / 2))
        point.setY(size.top());
    if (point.y() >= (n + yspacing / 2))
        point.setY(n);

    int x = (point.x() + xspacing / 2) / xspacing*xspacing;
    int y = (point.y() + yspacing / 2) / yspacing*yspacing;

    return QPoint(x, y);
}


