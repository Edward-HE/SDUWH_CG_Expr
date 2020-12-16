#ifndef FIGUREWIDGET_H
#define FIGUREWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <QPoint>
#include <QPen>
#include <QColor>
#include <QRect>

#include "line.h"
#include "rectex.h"
#include "circle.h"
#include "grid.h"
#include "ruler.h"
#include "guide.h"
#define ID_SHOW_XY          0
#define ID_SHOW_RUBBERBAND  1
#define ID_SHOW_TRANSLATE   2
#define ID_SHOW_SCALE       3
#define ID_SHOW_ROTATE      4
#define ID_SHOW_GRAVITY     5
#define ID_SHOW_DIRECTIONAL 6
#define ID_SHOW_GRID        7
#define ID_SHOW_RULER       8
#define ID_SHOW_GUIDE       9

class figureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit figureWidget(QWidget *parent = nullptr);

signals:
public slots:
private:
    bool isInitialized;//是否初始化
    int currentShow;//当前演示项目
    bool isOperating;//是否开始演示
    QPoint centerPoint;//演示区中心点
    QPoint oldPoint;//用于记录以前的点
    QPoint newPoint;
    Line line;//直线
    Line gravityLine;//引力直线
    RectEx rectangle;//矩形
    Circle circle;//圆
    Grid grid;//网格
    Ruler ruler;//标尺
    bool showVernier;
    Guide guide;
    bool drawGuide;
    bool vOrH;
    int currentCtrlRect;//矩形的当前控制框
    bool isInCircle;//光标是否在圆中
public:
    void paintEvent(QPaintEvent*);
    void Initialize();//初始化函数
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setcurrentShow(int cur);
    void startOperat();
    void stopOperat();
    void ID_SHOW_XY_Work(QPoint point);
    void ID_SHOW_RUBBERBAND_Work(QPoint point);
    void ID_SHOW_TRANSLATE_Work(QPoint point);
    void ID_SHOW_SCALE_Work(QPoint point);
    void ID_SHOW_ROTATE_Work(QPoint point,bool rot);
    void ID_SHOW_GRAVITY_Work(QPoint point);
    void ID_SHOW_DIRECTIONAL_Work(QPoint point);
    void ID_SHOW_GRID_Work(QPoint point);
    void ID_SHOW_RULER_Work(QPoint point);
    void ID_SHOW_GUIDE_Work(QPoint point);

};

#endif // FIGUREWIDGET_H
