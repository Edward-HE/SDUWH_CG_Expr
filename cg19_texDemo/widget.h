#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>
#include <QWidget>
#include <QtMath>
class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

private:
    QColor clearColor; //背景颜色
    int xRot; //x轴旋转量
    int yRot; //y轴旋转量
    int zRot; //z轴旋转量
    QOpenGLTexture* texForDesk; //桌子纹理指针
    QOpenGLTexture* texForBall; //球体纹理指针
    QOpenGLShaderProgram* program; //着色器
    QOpenGLBuffer buffer; //绘图缓冲

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void keyPressEvent(QKeyEvent* event);
    void makeDeskAndBall(); //建立桌子和球的模型
};
#endif // WIDGET_H
