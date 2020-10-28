#ifndef INPOINT_H
#define INPOINT_H
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QVector>
class InPoint {
    public:
    InPoint();
    InPoint(QPoint point, int jud);
    void setPoint(QPoint p);
    void setJudge(int jud);
    QPoint getPoint();
    int getJudge();

    private:
    QPoint point; //点的位置
    int judge;    // 1（入点）、2（出点）为交点，0为端点
};

#endif // INPOINT_H
