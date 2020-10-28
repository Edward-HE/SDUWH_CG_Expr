#include "polygon.h"
#include <QDebug>
#include <QPolygon>

polygon::polygon(QVector<QPoint> &points, QPoint seed, QColor color)
    : points(points), seed(seed), color(color) {}

void polygon::showPolygonInSeed(QPainter *ptr) {
  if (!isInPolygon(seed) || points.size() < 3)
    return;
  //获取多边形最小包围盒
  int minx, maxx, miny, maxy;
  minx = getMinX() - 1;
  maxx = getMaxX() + 1;
  miny = getMinY() - 1;
  maxy = getMaxY() + 1;
  if (seed.x() <= minx || seed.x() >= maxx || seed.y() <= miny ||
      seed.y() >= maxy)
    return;
  //设置一个标志矩阵
  int m = maxy - miny;
  int n = maxx - minx;
  bool MF[m][n];
  int i, j;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      MF[i][j] = false;
  //绘制边界，并将边界像素标志置为true
  QPoint p0, p1;
  int temp;
  int vertics = points.size();
  int x, y;
  double tx, ty, dx, dy;
  int k;
  int x0, x1, y0, y1;
  ptr->save();
  ptr->setPen(color);

  for (k = 0; k < vertics; k++) //逐边绘制
  {
    //获取一条边p0p1
    if (k == vertics - 1) {
      p0 = points[k];
      p1 = points[0];
    } else {
      p0 = points[k];
      p1 = points[k + 1];
    }

    x0 = p0.x();
    y0 = p0.y();
    x1 = p1.x();
    y1 = p1.y();

    if (y0 == y1) //水平边
    {
      y = y0;
      if (x0 > x1) {
        temp = x0;
        x0 = x1;
        x1 = temp;
      }
      for (x = x0; x < x1; x++) {
        ptr->drawPoint(x, y);
        MF[y - miny][x - minx] = true;
      }
    } else if (x0 == x1) //垂直边
    {
      x = x0;
      if (y0 > y1) {
        temp = y0;
        y0 = y1;
        y1 = temp;
      }
      for (y = y0; y < y1; y++) {
        ptr->drawPoint(x, y);
        MF[y - miny][x - minx] = true;
      }

    } else //非水平和垂直边
    {
      dy = (double)(y1 - y0) / (double)(x1 - x0);
      dx = 1 / dy;

      if (dy > -1 && dy < 1) {
        if (x0 > x1) {
          temp = x0;
          x0 = x1;
          x1 = temp;
          temp = y0;
          y0 = y1;
          y1 = temp;
        }
        ty = y0;
        for (x = x0; x <= x1; x++) {
          y = (int)(ty + 0.5);
          ptr->drawPoint(x, y);
          MF[y - miny][x - minx] = true;
          ty += dy;
        }
      } else {
        if (y0 > y1) {
          temp = x0;
          x0 = x1;
          x1 = temp;
          temp = y0;
          y0 = y1;
          y1 = temp;
        }
        tx = x0;
        for (y = y0; y <= y1; y++) {
          x = (int)(tx + 0.5);
          ptr->drawPoint(x, y);
          MF[y - miny][x - minx] = true;
          tx += dx;
        }
      }
    }
  }

  //种子点压栈，压栈像素标志置为true
  QStack<QPoint> stack;
  stack.push(seed);
  MF[seed.y() - miny][seed.x() - minx] = true;
  //当栈不为空时，退栈，绘制像素点
  //对当前退栈元素的左上右下点进行检查，若标志为false，压栈，并将压栈像素标志置为true
  QPoint ps;

  while (!stack.isEmpty()) {
    ps = stack.pop();
    ptr->drawPoint(ps);

    p0.setX(ps.x() - 1); //左
    p0.setY(ps.y());
    if (!MF[p0.y() - miny][p0.x() - minx]) {
      stack.push(p0);
      MF[p0.y() - miny][p0.x() - minx] = true;
    }

    p0.setX(ps.x() + 1); //右
    p0.setY(ps.y());
    if (!MF[p0.y() - miny][p0.x() - minx]) {
      stack.push(p0);
      MF[p0.y() - miny][p0.x() - minx] = true;
    }

    p0.setX(ps.x()); //下
    p0.setY(ps.y() - 1);
    if (!MF[p0.y() - miny][p0.x() - minx]) {
      stack.push(p0);
      MF[p0.y() - miny][p0.x() - minx] = true;
    }

    p0.setX(ps.x()); //上
    p0.setY(ps.y() + 1);
    if (!MF[p0.y() - miny][p0.x() - minx]) {
      stack.push(p0);
      MF[p0.y() - miny][p0.x() - minx] = true;
    }
  }

  ptr->restore();
}

int polygon::getMaxX() {
  int max = 0;
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->x() > max)
      max = iter->x();
  return max;
}

int polygon::getMinX() {
  int min = getMaxX();
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->x() < min)
      min = iter->x();
  return min;
}

int polygon::getMaxY() {
  int max = 0;
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->y() > max)
      max = iter->y();
  return max;
}

int polygon::getMinY() {
  int min = getMaxY();
  QVector<QPoint>::iterator iterPos;
  for (iterPos = points.begin(); iterPos != points.end(); iterPos++)
    if (iterPos->y() < min)
      min = iterPos->y();
  return min;
}

bool polygon::isInPolygon(QPoint p) {
  int i, j;
  bool c = false;

  for (i = 0, j = points.size() - 1; i < points.size(); j = i++) {
    if (((points[i].y() > seed.y()) != (points[j].y() > seed.y())) &&
        (seed.x() < (points[j].x() - points[i].x()) *
                            (seed.y() - points[i].y()) /
                            (points[j].y() - points[i].y()) +
                        points[i].x()))
      c = !c;
  }
  return c;
}
