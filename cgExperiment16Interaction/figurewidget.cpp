//figureWidget.cpp
#include "figurewidget.h"

figureWidget::figureWidget(QWidget* parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(254, 254, 254)));
    setAutoFillBackground(true);
    setMouseTracking(true);
}

void figureWidget::paintEvent(QPaintEvent*)
{
    QPainter* pt = new QPainter(this);
    pt->setPen(QColor(Qt::black));
    QString pos;
    switch (currentShow) {
    case ID_SHOW_XY:
        pt->save();
        pt->setPen(QPen(QColor(0, 0, 0)));
        pos += QString::number(newPoint.x()) + "," + QString::number(newPoint.y());
        pt->drawText(newPoint.x() + 10, newPoint.y() + 10, pos);
        pt->restore();
        break;
    case ID_SHOW_RUBBERBAND:
        line.draw(pt);
        break;
    case ID_SHOW_TRANSLATE:
        rectangle.draw(pt);
        break;
    case ID_SHOW_SCALE:
        rectangle.draw(pt);
        break;
    case ID_SHOW_ROTATE:
        rectangle.draw(pt);
        break;
    case ID_SHOW_GRAVITY:
        gravityLine.draw(pt);
        gravityLine.drawGravity(pt);
        line.draw(pt);
        circle.draw(pt);
        break;
    case ID_SHOW_DIRECTIONAL:
        line.draw(pt);
        break;
    case ID_SHOW_GRID:
        grid.draw(pt);
        circle.draw(pt);
        break;
    case ID_SHOW_RULER:
        ruler.Show(rect(), pt);
        if (showVernier)
            ruler.ShowVernier(rect(), pt, newPoint);
        else
            ruler.HideVernier(rect(), pt);
        break;
    case ID_SHOW_GUIDE:
        rectangle.draw(pt);
        guide.ShowGuides(pt, rect(), oldPoint, vOrH, drawGuide);
        break;
    default:
        break;
    }
}

void figureWidget::Initialize()
{
    QRect rc = QRect(0, 0, this->width(), this->height());
    centerPoint = QPoint(this->width() / 2, this->height() / 2);
    oldPoint = centerPoint;
    //橡皮筋
    if (currentShow == ID_SHOW_RUBBERBAND) {
        line.setStart(centerPoint);
        line.setEnd(centerPoint);
    }
    //移动、比例尺、旋转
    rectangle.setRect(centerPoint.x() - 50, centerPoint.y() - 40, centerPoint.x() + 50, centerPoint.y() + 40);
    //引力场
    if (currentShow == ID_SHOW_GRAVITY) {
        gravityLine.setStart(QPoint(50, 200));
        gravityLine.setEnd(QPoint(400, 50));
        gravityLine.setGravityIntensity(20);
        line.setStart(centerPoint);
        line.setEnd(centerPoint);
        circle.setCircle(centerPoint, 5);
    }
    //网格
    if (currentShow == ID_SHOW_GRID) {
        QPoint point;
        int radius = (grid.getXSpacing() > 10) ? 10 : grid.getXSpacing() / 3;
        grid.setSize(rc);
        point = grid.getClosestPoint(centerPoint);
        circle.setCircle(point, radius);
    }
    if (currentShow == ID_SHOW_GUIDE) {
        rectangle.setRect(width() / 3, height() * 3 / 5, width() * 5 / 6, height() * 4 / 5);
    }
}

void figureWidget::mouseMoveEvent(QMouseEvent* event)
{
    switch (currentShow) {
    case ID_SHOW_XY:
        setCursor(Qt::CrossCursor);
        break;
    case ID_SHOW_RUBBERBAND:
        setCursor(Qt::ArrowCursor);
        break;
    case ID_SHOW_TRANSLATE:
        if (rectangle.getCurrentCtrlRect(event->pos()) == CR_SELF)
            setCursor(Qt::SizeAllCursor);
        else
            setCursor(Qt::ArrowCursor);
        break;
    case ID_SHOW_SCALE:
        switch (currentCtrlRect) {
        case CR_NORTHWEST:
        case CR_SOUTHEAST:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case CR_NORTHEAST:
        case CR_SOUTHWEST:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case CR_WEST:
        case CR_EAST:
            setCursor(Qt::SizeHorCursor);
            break;
        case CR_NORTH:
        case CR_SOUTH:
            setCursor(Qt::SizeVerCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
        }
        break;
    case ID_SHOW_ROTATE:
        if (rectangle.getCurrentCtrlRect(event->pos()) == CR_CENTER)
            setCursor(Qt::SizeAllCursor);
        else if (rectangle.getCurrentCtrlRect(event->pos()) == -1)
            setCursor(Qt::ArrowCursor);
        else
            setCursor(Qt::ArrowCursor);
        break;
    case ID_SHOW_GRID:
        if (circle.ptInCircle(event->pos()))
            setCursor(Qt::SizeAllCursor);
        else
            setCursor(Qt::ArrowCursor);
        break;
    case ID_SHOW_RULER:
        if (ruler.GetCursorPosition(event->pos()) == CP_CLIENT)
            setCursor(Qt::SizeAllCursor);
        else
            setCursor(Qt::ArrowCursor);
        break;
    case ID_SHOW_GUIDE:
        if (rectangle.getCurrentCtrlRect(event->pos()) == CR_SELF)
            setCursor(Qt::SizeAllCursor);
        else
            setCursor(Qt::ArrowCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
    if (!isOperating) {
        currentCtrlRect = rectangle.getCurrentCtrlRect(event->pos());
        isInCircle = circle.ptInCircle(event->pos());
        return;
    }

    switch (currentShow) {
    case ID_SHOW_XY:
        ID_SHOW_XY_Work(event->pos());
        break;
    case ID_SHOW_RUBBERBAND:
        ID_SHOW_RUBBERBAND_Work(event->pos());
        break;
    case ID_SHOW_TRANSLATE:
        ID_SHOW_TRANSLATE_Work(event->pos());
        break;
    case ID_SHOW_SCALE:
        ID_SHOW_SCALE_Work(event->pos());
        break;
    case ID_SHOW_ROTATE:
        ID_SHOW_ROTATE_Work(event->pos(), false);
        break;
    case ID_SHOW_GRAVITY:
        ID_SHOW_GRAVITY_Work(event->pos());
        break;
    case ID_SHOW_DIRECTIONAL:
        ID_SHOW_DIRECTIONAL_Work(event->pos());
        break;
    case ID_SHOW_GRID:
        ID_SHOW_GRID_Work(event->pos());
        break;
    case ID_SHOW_RULER:
        ID_SHOW_RULER_Work(event->pos());
        break;
    case ID_SHOW_GUIDE:
        ID_SHOW_GUIDE_Work(event->pos());
        break;
    default:
        break;
    }
    update();
}

void figureWidget::mousePressEvent(QMouseEvent* event)
{
    switch (currentShow) {
    case ID_SHOW_RUBBERBAND:
        line.setStart(event->pos());
        line.setEnd(event->pos());
        break;
    case ID_SHOW_ROTATE:
        currentCtrlRect = rectangle.getCurrentCtrlRect(event->pos());
        break;
    case ID_SHOW_SCALE:
        currentCtrlRect = rectangle.getCurrentCtrlRect(event->pos());
        break;
    case ID_SHOW_RULER:
        showVernier = false;
        update();
        break;
    case ID_SHOW_GUIDE:
        drawGuide = guide.isInRuler(event->pos());
        vOrH = guide.isVRuler(event->pos());
        break;
    default:
        break;
    }
    if (!isInitialized) {
        Initialize();
        isInitialized = true;
    }
    startOperat();
    oldPoint = event->pos();
    update();
}

void figureWidget::mouseReleaseEvent(QMouseEvent* event)
{
    stopOperat();
    if (currentShow == ID_SHOW_ROTATE)
        ID_SHOW_ROTATE_Work(event->pos(), true);
    if (currentShow == ID_SHOW_GUIDE)
        if (drawGuide && guide.isInClient(event->pos()))
            guide.setLine(vOrH == true, event->pos());
}

void figureWidget::setcurrentShow(int cur)
{
    currentShow = cur;

    switch (cur) {
    case ID_SHOW_TRANSLATE:
        rectangle.setStatus(RS_TRANSLATING);
        break;
    case ID_SHOW_SCALE:
        rectangle.setStatus(RS_SCALING);
        break;
    case ID_SHOW_ROTATE:
        rectangle.setStatus(RS_ROTATING);
        break;
    case ID_SHOW_GRID:
        grid.setSize(rect());
        break;
    case ID_SHOW_GUIDE:
        rectangle.setStatus(RS_TRANSLATING);
        break;
    default:
        break;
    }
    Initialize();
    update();
}

void figureWidget::startOperat()
{
    isOperating = true;
    update();
}

void figureWidget::stopOperat()
{
    isOperating = false;
    update();
}

void figureWidget::ID_SHOW_XY_Work(QPoint point)
{
    newPoint = point;
}

void figureWidget::ID_SHOW_RUBBERBAND_Work(QPoint point)
{
    line.setEnd(point);
}

void figureWidget::ID_SHOW_TRANSLATE_Work(QPoint point)
{
    currentCtrlRect = rectangle.getCurrentCtrlRect(point);
    if (currentCtrlRect == CR_SELF)
        rectangle.offsetRect(QSize(point.x() - oldPoint.x(), point.y() - oldPoint.y()));
    oldPoint = point;
}

void figureWidget::ID_SHOW_SCALE_Work(QPoint point)
{
    switch (currentCtrlRect) {
    case CR_NORTHWEST:
        rectangle.setTop(point.y());
        rectangle.setLeft(point.x());
        break;
    case CR_SOUTHEAST:
        rectangle.setRight(point.x());
        rectangle.setBottom(point.y());
        break;
    case CR_NORTHEAST:
        rectangle.setTop(point.y());
        rectangle.setRight(point.x());
        break;
    case CR_SOUTHWEST:
        rectangle.setBottom(point.y());
        rectangle.setLeft(point.x());
        break;
    case CR_WEST:
        rectangle.setLeft(point.x());
        break;
    case CR_EAST:
        rectangle.setRight(point.x());
        break;
    case CR_NORTH:
        rectangle.setTop(point.y());
        break;
    case CR_SOUTH:
        rectangle.setBottom(point.y());
        break;
    default:
        break;
    }
}

void figureWidget::ID_SHOW_ROTATE_Work(QPoint point, bool rot)
{
    switch (currentCtrlRect) {
    case CR_NORTHWEST:
    case CR_SOUTHEAST:
    case CR_NORTHEAST:
    case CR_SOUTHWEST:
    case CR_WEST:
    case CR_EAST:
    case CR_NORTH:
    case CR_SOUTH:
        rectangle.rotateRect(oldPoint, point, rot); //旋转矩形
        break;
    case CR_CENTER:
        rectangle.setCenterPoint(point); //改变旋转中心
        break;
    default:
        break;
    }
}

void figureWidget::ID_SHOW_GRAVITY_Work(QPoint point)
{
    line.setStart(QPoint(0, 0));
    if (gravityLine.ptInGravity(point))
        line.setEnd(gravityLine.getClosestPoint(point));
    else
        line.setEnd(point);
    circle.setCenter(line.getEnd());
}

void figureWidget::ID_SHOW_DIRECTIONAL_Work(QPoint point)
{
    QPoint start = line.getStart();
    if (start.x() != point.x())
        if ((point.y() - start.y()) < tan(3.1415926 / 8) * (point.x() - start.x()))
            line.setEnd(QPoint(point.x(), start.y()));
        else if ((point.y() - start.y()) > tan(3 * 3.1415926 / 8) * (point.x() - start.x()))
            line.setEnd(QPoint(start.x(), point.y()));
        else {
            int temp = ((point.x() - start.x()) > (point.y() - start.y())) ? (point.x() - start.x()) : (point.y() - start.y());
            if (point.x() > start.x() && point.y() > start.y())
                line.setEnd(QPoint(start.x() + temp, start.y() + temp));
            else if (point.x() < start.x() && point.y() < start.y())
                line.setEnd(QPoint(start.x() - temp, start.y() - temp));
            else if (point.x() > start.x())
                line.setEnd(QPoint(start.x() + temp, start.y() - temp));
            else
                line.setEnd(QPoint(start.x() - temp, start.y() + temp));
        }
    else
        line.setEnd(QPoint(start.x(), point.y()));
}

void figureWidget::ID_SHOW_GRID_Work(QPoint point)
{
    if (grid.getClosestPoint(point) != circle.getCenter())
        circle.setCenter(grid.getClosestPoint(point));
}

void figureWidget::ID_SHOW_RULER_Work(QPoint point)
{
    if (ruler.GetCursorPosition(point) == CP_CLIENT) {
        newPoint = point;
        showVernier = true;
    } else
        showVernier = false;
}

void figureWidget::ID_SHOW_GUIDE_Work(QPoint point)
{
    if (rectangle.getCurrentCtrlRect(point) == CR_SELF)
        rectangle.offsetRect(QSize(point.x() - oldPoint.x(), point.y() - oldPoint.y()));
    if (drawGuide && guide.isInClient(point))
        guide.setLine(vOrH == true, point);
    if (guide.getLine().dx() != 0 && guide.getLine().dy() == 0) {
        if ((rectangle.getTopLeft().y() - guide.getLine().p1().y()) < guide.getGravity() && (guide.getLine().p1().y() - rectangle.getTopLeft().y()) < guide.getGravity())
            rectangle.offsetRect(QSize(0, guide.getLine().p1().y() - rectangle.getTopLeft().y()));
        if ((rectangle.getBottonRight().y() - guide.getLine().p1().y()) < guide.getGravity() && (guide.getLine().p1().y() - rectangle.getBottonRight().y()) < guide.getGravity())
            rectangle.offsetRect(QSize(0, guide.getLine().p1().y() - rectangle.getBottonRight().y()));
    }
    if (guide.getLine().dx() == 0 && guide.getLine().dy() != 0) {
        if ((rectangle.getTopLeft().x() - guide.getLine().p1().x()) < guide.getGravity() && (guide.getLine().p1().x() - rectangle.getTopLeft().x()) < guide.getGravity())
            rectangle.offsetRect(QSize(guide.getLine().p1().x() - rectangle.getTopLeft().x(), 0));
        if ((rectangle.getBottonRight().x() - guide.getLine().p1().x()) < guide.getGravity() && (guide.getLine().p1().x() - rectangle.getBottonRight().x()) < guide.getGravity())
            rectangle.offsetRect(QSize(guide.getLine().p1().x() - rectangle.getBottonRight().x(), 0));
    }
    oldPoint = point;
}
