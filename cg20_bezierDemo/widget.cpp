#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    resize(800, 600);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    point[0] = QPoint(100, 550); //控制点初始位置
    point[1] = QPoint(230, 200);
    point[2] = QPoint(590, 120);
    point[3] = QPoint(700, 500);
    t = INTERAL - 1;
    isMoving = false;
    nextPoint();
    timer.start(8);
    connect(&timer, SIGNAL(timeout()), this, SLOT(nextPoint()));
    //连接定时器信号和槽函数
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent* event)
{
    QPainter* pt = new QPainter(this);
    QPen pen;
    pen.setWidth(2); //设置线宽
    pen.setColor(QColor(Qt::blue));
    pt->setPen(pen);
    pt->drawLine(point[0], point[1]);
    pt->drawLine(point[1], point[2]);
    pt->drawLine(point[2], point[3]);
    pen.setColor(QColor(Qt::red));
    pt->setPen(pen);
    for (int i = 0; i < bezier.length(); ++i) {
        pt->drawPoint(bezier[i]); //画点和周围8个点
        pt->drawPoint(bezier[i] + QPoint(-1, -1));
        pt->drawPoint(bezier[i] + QPoint(0, -1));
        pt->drawPoint(bezier[i] + QPoint(1, -1));
        pt->drawPoint(bezier[i] + QPoint(-1, 0));
        pt->drawPoint(bezier[i] + QPoint(1, 0));
        pt->drawPoint(bezier[i] + QPoint(-1, 1));
        pt->drawPoint(bezier[i] + QPoint(0, 1));
        pt->drawPoint(bezier[i] + QPoint(1, 1));
    }
    pen.setColor(QColor(Qt::green));
    pt->setPen(pen);
    pt->drawLine(auxPoint[0], auxPoint[1]);
    pt->drawLine(auxPoint[1], auxPoint[2]);
    pen.setColor(QColor(Qt::yellow));
    pt->setPen(pen);
    pt->drawLine(auxPoint[3], auxPoint[4]);
    pen.setColor(QColor(Qt::black));
    pen.setWidth(1);
    pt->setPen(pen);
    for (int i = 0; i < 4; ++i)
        pt->drawEllipse(point[i].x() - 5, point[i].y() - 5, 10, 10);
    for (int i = 0; i < 6; ++i)
        pt->drawEllipse(auxPoint[i].x() - 5, auxPoint[i].y() - 5, 10, 10);
    if (isMoving) { //如果点被移动，在被移动的点和鼠标当前位置画一条虚线
        pen.setStyle(Qt::DashLine); //将线性设置为虚线
        pt->setPen(pen);
        pt->drawEllipse(tem.x() - 5, tem.y() - 5, 10, 10);
        pt->drawLine(tem, point[order]);
    }
}

void Widget::mousePressEvent(QMouseEvent* event)
{
    QPoint p = event->pos();
    if ((point[0].x() - p.x()) * (point[0].x() - p.x()) + (point[0].y() - p.y()) * (point[0].y() - p.y()) < 25) {
        order = 0;
        isMoving = true;
        return;
    }
    if ((point[1].x() - p.x()) * (point[1].x() - p.x()) + (point[1].y() - p.y()) * (point[1].y() - p.y()) < 25) {
        order = 1;
        isMoving = true;
        return;
    }
    if ((point[2].x() - p.x()) * (point[2].x() - p.x()) + (point[2].y() - p.y()) * (point[2].y() - p.y()) < 25) {
        order = 2;
        isMoving = true;
        return;
    }
    if ((point[3].x() - p.x()) * (point[3].x() - p.x()) + (point[3].y() - p.y()) * (point[3].y() - p.y()) < 25) {
        order = 3;
        isMoving = true;
        return;
    }
}

void Widget::mouseMoveEvent(QMouseEvent* event)
{
    if (isMoving)
        tem = event->pos();
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent* event)
{
    if (isMoving) {
        point[order] = tem; //把控制点移动到当前位置
        isMoving = false; //重新绘制贝塞尔曲线
        t = 0;
        nextPoint();
    }
}

void Widget::nextPoint()
{
    if (t == 0) {
        t = INTERAL - 1;
        bezier.clear();
    }
    //用插值公式生成负责点坐标
    auxPoint[0] = QPoint((point[0].x() * t + point[1].x() * (INTERAL - t)) / INTERAL, (point[0].y() * t + point[1].y() * (INTERAL - t)) / INTERAL);
    auxPoint[1] = QPoint((point[1].x() * t + point[2].x() * (INTERAL - t)) / INTERAL, (point[1].y() * t + point[2].y() * (INTERAL - t)) / INTERAL);
    auxPoint[2] = QPoint((point[2].x() * t + point[3].x() * (INTERAL - t)) / INTERAL, (point[2].y() * t + point[3].y() * (INTERAL - t)) / INTERAL);
    auxPoint[3] = QPoint((auxPoint[0].x() * t + auxPoint[1].x() * (INTERAL - t)) / INTERAL, (auxPoint[0].y() * t + auxPoint[1].y() * (INTERAL - t)) / INTERAL);
    auxPoint[4] = QPoint((auxPoint[1].x() * t + auxPoint[2].x() * (INTERAL - t)) / INTERAL, (auxPoint[1].y() * t + auxPoint[2].y() * (INTERAL - t)) / INTERAL);
    auxPoint[5] = QPoint((auxPoint[3].x() * t + auxPoint[4].x() * (INTERAL - t)) / INTERAL, (auxPoint[3].y() * t + auxPoint[4].y() * (INTERAL - t)) / INTERAL);
    bezier << auxPoint[5];
    --t;
    update();
}
