#include "line.h"

line::line(QPoint p0, QPoint p1, QColor color) : p0(p0), p1(p1), color(color) {}

void line::showLineInDDA(QPainter *ptr) {
  int x, y;
  double m, tx, ty;
  QPoint temp;
  ptr->save();
  ptr->setPen(color);
  if (p0.y() == p1.y()) //水平边
  {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    for (x = p0.x(); x < p1.x(); x++)
      ptr->drawPoint(x, p0.y());
  } else if (p0.x() == p1.y()) //垂直边
  {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    for (y = p0.y(); y < p1.y(); y++)
      ptr->drawPoint(p0.x(), y);
  } else {
    m = (double)(p1.y() - p0.y()) / (double)(p1.x() - p0.x());
    if (m > -1 && m < 1) //斜率在-45°到45°之间
    {
      if (p0.x() > p1.x()) {
        temp = p0;
        p0 = p1;
        p1 = temp;
      }
      ty = p0.y();
      for (x = p0.x(); x < p1.y(); x++) {
        y = (int)(ty + 0.5);
        ptr->drawPoint(x, y);
        ty += m;
      }
    } else //斜率超过45°
    {
      if (p0.y() > p1.y()) {
        temp = p0;
        p0 = p1;
        p1 = temp;
      }
      tx = p0.x();
      for (y = p0.y(); y < p1.y(); y++) {
        x = (int)(tx + 0.5);
        ptr->drawPoint(x, y);
        tx += 1 / m;
      }
    }
  }
  ptr->restore();
}
