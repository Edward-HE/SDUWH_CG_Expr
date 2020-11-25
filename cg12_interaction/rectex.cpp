//RectEx.cpp
#include "rectex.h"

RectEx::RectEx()
{
    status = RS_NORMAL; //初始化矩形为一般状态
    deflection = 0; //初始化旋转偏角为0
}

void RectEx::setRect(int x1, int y1, int x2, int y2)
{
    rectangle = QRect(QPoint(x1, y1), QPoint(x2, y2));
    centerPoint = rectangle.center();
    //初始化points数组，用于旋转
    if (!points.isEmpty())
        points.clear();
    points.append(QPoint(x1, y1));
    points.append(QPoint(x1, y2));
    points.append(QPoint(x2, y2));
    points.append(QPoint(x2, y1));
    pointstemp = points;
}

//设置上边
void RectEx::setTop(int top)
{
    rectangle.setTop(top);
}

//设置下边
void RectEx::setBottom(int bottom)
{
    rectangle.setBottom(bottom);
}

//设置左边
void RectEx::setLeft(int left)
{
    rectangle.setLeft(left);
}

//设置右边
void RectEx::setRight(int right)
{
    rectangle.setRight(right);
}

//设置状态
void RectEx::setStatus(int status)
{
    this->status = status;

    //在缩放结束后需规格化矩形，以便控制框具有正确的位置
    if (this->status == RS_NORMAL)
        rectangle.normalized();
}

//获取矩形状态
int RectEx::getStatus()
{
    return status;
}

//获取左上点
QPoint RectEx::topLeft()
{
    return rectangle.topLeft();
}

//获取右下点
QPoint RectEx::bottomRight()
{
    return rectangle.bottomRight();
}

//设置旋转中心
void RectEx::setCenterPoint(QPoint point)
{
    centerPoint = point;
    //for rotating
    deflection = 0; //重置旋转偏角为0
    points = pointstemp;
}

//设置控制框
void RectEx::setCtrlRects()
{
    /////////following shows the contrl rectangles
    /*
    O---O---O
    |		|
    O	O	O
    |		|
    O---O---O
    */

    int cx = centerPoint.x();
    int cy = centerPoint.y();

    if (status != RS_ROTATING) //非旋转情况
    {
        QRect rect(rectangle);
        int l = rect.left();
        int r = rect.right();
        int t = rect.top();
        int b = rect.bottom();
        int h = (l + r) / 2;
        int v = (t + b) / 2;
        if (!ctrlRects.isEmpty())
            ctrlRects.clear();
        ctrlRects.append(rectangle);
        ctrlRects.append(QRect(QPoint(l - 5, t - 5), QPoint(l + 5, t + 5)));
        ctrlRects.append(QRect(QPoint(l - 5, v - 5), QPoint(l + 5, v + 5)));
        ctrlRects.append(QRect(QPoint(l - 5, b - 5), QPoint(l + 5, b + 5)));
        ctrlRects.append(QRect(QPoint(h - 5, b - 5), QPoint(h + 5, b + 5)));
        ctrlRects.append(QRect(QPoint(r - 5, b - 5), QPoint(r + 5, b + 5)));
        ctrlRects.append(QRect(QPoint(r - 5, v - 5), QPoint(r + 5, v + 5)));
        ctrlRects.append(QRect(QPoint(r - 5, t - 5), QPoint(r + 5, t + 5)));
        ctrlRects.append(QRect(QPoint(h - 5, t - 5), QPoint(h + 5, t + 5)));
        ctrlRects.append(QRect(QPoint(cx - 5, cy - 5), QPoint(cx + 5, cy + 5)));
    } else //旋转情况
    {
        if (ctrlRects.isEmpty()) {
            QRect rect(rectangle);
            int l = rect.left();
            int r = rect.right();
            int t = rect.top();
            int b = rect.bottom();
            int h = (l + r) / 2;
            int v = (t + b) / 2;
            ctrlRects.append(rectangle);
            ctrlRects.append(QRect(QPoint(l - 5, t - 5), QPoint(l + 5, t + 5)));
            ctrlRects.append(QRect(QPoint(l - 5, v - 5), QPoint(l + 5, v + 5)));
            ctrlRects.append(QRect(QPoint(l - 5, b - 5), QPoint(l + 5, b + 5)));
            ctrlRects.append(QRect(QPoint(h - 5, b - 5), QPoint(h + 5, b + 5)));
            ctrlRects.append(QRect(QPoint(r - 5, b - 5), QPoint(r + 5, b + 5)));
            ctrlRects.append(QRect(QPoint(r - 5, v - 5), QPoint(r + 5, v + 5)));
            ctrlRects.append(QRect(QPoint(r - 5, t - 5), QPoint(r + 5, t + 5)));
            ctrlRects.append(QRect(QPoint(h - 5, t - 5), QPoint(h + 5, t + 5)));
            ctrlRects.append(QRect(QPoint(cx - 5, cy - 5), QPoint(cx + 5, cy + 5)));
        }
        QPoint pt1, pt2;
        int i;
        for (i = 0; i < 4; i++) //位于顶点的控制框
        {
            pt1 = pointstemp.at(i);
            ctrlRects.replace(i * 2 + 1, QRect(QPoint(pt1.x() - 5, pt1.y() - 5), QPoint(pt1.x() + 5, pt1.y() + 5)));
        }
        for (i = 0; i < 4; i++) //位于边中点的控制框
        {
            pt1 = pointstemp.at(i);
            pt2 = pointstemp.at((i + 1) % 4);
            ctrlRects.replace(i * 2 + 2, QRect(QPoint((pt1.x() + pt2.x()) / 2 - 5, (pt1.y() + pt2.y()) / 2 - 5), QPoint((pt1.x() + pt2.x()) / 2 + 5, (pt1.y() + pt2.y()) / 2 + 5)));
        }
        ctrlRects.replace(9, QRect(QPoint(cx - 5, cy - 5), QPoint(cx + 5, cy + 5)));
    }
}

QPoint RectEx::getTopLeft()
{
    return rectangle.topLeft();
}

QPoint RectEx::getBottonRight()
{
    return rectangle.bottomRight();
}

//返回指定点位于矩形的哪个控制框中
int RectEx::getCurrentCtrlRect(QPoint point)
{
    setCtrlRects(); //设置控制框
        //	if(m_Status == RS_TRANSLATING && m_CtrlRects[0].PtInRect(point))
        //		return 0;
        //	if(m_Status == RS_SCALING || m_Status == RS_ROTATING)
    for (int i = 9; i >= 0; i--)
        if (ctrlRects.at(i).contains(point))
            return i;
    return -1;
}

//移动矩形
void RectEx::offsetRect(QSize size)
{
    rectangle.translate(size.width(), size.height());
    //
    for (int i = 0; i < ctrlRects.length(); i++)
        ctrlRects[i].translate(size.width(), size.height());
}

//获取旋转角度，origin为旋转参考点，start为起点，end为终点
double RectEx::getAngle(QPoint origin, QPoint start, QPoint end)
{
    int aa = (start.y() - origin.y()) * (start.y() - origin.y()) + (start.x() - origin.x()) * (start.x() - origin.x());
    int bb = (end.y() - origin.y()) * (end.y() - origin.y()) + (end.x() - origin.x()) * (end.x() - origin.x());
    int cc = (end.y() - start.y()) * (end.y() - start.y()) + (end.x() - start.x()) * (end.x() - start.x());

    double cosagl = (aa + bb - cc) / (2 * qSqrt(aa) * qSqrt(bb)); //使用余弦定理计算角度
    int flag = 1; //角度正负系数，在屏幕坐标系中，顺时针为正，逆时针为负
    if (start.x() == origin.x()) //起始边垂直
    {
        flag = (start.y() > origin.y()) ? 1 : -1; //起始边向量方向(origin->start)，下正上负
        flag = (end.x() < start.x()) ? flag : -flag; //终点在起始边向量的右边为正左边为负
    } else //起始边不垂直
    {
        double k = (start.y() - origin.y()) / (double)(start.x() - origin.x()); //起始边斜率
        double t = (end.y() - start.y()) - k * (end.x() - start.x()); //终点相对于起始边的位置

        flag = (start.x() > origin.x()) ? 1 : -1; //起始边向量方向，右正左负
        flag = t > 0 ? flag : -flag; //终点在起始边向量的右边为正左边为负
    }

    return flag * qAcos(cosagl);
}

/**旋转矩形，p1为旋转起点，p2为旋转终点，
* change为假表示当前是旋转的中间过程，为真则结束旋转，记录旋转角度
* 原因是因为旋转叠代次数越多误差越大
**/
void RectEx::rotateRect(QPoint p1, QPoint p2, bool change)
{
    double agl = getAngle(centerPoint, p1, p2); //获取偏角
    agl += deflection; //累加偏角，agl变成相对于最原始状态的偏角

    double R[3][3]; //构造旋转矩阵
    R[0][0] = qCos(agl);
    R[0][1] = -qSin(agl);
    R[0][2] = centerPoint.x() * (1 - qCos(agl)) + centerPoint.y() * qSin(agl);
    R[1][0] = qSin(agl);
    R[1][1] = qCos(agl);
    R[1][2] = centerPoint.y() * (1 - qCos(agl)) - centerPoint.x() * qSin(agl);
    R[2][0] = 0;
    R[2][1] = 0;
    R[2][2] = 1;

    //生成新坐标
    for (int i = 0; i < 4; i++)
        pointstemp.replace(i, QPoint((int)(R[0][0] * points[i].x() + R[0][1] * points[i].y() + R[0][2]), (int)(R[1][0] * points[i].x() + R[1][1] * points[i].y() + R[1][2])));
    if (change) { //结束旋转时，记录当前偏角
        deflection = agl;
    }
}

//绘制矩形
void RectEx::draw(QPainter* pt)
{
    int i;

    switch (status) {
    case RS_NORMAL:
    case RS_TRANSLATING:
        pt->drawRect(rectangle);
        break;
    case RS_SCALING:
        setCtrlRects();
        for (i = 0; i < 9; i++)
            pt->drawRect(ctrlRects.at(i));
        break;
    case RS_ROTATING:
        setCtrlRects();
        pt->drawPolygon(pointstemp);
        for (i = 1; i < 10; i++)
            pt->drawEllipse(ctrlRects.at(i));
        break;
    }
}
