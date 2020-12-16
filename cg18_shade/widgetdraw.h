#ifndef WIDGETDRAW_H
#define WIDGETDRAW_H

#include <GL/glut.h>
#include <QGLWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QTime>
#include <QWidget>
typedef GLfloat Point3[3];
typedef GLfloat Point4[4];
typedef GLfloat Matrix[16];
class widgetDraw : public QGLWidget {
    Q_OBJECT
public:
    explicit widgetDraw(QWidget* parent = nullptr);
    void ground();
    void setLight();
    void GetShadeMatrix(Point4 lightPos, Point4 planeEquation, Matrix desMatrix);
    void setLineFrame();
    void setSurface();
    void paintGL();
    void timerEvent(QTimerEvent*);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
private:
    GLUquadricObj* pSphere;
    float m_angle;
    bool isLine;
    bool isTimer;
    int id;
};

#endif // WIDGETDRAW_H
