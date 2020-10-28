#ifndef EDGE_H
#define EDGE_H

class edge {
private:
  double x;  // 边的起始x坐标或边与扫描线的交点坐标
  double dx; // 边的斜率的倒数
  int ymax;  // 边的最大y坐标
public:
  edge();
  edge(double x, double dx, int ymax);
  void setX(double x);
  void setDx(double dx);
  void setYmax(int ymax);
  double getX() const;
  double getDx() const;
  int getYmax() const;
};

#endif // EDGE_H
