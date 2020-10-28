#include "line.h"

line::line(QPoint p0, QPoint p1, QColor color) : p0(p0), p1(p1), color(color) {}

void line::showLineInBresenham(QPainter *ptr) {
  QPoint temp;
  double m;
  double e = -0.5;
  int x, y;

  if (p0.y() == p1.y()) //水平线
  {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    ptr->save();
    ptr->setPen(color);
    for (x = p0.x(); x < p1.x(); x++)
      ptr->drawPoint(x, p0.y());
    ptr->restore();
    return;
  }

  if (p0.x() == p1.x()) //垂直线
  {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    ptr->save();
    ptr->setPen(color);
    for (y = p0.y(); y < p1.y(); y++)
      ptr->drawPoint(p0.x(), y);
    ptr->restore();
    return;
  }

  m = (double)(p1.y() - p0.y()) / (double)(p1.x() - p0.x());
  if (m > 0 && m <= 1) //斜率在-45°到45°之间
  {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    e = -0.5;
    x = p0.x();
    y = p0.y();
    while (x < p1.x()) {
      ptr->drawPoint(x, y);
      e = e + m;
      if (e > 0) {
        y++;
        e = e - 1;
      }
      x++;
    }
  } else if (m >= -1 && m < 0) {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    e = 0.5;
    x = p0.x();
    y = p0.y();
    while (x < p1.x()) {
      ptr->drawPoint(x, y);
      e = e + m;
      if (e < 0) {
        y--;
        e = e + 1;
      }
      x++;
    }
  } else if (m > 1) //斜率超过45°，每次y自增1，x根据判别式增加
  {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    e = -0.5;
    x = p0.x();
    y = p0.y();
    while (y < p1.y()) {
      ptr->drawPoint(x, y);
      e = e + 1 / m;
      if (e > 0) {
        x = x + 1;
        e = e - 1;
      }
      y++;
    }
  } else {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    e = 0.5;
    x = p0.x();
    y = p0.y();
    while (y < p1.y()) {
      ptr->drawPoint(x, y);
      e = e + 1 / m;
      if (e < 0) {
        x--;
        e = e + 1;
      }
      y++;
    }
  }
  ptr->restore();
}
