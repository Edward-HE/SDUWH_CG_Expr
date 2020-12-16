#include "widgetdraw.h"
//#include <GL/glut.h>
//#include <QGLWidget>
//#include <QMouseEvent>
//#include <QPainter>
//#include <QTime>
widgetDraw::widgetDraw(QWidget* parent)
    : QGLWidget(parent)
{
    isLine = false;
    m_angle = 0.0; //初始化旋转角
    id = startTimer(11);
    isTimer = true;
}
void widgetDraw::setLight()
{
    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 5.0 };
    GLfloat light_position[] = { 4.0, 4.0, 4.0, 0.0 };
    GLfloat light_color[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat lmodel_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0 };
    glClearColor(0.0, 0.0, 1.0, 1.0);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void widgetDraw::ground()
{
    glShadeModel(GL_SMOOTH);
    GLfloat fsize = 200.0, fyPos = -11;
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(fsize, fyPos, fsize);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(fsize, fyPos, -fsize);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-fsize, fyPos, -fsize);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-fsize, fyPos, fsize);
    glEnd();
}

void widgetDraw::GetShadeMatrix(Point4 lightPos, Point4 planeEquation, Matrix desMatrix)
{
    GLfloat dot;
    //点积，即数量积
    dot = planeEquation[0] * lightPos[0] + planeEquation[1] * lightPos[1] + planeEquation[2] * lightPos[2] + planeEquation[3] * lightPos[3];

    desMatrix[0] = dot - lightPos[0] * planeEquation[0];
    desMatrix[4] = 0.0f - lightPos[0] * planeEquation[1];
    desMatrix[8] = 0.0f - lightPos[0] * planeEquation[2];
    desMatrix[12] = 0.0f - lightPos[0] * planeEquation[3];

    desMatrix[1] = 0.0f - lightPos[1] * planeEquation[0];
    desMatrix[5] = dot - lightPos[1] * planeEquation[1];
    desMatrix[9] = 0.0f - lightPos[1] * planeEquation[2];
    desMatrix[13] = 0.0f - lightPos[1] * planeEquation[3];

    desMatrix[2] = 0.0f - lightPos[2] * planeEquation[0];
    desMatrix[6] = 0.0f - lightPos[2] * planeEquation[1];
    desMatrix[10] = dot - lightPos[2] * planeEquation[2];
    desMatrix[14] = 0.0f - lightPos[2] * planeEquation[3];

    desMatrix[3] = 0.0f - lightPos[3] * planeEquation[0];
    desMatrix[7] = 0.0f - lightPos[3] * planeEquation[1];
    desMatrix[11] = 0.0f - lightPos[3] * planeEquation[2];
    desMatrix[15] = dot - lightPos[3] * planeEquation[3];
}

void widgetDraw::setLineFrame()
{
    isLine = true;
    update();
    if (!isTimer) {
        id = startTimer(11);
        isTimer = true;
    }
}

void widgetDraw::setSurface()
{
    isLine = false;
    update();
    if (!isTimer) {
        id = startTimer(11);
        isTimer = true;
    }
}

void widgetDraw::timerEvent(QTimerEvent*)
{
    m_angle += 1.0;
    update();
}

void widgetDraw::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        if (!isTimer) {
            id = startTimer(11);
            isTimer = true;
        }
    } else if (event->button() == Qt::RightButton) {
        if (isTimer) {
            killTimer(id);
            isTimer = false;
        }
    }
}

void widgetDraw::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
}

void widgetDraw::paintGL()
{

    setLight(); //设置光照模型参数

    pSphere = gluNewQuadric();
    if (isLine)
        gluQuadricDrawStyle(pSphere, GLU_LINE); //设置线框的绘制方式
    else
        gluQuadricDrawStyle(pSphere, GLU_FILL); //设置曲面的绘制方式
    glViewport(0, 0, width(), height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width() / (float)height(), 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat light_position[4];
    Matrix desMatrix;
    Point4 planeEquation = { 0.0, 1.0, 0.0, 10.0 }; //平面方程为z+10=0.

    glGetLightfv(GL_LIGHT0, GL_POSITION, light_position); //获得光源位置
    GetShadeMatrix(light_position, planeEquation, desMatrix);

    //绘制光源
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glTranslatef(light_position[0], light_position[1], light_position[2]);
    gluSphere(pSphere, 0.2, 24, 18);
    glEnable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();

    //绘制地面
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    ground();
    glEnable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();

    //绘制阴影
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glMultMatrixf(desMatrix);
    glRotatef(m_angle, 0.0, 1.0, 0.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    gluCylinder(pSphere, 0.8, 2.0, 4.0, 20, 10);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();

    //绘制原物体
    glPushMatrix();
    glRotatef(m_angle, 0.0, 1.0, 0.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    gluCylinder(pSphere, 0.8, 2.0, 4.0, 20, 10);
    glPopMatrix();
}
