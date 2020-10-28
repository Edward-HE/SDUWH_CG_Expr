#ifndef POLYGON_H
#define POLYGON_H
#include <QColor>
#include <QList>
#include <QPainter>
#include <QPoint>
#include <QVector>
#include <algorithm>
using namespace std;
#include "edge.h"

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
  void showPolygonInEdgeTable(QPainter *ptr); //有序边表算法
};

#endif // POLYGON_H
