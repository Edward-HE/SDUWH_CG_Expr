#include "projectionwidget.h"

projectionWidget::projectionWidget(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(QColor(251,251,251)));
    setAutoFillBackground(true);
}
void projectionWidget::paintEvent(QPaintEvent*)
{
    QPainter* ptr = new QPainter(this);
    ptr->translate(52, 102);
    o3d.ShowProjection(ptr);
}
