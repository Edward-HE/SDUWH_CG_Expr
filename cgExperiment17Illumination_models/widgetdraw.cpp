#include "widgetdraw.h"
widgetDraw::widgetDraw(QWidget* parent)
    : QGLWidget(parent)
{
    lightEnable = false;
    doubleFaceEnable = false;
    infiniteEnable = false;
    globalAmbientEnable = false;
    diffuseColor = QColor(Qt::black);
    specularColor = QColor(Qt::white);
    ambientColor = QColor(Qt::white);
    comboIndex = -1;
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
}

void widgetDraw::setLightEnable(bool flag)
{
    lightEnable = flag;
    update();
}

void widgetDraw::setDoubleFaceEnable(bool flag)
{
    doubleFaceEnable = flag;
    update();
}

void widgetDraw::setInfiniteEnable(bool flag)
{
    infiniteEnable = flag;
    update();
}

void widgetDraw::setGlobalAmbientEnable(bool flag)
{
    globalAmbientEnable = flag;
    update();
}

void widgetDraw::setDiffuseColor(QColor clr)
{
    diffuseColor = clr;
    update();
}

void widgetDraw::setSpecularColor(QColor clr)
{
    specularColor = clr;
    update();
}

void widgetDraw::setAmbientColor(QColor clr)
{
    ambientColor = clr;
    update();
}

void widgetDraw::setComboIndex(int n)
{
    comboIndex = n;
    update();
}

void widgetDraw::paintGL()
{
    glPolygonMode(GL_FRONT, GL_FILL); // 设置绘图模式
    glPolygonMode(GL_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH); // 平滑处理模式
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE); // 开启自动单位化
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    initLight(); //初始化光照设置
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0); // 设置背景颜色

    glViewport(0, 0, width(), height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // 设置观察者位置、方向。
    glDrawBuffer(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    render(comboIndex);

    if (lightEnable)
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);

    if (doubleFaceEnable)
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    if (infiniteEnable)
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE); // 远视点
    else
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // 近视点

    GLfloat model_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    if (globalAmbientEnable) {
        glPushAttrib(GL_LIGHTING_BIT);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    } else {
        glPopAttrib();
        colorChange(ambientColor, 1);
        colorChange(diffuseColor, 2);
        colorChange(specularColor, 3);
    }

    DrawScene();
}

void widgetDraw::colorChange(QColor clr, int mode)
{
    GLfloat r, g, b;
    r = clr.redF();
    g = clr.greenF();
    b = clr.blueF();
    switch (mode) {
    case 1: {
        GLfloat tempAmbient[] = { r, g, b, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, tempAmbient);
        break;
    }
    case 2: {
        GLfloat tempDiffuse[] = { r, g, b, 1.0f };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, tempDiffuse);
        break;
    }
    case 3: {
        GLfloat tempSpecular[] = { r, g, b, 1.0f };
        glLightfv(GL_LIGHT0, GL_SPECULAR, tempSpecular);
        break;
    }
    default:
        break;
    }
}

void widgetDraw::render(int index)
{
    GLfloat m_MaterialAmbient[][4] = {
        { 0.2f, 0.2f, 0.2f, 1.0f },
        { 0.25f, 0.20725f, 0.20725f, 1.0f },
        { 0.33f, 0.22f, 0.028f, 1.0f },
        { 0.05f, 0.05f, 0.0f, 1.0f },
        { 0.25f, 0.25f, 0.25f, 1.0f },
        { 0.02f, 0.17f, 0.02f, 1.0f }
    };

    GLfloat m_MaterialDiffuse[][4] = {
        { 0.8f, 0.8f, 0.8f, 1.0f },
        { 1.0f, 0.829f, 0.829f, 1.0f },
        { 0.78f, 0.57f, 0.11f, 1.0f },
        { 0.5f, 0.5f, 0.4f, 1.0f },
        { 0.4f, 0.4f, 0.4f, 1.0f },
        { 0.07f, 0.61f, 0.07f, 1.0f }
    };

    GLfloat m_MaterialSpecular[][4] = {
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { 0.297f, 0.297f, 0.297f, 1.0f },
        { 0.99f, 0.94f, 0.8f, 1.0f },
        { 0.7f, 0.7f, 0.04f, 1.0f },
        { 0.77f, 0.77f, 0.77f, 1.0f },
        { 0.63f, 0.73f, 0.63f, 1.0f }
    };
    // 高光系数，即镜面反射的指数
    GLfloat m_MaterialShininess[] = { 0.0f, 0.01f, 0.22f, 0.08f, 0.6f, 0.6f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_MaterialAmbient[index]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_MaterialDiffuse[index]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_MaterialSpecular[index]);
    glMaterialf(GL_FRONT, GL_SHININESS, m_MaterialShininess[index] * 128.0f);
}

void widgetDraw::initLight()
{
    GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f }; // 环境光颜色
    GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 漫反射颜色
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 镜面反射颜色
    GLfloat light_pos[] = { 0.0f, 3.0f, 3.0f, 0.0f }; // 光源位置
    glClearDepth(1.0f);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glEnable(GL_LIGHT0); // 激活光源0
    glEnable(GL_LIGHTING); // 开启光照
}

void widgetDraw::DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    GLfloat m_BackDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat m_emission[] = { 1.0f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_BACK, GL_DIFFUSE, m_BackDiffuse);

    glPushMatrix();
    glFrontFace(GL_CW);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.5, 0.0, -15.0);
    glRotatef(40.0f, 1.0f, 0.0f, 0.0f);
    GLUquadricObj* objCylinder = gluNewQuadric();
    gluCylinder(objCylinder, 1.6f, 1.6f, 1.4f, 32, 32);
    glPopMatrix();

    glFlush();
}
