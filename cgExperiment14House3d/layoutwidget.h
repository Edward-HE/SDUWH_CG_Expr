#ifndef LAYOUTWIDGET_H
#define LAYOUTWIDGET_H

#include <QWidget>
#include <object3d.h>

class layoutWidget : public QWidget
{
    Q_OBJECT
public:
    explicit layoutWidget(QWidget *parent = nullptr);
public:
    object3d o3d;
    void paintEvent(QPaintEvent*);
signals:

};

#endif // LAYOUTWIDGET_H
