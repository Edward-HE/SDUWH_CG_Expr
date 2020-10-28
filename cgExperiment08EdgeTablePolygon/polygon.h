#ifndef POLYGON_H
#define POLYGON_H
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QVector>

class polygon {
private:
  QVector<QPoint> points;
  QColor color;
  int getMaxX();
  int getMinX();
  int getMaxY();
  int getMinY();

public:
  polygon(QVector<QPoint> &points, QColor color);
  void showPolygonInEdgeFlag(QPainter *ptr); //边标志算法
};

#endif // POLYGON_H
