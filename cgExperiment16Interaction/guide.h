//Guide.h
#ifndef GUIDE_H
#define GUIDE_H
#include "rectex.h"
#include "ruler.h"
#include <QPainter>
#include <QVector>

class Guide {
private:
    int gravity;
    bool drawline;
    QLine line;
    Ruler ruler;

public:
    Guide();
    void ShowGuides(QPainter* pt, QRect win, QPoint point, bool vline, bool drawline);
    void SetGravity(int gravity);
    int getGravity();
    bool isInRuler(QPoint point);
    bool isVRuler(QPoint point);
    void setLine(bool vline, QPoint point);
    bool isInClient(QPoint point);
    QLine getLine();
};

#endif // GUIDE_H
