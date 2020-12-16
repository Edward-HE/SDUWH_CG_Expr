#ifndef WIDGETDRAW_H
#define WIDGETDRAW_H

#include <GL/glut.h>
#include <QColor>
#include <QGLWidget>
#include <QWidget>

class widgetDraw : public QGLWidget {
    Q_OBJECT
public:
    explicit widgetDraw(QWidget* parent = nullptr);

signals:
private:
    bool lightEnable;
    bool doubleFaceEnable;
    bool infiniteEnable;
    bool globalAmbientEnable;
    QColor diffuseColor;
    QColor specularColor;
    QColor ambientColor;
    int comboIndex;

public:
    void setLightEnable(bool flag);
    void setDoubleFaceEnable(bool flag);
    void setInfiniteEnable(bool flag);
    void setGlobalAmbientEnable(bool flag);
    void setDiffuseColor(QColor clr);
    void setSpecularColor(QColor clr);
    void setAmbientColor(QColor clr);
    void setComboIndex(int n);
    void paintGL();
    void colorChange(QColor clr, int mode);
    void render(int index);
    void initLight();
    void DrawScene();
};

#endif // WIDGETDRAW_H
