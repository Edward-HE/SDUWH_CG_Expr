#include "widget.h"

Widget::Widget(QWidget* parent)
    : QOpenGLWidget(parent)
    , clearColor(Qt::yellow)
    , //设置背景颜色为黄色（可替换）
    xRot(70 * 16)
    , //初始的旋转角，从物体上方观察
    yRot(0)
    , zRot(40 * 16)
    , program(0)
{
}

Widget::~Widget()
{
    makeCurrent();
    buffer.destroy();
    delete texForDesk;
    delete texForBall;
    delete program;
    doneCurrent();
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();

    makeDeskAndBall(); //生成物体模型

    glEnable(GL_DEPTH_TEST); //开启深度测试
    glEnable(GL_CULL_FACE); //开启消隐

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_TEXCOORD_ATTRIBUTE 1
    //对着色器进行设置
    QOpenGLShader* vshader = new QOpenGLShader(QOpenGLShader::Vertex, this); //设置顶点着色器，对输入的顶点进行处理
    const char* vsrc = "attribute highp vec4 vertex;\n"
                       "attribute mediump vec4 texCoord;\n"
                       "varying mediump vec4 texc;\n"
                       "uniform mediump mat4 matrix;\n"
                       "void main(void)\n"
                       "{\n"
                       "    gl_Position = matrix * vertex;\n"
                       "    texc = texCoord;\n"
                       "}\n";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader* fshader = new QOpenGLShader(QOpenGLShader::Fragment, this); //设置片元着色器，对纹理进行插值等处理
    const char* fsrc = "uniform sampler2D texture;\n"
                       "varying mediump vec4 texc;\n"
                       "void main(void)\n"
                       "{\n"
                       "    gl_FragColor = texture2D(texture, texc.st);\n"
                       "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader); //添加着色器
    program->addShader(fshader); //添加着色器
    program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE); //绑定顶点坐标属性
    program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE); //绑定纹理坐标属性
    program->link(); //连接到上面加入的两个着色器

    program->bind(); //将着色器程序绑定到活动的OpenGL环境，并成为当前着色器程序
    program->setUniformValue("texture", 0); //将当前环境中的纹理设置为0
}

void Widget::paintGL()
{
    glClearColor(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF()); //设置背景颜色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清空颜色缓存和深度缓存

    QMatrix4x4 m; //变换矩阵
    m.ortho(-0.5f, +0.5f, +0.5f, -0.5f, 4.0f, 15.0f); //设置视见体
    m.translate(0.0f, 0.0f, -10.0f);
    m.rotate(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
    m.rotate(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
    m.rotate(zRot / 16.0f, 0.0f, 0.0f, 1.0f);

    program->setUniformValue("matrix", m);
    program->enableAttributeArray(PROGRAM_VERTEX_ATTRIBUTE); //启用顶点坐标属性
    program->enableAttributeArray(PROGRAM_TEXCOORD_ATTRIBUTE); //启用纹理坐标属性
    program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 3, 5 * sizeof(GLfloat)); //设置数组，以float为数据类型，5个为一组，前三个为顶点坐标
    program->setAttributeBuffer(PROGRAM_TEXCOORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));
    //设置数组，以float为数据类型，5个为一组，后两个为纹理坐标

    for (int i = 0; i < 1026; ++i) {
        if (i < 26)
            texForDesk->bind(); //绑定桌面的纹理
        else
            texForBall->bind(); //绑定球面的纹理
        glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4); //每四个点画一个平面
    }
}

void Widget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Widget::keyPressEvent(QKeyEvent* event) //实现桌子的旋转
{
    if (event->key() == Qt::Key_Right)
        zRot -= 10 * 16; //旋转10°，16=1°
    if (event->key() == Qt::Key_Left)
        zRot += 10 * 16;
    update();
}

void Widget::makeDeskAndBall()
{
    static const int coords[26][4][3] = { //定义一个26个面的桌子，每个面的点按逆时针方向排序，让计算机知道哪一边是外面
        { { 5, 5, 8 }, { 5, -5, 8 }, { -5, -5, 8 }, { -5, 5, 8 } },
        { { -5, 5, 7 }, { -5, -5, 7 }, { 5, -5, 7 }, { 5, 5, 7 } },
        { { 5, 5, 8 }, { 5, 5, 7 }, { 5, -5, 7 }, { 5, -5, 8 } },
        { { 5, -5, 8 }, { 5, -5, 7 }, { -5, -5, 7 }, { -5, -5, 8 } },
        { { -5, -5, 8 }, { -5, -5, 7 }, { -5, 5, 7 }, { -5, 5, 8 } },
        { { -5, 5, 8 }, { -5, 5, 7 }, { 5, 5, 7 }, { 5, 5, 8 } },
        { { 4, 4, 0 }, { 3, 4, 0 }, { 3, 3, 0 }, { 4, 3, 0 } },
        { { 4, 4, 7 }, { 4, 4, 0 }, { 4, 3, 0 }, { 4, 3, 7 } },
        { { 4, 3, 7 }, { 4, 3, 0 }, { 3, 3, 0 }, { 3, 3, 7 } },
        { { 3, 3, 7 }, { 3, 3, 0 }, { 3, 4, 0 }, { 3, 4, 7 } },
        { { 3, 4, 7 }, { 3, 4, 0 }, { 4, 4, 0 }, { 4, 4, 7 } },
        { { -4, 4, 0 }, { -4, 3, 0 }, { -3, 3, 0 }, { -3, 4, 0 } },
        { { -4, 4, 0 }, { -4, 4, 7 }, { -4, 3, 7 }, { -4, 3, 0 } },
        { { -4, 3, 0 }, { -4, 3, 7 }, { -3, 3, 7 }, { -3, 3, 0 } },
        { { -3, 3, 0 }, { -3, 3, 7 }, { -3, 4, 7 }, { -3, 4, 0 } },
        { { -3, 4, 0 }, { -3, 4, 7 }, { -4, 4, 7 }, { -4, 4, 0 } },
        { { -3, -4, 0 }, { -3, -3, 0 }, { -4, -3, 0 }, { -4, -4, 0 } },
        { { -4, -4, 7 }, { -4, -4, 0 }, { -4, -3, 0 }, { -4, -3, 7 } },
        { { -4, -3, 7 }, { -4, -3, 0 }, { -3, -3, 0 }, { -3, -3, 7 } },
        { { -3, -3, 7 }, { -3, -3, 0 }, { -3, -4, 0 }, { -3, -4, 7 } },
        { { -3, -4, 7 }, { -3, -4, 0 }, { -4, -4, 0 }, { -4, -4, 7 } },
        { { 4, -4, 0 }, { 4, -3, 0 }, { 3, -3, 0 }, { 3, -4, 0 } },
        { { 4, -4, 0 }, { 4, -4, 7 }, { 4, -3, 7 }, { 4, -3, 0 } },
        { { 4, -3, 0 }, { 4, -3, 7 }, { 3, -3, 7 }, { 3, -3, 0 } },
        { { 3, -3, 0 }, { 3, -3, 7 }, { 3, -4, 7 }, { 3, -4, 0 } },
        { { 3, -4, 0 }, { 3, -4, 7 }, { 4, -4, 7 }, { 4, -4, 0 } }
    };

    QVector<GLfloat> vertData;
    //将点加入到数组中，之所以能这样加入点，是因为在前面已经设置过着色器、属性，并且还会在重绘函数中定义缓存数组的结构
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 定点
            vertData.append(0.05 * coords[i][j][0]); //乘0.05以调节物体大小
            vertData.append(0.05 * coords[i][j][1]);
            vertData.append(0.05 * (coords[i][j][2] - 6));
            // 纹理坐标
            vertData.append(j == 0 || j == 3);
            vertData.append(j == 0 || j == 1);
        }
    }
    float r, r1, k = 0.08, h, h1, up = 0.18; //k用于调整大小，up用于调整物体上下位置
    for (int i = 0; i < 10; ++i) { //将球体按照经度——维度模型分割成20*50个平面加入到数组
        r = qSin(M_PI_2 * i / 10);
        r1 = qSin(M_PI_2 * (1 + i) / 10);
        h = qCos(M_PI_2 * i / 10);
        h1 = qCos(M_PI_2 * (1 + i) / 10);
        for (int j = 0; j < 50; j++) {
            //北半球
            //添加顶点坐标
            vertData << k * r * qCos(M_PI * (j + 1) / 25);
            vertData << k * r * qSin(M_PI * (j + 1) / 25);
            vertData << k * h + up;
            //添加纹理坐标，0~1.0
            vertData << (float)(j + 1) / (float)51;
            vertData << (float)i / (float)21;

            vertData << k * r1 * qCos(M_PI * (j + 1) / 25);
            vertData << k * r1 * qSin(M_PI * (j + 1) / 25);
            vertData << k * h1 + up;
            vertData << (float)(j + 1) / (float)51;
            vertData << (float)(i + 1) / (float)21;

            vertData << k * r1 * qCos(M_PI * j / 25);
            vertData << k * r1 * qSin(M_PI * j / 25);
            vertData << k * h1 + up;
            vertData << (float)j / (float)51;
            vertData << (float)(i + 1) / (float)21;

            vertData << k * r * qCos(M_PI * j / 25);
            vertData << k * r * qSin(M_PI * j / 25);
            vertData << k * h + up;
            vertData << (float)j / (float)51;
            vertData << (float)i / (float)21;
            //南半球
            vertData << k * r * qCos(M_PI * j / 25);
            vertData << k * r * qSin(M_PI * j / 25);
            vertData << -k * h + up;
            vertData << (float)j / (float)51;
            vertData << (float)(21 - i) / (float)21;

            vertData << k * r1 * qCos(M_PI * j / 25);
            vertData << k * r1 * qSin(M_PI * j / 25);
            vertData << -k * h1 + up;
            vertData << (float)j / (float)51;
            vertData << (float)(21 - i - 1) / (float)21;

            vertData << k * r1 * qCos(M_PI * (j + 1) / 25);
            vertData << k * r1 * qSin(M_PI * (j + 1) / 25);
            vertData << -k * h1 + up;
            vertData << (float)(j + 1) / (float)51;
            vertData << (float)(21 - i - 1) / (float)21;

            vertData << k * r * qCos(M_PI * (j + 1) / 25);
            vertData << k * r * qSin(M_PI * (j + 1) / 25);
            vertData << -k * h + up;
            vertData << (float)(j + 1) / (float)51;
            vertData << (float)(21 - i) / (float)21;
        }
    }

    texForDesk = new QOpenGLTexture(QImage(QString(":/images/images/1.bmp")).mirrored()); //生成桌子纹理对象
    texForBall = new QOpenGLTexture(QImage(QString(":/images/images/2.bmp")).mirrored()); //生成球纹理对象
    buffer.create();
    buffer.bind(); //绑定到OpenGL环境
    buffer.allocate(vertData.constData(), vertData.count() * sizeof(GLfloat)); //将数组加入到缓存中
}
