#ifndef WIDGET_H
#define WIDGET_H

#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>
#define INTERAL 500 //画线的点的数量，表示每一次用多少个点来画贝塞尔曲线
class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    void nextPoint(); //生成下一个点
private:
    QPoint point[4]; //控制点
    QPoint auxPoint[6]; //辅助点
    QPoint tem; //移动控制点时用的临时点
    QVector<QPoint> bezier; //贝塞尔曲线
    bool isMoving;
    QTimer timer; //定时器
    int order; //移动的是第几个控制点
    int t; //插值公式的t*INTERAL
};
#endif // WIDGET_H
