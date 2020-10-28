#include "ellipse.h"

ellipse::ellipse(QPoint p0, int a, int b, QColor color)
    : p0(p0), a(a), b(b), color(color) {}

void ellipse::showEllipse(QPainter *ptr) {
  if (a == 0 || b == 0)
    return;
  double d;
  int x, y;
  x = 0;
  y = b;
  d = 4 * b * b - 4 * a * a * b + a * a;
  while ((a * a * (2 * y - 1)) >= 2 * (b * b * (x + 1))) {
    Draw4thEllipse(x, y, ptr);
    if (d < 0)
      d = d + 4 * b * b * (2 * x + 3);
    else {
      d = d + 4 * b * b * (2 * x + 3) - 8 * a * a * (y - 1);
      y--;
    }
    x++;
  }
  x = a;
  y = 0;
  d = 4 * a * a - 4 * a * b * b + b * b;
  while ((b * b * (2 * x - 1)) > 2 * (a * a * (y - 1))) {
    Draw4thEllipse(x, y, ptr);
    if (d < 0)
      d = d + 4 * a * a * (2 * y + 3);
    else {
      d = d + 4 * a * a * (2 * y + 3) - 8 * b * b * (x - 1);
      x--;
    }
    y++;
  }
}

void ellipse::Draw4thEllipse(int x, int y, QPainter *ptr) {
  ptr->save();
  ptr->setPen(color);
  ptr->drawPoint(x + p0.x(), y + p0.y());
  ptr->drawPoint(-x + p0.x(), y + p0.y());
  ptr->drawPoint(x + p0.x(), -y + p0.y());
  ptr->drawPoint(-x + p0.x(), -y + p0.y());
  ptr->restore();
}
