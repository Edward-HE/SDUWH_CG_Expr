#ifndef LINE_H
#define LINE_H
#include <QObject>
#include <QPoint>
#include <QPolygon>
#include <QPainter>
#include <QtMath>
#include <QVector>
const double PI = 3.1415926;


class Line
{
private:
    bool initStart;//起点初始化标志
    bool initEnd;//终点初始化标志
    QPoint start;//线段起点
    QPoint end;//线段终点
    int gi;//引力场强度
    QPolygon gravity;//引力场区域

public:
    Line();
    Line(QPoint start, QPoint end);
        void setStart(QPoint start);//设置起点
        void setEnd(QPoint end);//设置终点
        QPoint getStart();//获取起点
        QPoint getEnd();//获取终点
        QPoint getClosestPoint(QPoint point);//返回线段上离指定点最近的点
        bool ptInGravity(QPoint point);//判断指定点是否在线段的引力场内
        void setGravityIntensity(int intensity);//设置引力强度：引力场的范围大小
        void drawGravity(QPainter* pt);//绘制引力场
        void draw(QPainter* pt);//绘制线段
protected:
    void initGravity();//初始化引力场

};

#endif // LINE_H
