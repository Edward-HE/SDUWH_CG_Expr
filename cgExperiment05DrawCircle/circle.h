#ifndef CIRCLE_H
#define CIRCLE_H
#include <QColor>
#include <QPainter>
#include <QPoint>

class circle {
private:
  QPoint p0;
  int r;
  QColor color;

public:
  circle(QPoint p0, int r, QColor color);
  void showCircle(QPainter *ptr);

private:
  void draw8th(QPoint p, QPainter *ptr);
};

#endif // CIRCLE_H
