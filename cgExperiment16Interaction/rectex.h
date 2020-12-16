#ifndef RECTEX_H
#define RECTEX_H

//RectEx.h
#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QVector>
#include <QtMath>

//定义矩形状态
#define RS_NORMAL 0 //普通
#define RS_TRANSLATING 1 //移动
#define RS_SCALING 2 //缩放
#define RS_ROTATING 3 //旋转
//定义点相对于矩形的位置
#define CR_SELF 0 //点在矩形内
#define CR_NORTHWEST 1 //点在矩形左上
#define CR_WEST 2 //点在矩形左中
#define CR_SOUTHWEST 3 //点在矩形左下
#define CR_SOUTH 4 //点在矩形下中
#define CR_SOUTHEAST 5 //点在矩形右下
#define CR_EAST 6 //点在矩形右中
#define CR_NORTHEAST 7 //点在矩形右上
#define CR_NORTH 8 //点在矩形上中
#define CR_CENTER 9 //点在矩形中心
class RectEx {
private:
    QPoint oldPoint;
    QRect rectangle;
    int status; //矩形当前状态
    QPoint centerPoint; //矩形的中心点
    QVector<QPoint> points; //矩形的原始顶点，用于旋转
    QVector<QPoint> pointstemp; //矩形的临时顶点，用于旋转
    double deflection; //旋转偏角
    QVector<QRect> ctrlRects; //矩形控制框
    void setCtrlRects(); //设置矩形的控制框
public:
    RectEx();
    QPoint getTopLeft();
    QPoint getBottonRight();
    void setRect(int x1, int y1, int x2, int y2); //设置矩形
    void setTop(int top); //设置矩形上边
    void setBottom(int bottom); //设置矩形下边
    void setLeft(int left); //设置矩形左边
    void setRight(int right); //设置矩形右边
    void setCenterPoint(QPoint point); //设置矩形中心
    void setStatus(int status); //设置矩形状态
    int getStatus(); //返回矩形状态
    QPoint topLeft(); //返回矩形的左上顶点
    QPoint bottomRight(); //返回矩形的右下顶点
    void offsetRect(QSize size); //移动矩形
    static double getAngle(QPoint origin, QPoint start, QPoint end); //根据点获取偏角
    void rotateRect(QPoint p1, QPoint p2, bool change = false); //旋转矩形
    int getCurrentCtrlRect(QPoint point); //返回指定点位于矩形的哪个控制框内
    void draw(QPainter* pt); //绘制矩形
};

#endif // RECTEX_H
