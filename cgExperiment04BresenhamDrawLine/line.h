#ifndef LINE_H
#define LINE_H
#include <QColor>
#include <QPainter>
#include <QPoint>

class line {
private:
  QPoint p0;
  QPoint p1;
  QColor color;

public:
  line(QPoint p0, QPoint p1, QColor color);
  void showLineInBresenham(QPainter *ptr);
};

#endif // LINE_H
