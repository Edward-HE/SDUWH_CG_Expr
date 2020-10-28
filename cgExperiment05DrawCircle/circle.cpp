#include "circle.h"

circle::circle(QPoint p0, int r, QColor color) : p0(p0), r(r), color(color) {}

void circle::showCircle(QPainter *ptr) {
  if (r < 1)
    return;
  int x, y;
  int e = 1 - r;
  x = 0;
  y = r;
  while (x < y) {
    draw8th(QPoint(x, y), ptr);
    if (e <= 0)
      e = e + 2 * x + 3;
    else {
      e = e + 2 * x - 2 * y + 5;
      y--;
    }
    x++;
  }
}

void circle::draw8th(QPoint p, QPainter *ptr) {
  ptr->save();
  ptr->setPen(color);
  ptr->drawPoint(p.x() + p0.x(), p.y() + p0.y());
  ptr->drawPoint(p.y() + p0.x(), p.x() + p0.y());
  ptr->drawPoint(-p.y() + p0.x(), p.x() + p0.y());
  ptr->drawPoint(-p.x() + p0.x(), p.y() + p0.y());
  ptr->drawPoint(p.y() + p0.x(), -p.x() + p0.y());
  ptr->drawPoint(p.x() + p0.x(), -p.y() + p0.y());
  ptr->drawPoint(-p.x() + p0.x(), -p.y() + p0.y());
  ptr->drawPoint(-p.y() + p0.x(), -p.x() + p0.y());
  ptr->restore();
}
