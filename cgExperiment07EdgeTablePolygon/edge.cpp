#include "edge.h"

edge::edge() {}

edge::edge(double x, double dx, int ymax) : x(x), dx(dx), ymax(ymax) {}

void edge::setX(double x) { this->x = x; }

void edge::setDx(double dx) { this->dx = dx; }

void edge::setYmax(int ymax) { this->ymax = ymax; }

double edge::getX() const { return x; }

double edge::getDx() const { return dx; }

int edge::getYmax() const { return ymax; }
