#include "polygon.h"

polygon::polygon(QVector<QPoint> &points, QColor color)
    : points(points), color(color) {}

void polygon::showPolygonInEdgeTable(QPainter *ptr) {
  if (points.size() < 3)
    return;
  int i, j;
  int x0, x1, y, tx;

  int scanLines; //扫描线数量
  int min;       //最低扫描线号
  int max;       //最高扫描线号

  QVector<QList<edge>> ET; //边表
  QList<edge> AET;         //活化边表
  QVector<double> arr;     //扫描线与各边交点表

  QPoint p0;   //边的起点
  QPoint p1;   //边的终点
  QPoint temp; //保存位置变量
  edge *pNode; //边结点指针

  QVector<QList<edge>>::iterator iterET; //边表矢量迭代器
  QList<edge>::iterator iterEdge;        //边链表迭代器

  min = getMinY();
  max = getMaxY();
  scanLines = max - min;

  //建立边表ET
  ET.resize(scanLines);
  //逐边进行处理，将每一条边的信息插入到ET中
  for (i = 0; i < points.size(); i++) {
    if (i < points.size() - 1) {
      p0 = points[i];
      p1 = points[i + 1];
    } else {
      p0 = points[i];
      p1 = points[0];
    }

    if (p0.y() > p1.y()) //将p0设为边的起点坐标，y坐标较小
    {
      temp = p0;
      p0 = p1;
      p1 = temp;
    }

    if (p0.y() != p1.y()) //非水平边
    {
      pNode = new edge;
      pNode->setX(static_cast<double>(p0.x()));
      pNode->setDx(static_cast<double>(p1.x() - p0.x()) / (p1.y() - p0.y()));
      pNode->setYmax(p1.y() - 1); //下闭上开
      ET[p0.y() - min].append(*pNode);
    }
  } //所有边都已插入到ET中

  for (i = 0; i < scanLines; i++) // 开始扫描，各边依次加入到AET中
  {
    y = i + min;          //当前扫描线y坐标
    if (!ET[i].isEmpty()) //有边加入AET
    {
      for (iterEdge = ET[i].begin(); iterEdge != ET[i].end(); iterEdge++)
        AET.append(*iterEdge);
    }
    ET[i].clear(); //边结点已取出加入AET，无需保留

    //处理活化边表AET
    if (!AET.isEmpty()) //首先删除扫描线以下的边
    {
      for (iterEdge = AET.begin(); iterEdge != AET.end(); iterEdge++) {
        if (iterEdge->getYmax() < y) {
          AET.erase(iterEdge);
          iterEdge = AET.begin();
        }
      }
    }

    if (!AET.isEmpty()) //活化边表非空，求出交点，排序，画线
    {
      for (iterEdge = AET.begin(); iterEdge != AET.end(); iterEdge++) {
        arr.append(iterEdge->getX()); //取出所有交点
        iterEdge->setX(iterEdge->getX() + iterEdge->getDx());
      }
      sort(arr.begin(), arr.end()); //交点排序
      for (j = 0; j < arr.size(); j++) {
        if (j % 2 == 0) {
          tx = static_cast<int>(arr[j]); // 左边交点向右取整
          if (arr[j] - tx)
            x0 = tx + 1;
          else
            x0 = tx;
          x1 = static_cast<int>(arr[j + 1]); // 右边交点向左取整
        }
        ptr->save();
        ptr->setPen(color);
        ptr->drawLine(QPoint(x0, y), QPoint(x1, y));
        ptr->restore();
      }
      arr.clear();
    }
  } //所有扫描线处理完毕
  ET.clear();
}

int polygon::getMaxX() {
  int max = 0;
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->x() > max)
      max = iter->x();
  return max;
}

int polygon::getMinX() {
  int min = getMaxX();
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->x() < min)
      min = iter->x();
  return min;
}

int polygon::getMaxY() {
  int max = 0;
  QVector<QPoint>::iterator iter;
  for (iter = points.begin(); iter != points.end(); iter++)
    if (iter->y() > max)
      max = iter->y();
  return max;
}

int polygon::getMinY() {
  int min = getMaxY();
  QVector<QPoint>::iterator iterPos;
  for (iterPos = points.begin(); iterPos != points.end(); iterPos++)
    if (iterPos->y() < min)
      min = iterPos->y();
  return min;
}
