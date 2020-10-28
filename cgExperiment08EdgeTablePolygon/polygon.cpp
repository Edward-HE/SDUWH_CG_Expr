#include "polygon.h"

polygon::polygon(QVector<QPoint> &points, QColor color)
    : points(points), color(color) {}

void polygon::showPolygonInEdgeFlag(QPainter *ptr) {
  if (points.size() < 3)
    return;
  ptr->save();
  ptr->setPen(color);

  //获取多边形最小包围盒
  int minx, maxx, miny, maxy;
  minx = getMinX();
  maxx = getMaxX();
  miny = getMinY();
  maxy = getMaxY();

  //设置一个标志矩阵
  int m = maxy - miny;
  int n = maxx - minx;
  bool MF[m][n];
  int i, j;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      MF[i][j] = false;

  //对于多边形每一条边，从这条边向右直到包围盒右边界进行扫描
  QPoint p0, p1, temp;
  double dx, tx;
  int x;
  int k;
  int vertics = points.size();

  for (k = 0; k < vertics; k++) {
    //获取一条边p0p1
    if (k == vertics - 1) {
      p0 = points[k];
      p1 = points[0];
    } else {
      p0 = points[k];
      p1 = points[k + 1];
    }

    if (p0.y() > p1.y()) //将p0设为边的起点坐标，y坐标较小
    {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }

    //对于一条边，从左至右对标志位求反
    if (p0.y() != p1.y()) //非水平边
    {
      dx = static_cast<double>(p1.x() - p0.x()) / (p1.y() - p0.y());
      //对于一条边，y每次递增1,x每次递增dx
      x = p0.x();
      tx = x;
      for (i = p0.y(); i < p1.y(); i++) {
        x = static_cast<int>(tx);
        for (j = x; j < maxx; j++)
          MF[i - miny][j - minx] = !MF[i - miny][j - minx];
        tx = tx + dx;
      }
    }
  }
  //对整个包围盒扫描，为true，用前景色绘制
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (MF[i][j])
        ptr->drawPoint(j + minx, i + miny);
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
