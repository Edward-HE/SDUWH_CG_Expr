#include "line.h"

Line::Line()
    : initStart(false)
    , initEnd(false)
    , gi(3)
{

}
Line::Line(QPoint start, QPoint end)
    : start(start)
    , end(end)
    , initStart(false)
    , initEnd(false)
    , gi(3)
{
    initGravity();
}

void Line::setStart(QPoint start)
{
    this->start = start;
    initStart = true;
    initGravity();
}

void Line::setEnd(QPoint end)
{
    this->end = end;
    initEnd = true;
    initGravity();
}

QPoint Line::getStart()
{
    return start;
}

QPoint Line::getEnd()
{
    return end;
}

//绘线
void Line::draw(QPainter* pt)
{
    pt->drawLine(start, end);
}

//初始化引力场，使用哑铃模型
void Line::initGravity()
{
    if (!initStart || !initEnd)
        return;//只有当起点、终点都设置后才能初始化

    QVector<QPoint> vertex;
    int dx, dy;
    double k, t;
    if (end.x()==start.x()){//垂直线
        vertex.append(QPoint(start.x() - gi, start.y() - gi));
        vertex.append(QPoint(start.x() + gi, start.y() - gi));
        vertex.append(QPoint(end.x() + gi, end.y() + gi));
        vertex.append(QPoint(end.x() - gi, end.y() + gi));
    }
    else
    {
        k = static_cast<double>(end.y()-start.y())/(end.x()-start.x());//直线斜率
        t = qSqrt(1/(1 + k*k));
        dx = static_cast<int>(t*k*gi);
        dy = static_cast<int>(t*gi);

        vertex.append(QPoint(start.x() + dx, start.y() - dy));
        vertex.append(QPoint(start.x() - dx, start.y() + dy));
        vertex.append(QPoint(end.x() - dx, end.y() + dy));
        vertex.append(QPoint(end.x() + dx, end.y() - dy));
    }
    gravity = QPolygon(vertex);
}

//绘制引力场
void Line::drawGravity(QPainter* pt)
{
    initGravity();
    pt->save();
    pt->setPen(Qt::blue);

    double k = (double)(end.y() - start.y()) /
               (double)(end.x() - start.x());
    pt->drawLine(start, end);
    pt->drawArc(start.x() - 2*gi, start.y() - 2*gi,
                4*gi, 4*gi, 480 - 16*180*qAtan(k)/PI, 4800);
    pt->drawArc(end.x() - 2*gi, end.y() - 2*gi,
                4*gi, 4*gi, -180*16 + 30*16 - 16*180*qAtan(k)/PI, 4800);
    pt->drawLine(start+
            QPoint(2*gi*qCos(PI/6-qAtan(k)), -2*gi*qSin(PI/6-qAtan(k))),
            end+
            QPoint(2*gi*qCos(PI*5/6-qAtan(k)), -2*gi*qSin(PI*5/6-qAtan(k))));
    pt->drawLine(start+
            QPoint(2*gi*qCos(-PI/6-qAtan(k)), -2*gi*qSin(-PI/6-qAtan(k))),
            end+
            QPoint(2*gi*qCos(-PI*5/6-qAtan(k)), -2*gi*qSin(-PI*5/6-qAtan(k))));

    pt->restore();
}

//设置引力场强度
void Line::setGravityIntensity(int intensity)
{
    gi = intensity;
    initGravity();
}

//判断指定点是否在引力场区域内
bool Line::ptInGravity(QPoint point)
{
    QRegion rgn1 = QRegion(QRect(start.x() - 2*gi, start.y() - 2*gi, 4*gi, 4*gi), QRegion::Ellipse);
    QRegion rgn2 = QRegion(QRect(end.x() - 2*gi, end.y() - 2*gi, 4*gi, 4*gi), QRegion::Ellipse);
    QRegion rgn3 = QRegion(gravity, Qt::WindingFill);
    QRegion rgn = rgn1.united(rgn2.united(rgn3));
    if(rgn.contains(point))
        return true;
    else
        return false;
}

//返回线段上离指定点最近的点
QPoint Line::getClosestPoint(QPoint point)
{
    QPoint pt;
    int xt, yt;
    double k;
    //获取线段所在直线离指定点最近的点
    if (start.x() == end.x())//垂直线
    {
        pt.setX(start.x());
        pt.setY(point.y());
    }
    else
    {
        k = static_cast<double>(end.y()-start.y())/(end.x()-start.x());//线段斜率
        xt = static_cast<int>((k*(point.y()-start.y()+k*start.x())+point.x())/(1+k*k));
        yt = static_cast<int>((k*(point.x()-start.x()+k*point.y())+start.y())/(1+k*k));
        pt.setX(xt);
        pt.setY(yt);
    }

    //将点约束到线段上
    if (pt.x() < qMin(start.x(), end.x()))
        pt.setX(qMin(start.x(), end.x()));
    if (pt.x() > qMax(start.x(), end.x()))
        pt.setX(qMax(start.x(), end.x()));
    if (pt.y() < qMin(start.y(), end.y()))
        pt.setY(qMin(start.y(), end.y()));
    if (pt.y() > qMax(start.y(), end.y()))
        pt.setY(qMax(start.y(), end.y()));

    return pt;
}

