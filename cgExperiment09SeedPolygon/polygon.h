#ifndef POLYGON_H
#define POLYGON_H
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QStack>
#include <QVector>

class polygon {
private:
  QVector<QPoint> points;
  QPoint seed;
  QColor color;
  int getMaxX();
  int getMinX();
  int getMaxY();
  int getMinY();
  bool isInPolygon(QPoint p);

public:
  polygon(QVector<QPoint> &points, QPoint seed, QColor color);
  void showPolygonInSeed(QPainter *ptr); //边标志算法
};

#endif // POLYGON_H
