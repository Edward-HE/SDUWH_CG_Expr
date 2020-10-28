#include "inpoint.h"

InPoint::InPoint() {
}

InPoint::InPoint(QPoint point, int jud) : point(point), judge(jud) {
}

void InPoint::setPoint(QPoint p) {
    this->point = p;
}

void InPoint::setJudge(int jud) {
    this->judge = jud;
}

QPoint InPoint::getPoint() {
    return point;
}

int InPoint::getJudge() {
    return judge;
}
