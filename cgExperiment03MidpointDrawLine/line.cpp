#include "line.h"

line::line(QPoint p0, QPoint p1, QColor color) : p0(p0), p1(p1), color(color) {}

void line::showLineInMidpoint(QPainter *ptr) {
  QPoint temp;
  double m; //斜率
  int d, dx, dy, dNE, dE, x, y;

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

  ptr->save();
  ptr->setPen(color);
  m = (double)(p1.y() - p0.y()) / (double)(p1.x() - p0.x());
  if (m > 0 && m <= 1) //斜率在0°到45°之间,每次x自增1，y根据dp判别式增加
  {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    dx = p1.x() - p0.x();  // delt x
    dy = p1.y() - p0.y();  // delt y
    d = dx - 2 * dy;       // d0的判别式
    dNE = 2 * dx - 2 * dy; // dp<=0时的d(p+1)递推式
    dE = -2 * dy;          // dp>0时的d(p+1)递推式
    x = p0.x();
    y = p0.y();
    while (x < p1.x()) {
      ptr->drawPoint(x, y);
      if (d <= 0) {
        d += dNE;
        y++;
      } else
        d += dE;
      x++;
    }
  } else if (m >= -1 && m < 0) //斜率在-45°到0°之间,每次x自增1
  {
    if (p0.x() > p1.x()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    dx = p1.x() - p0.x();   // delt x
    dy = p1.y() - p0.y();   // delt y
    d = -1 * dx - 2 * dy;   // d0的判别式
    dNE = -2 * dx - 2 * dy; // dp>=0时的d(p+1)递推式
    dE = -2 * dy;           // dp<0时的d(p+1)递推式
    x = p0.x();
    y = p0.y();
    while (x < p1.x()) {
      ptr->drawPoint(x, y);
      if (d >= 0) {
        d += dNE;
        y--;
      } else
        d += dE;
      x++;
    }
  } else if (m > 1) //斜率超过45°，每次y自增1，x根据判别式增加
  {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    dx = p1.x() - p0.x();
    dy = p1.y() - p0.y();
    d = dy - 2 * dx;
    dNE = 2 * dy - 2 * dx;
    dE = -2 * dx;
    x = p0.x();
    y = p0.y();
    while (y < p1.y()) {
      ptr->drawPoint(x, y);
      if (d <= 0) {
        d += dNE;
        x++;
      } else
        d += dE;
      y++;
    }
  } else //斜率小于-45°，每次y自减1，x根据判别式增加
  {
    if (p0.y() > p1.y()) {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }
    dx = p1.x() - p0.x();   // delt x
    dy = p1.y() - p0.y();   // delt y
    d = -1 * dy - 2 * dx;   // d0的判别式
    dNE = -2 * dy - 2 * dx; // dp>=0时的d(p+1)递推式
    dE = -2 * dx;           // dp<0时的d(p+1)递推式
    x = p0.x();
    y = p0.y();
    while (y < p1.y()) {
      ptr->drawPoint(x, y);
      if (d >= 0) {
        d += dNE;
        x--;
      } else
        d += dE;
      y++;
    }
  }
  ptr->restore();
}
