#ifndef PROJECTIONWIDGET_H
#define PROJECTIONWIDGET_H

#include <QWidget>
#include <object3d.h>
class projectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit projectionWidget(QWidget *parent = nullptr);
public:
    object3d o3d;
    void paintEvent(QPaintEvent*);
signals:

};

#endif // PROJECTIONWIDGET_H
