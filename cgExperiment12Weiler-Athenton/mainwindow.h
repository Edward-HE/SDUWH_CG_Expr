#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "inpoint.h"
#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QVector>
#include <algorithm>
#include <vector>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    private slots:
    void on_pushButton_oldColor_clicked();
    void on_pushButton_newColor_clicked();
    void on_pushButton_ok_clicked();

    private:
    Ui::MainWindow *ui;
    int pn;                //被裁剪的多边形顶点个数
    int vn;                //裁剪窗口的顶点个数
    QPoint pp[8];          //被裁剪的多边形的顶点
    QPoint vp[8];          //裁剪窗口的顶点
    QList<QLine> pLine;    //被裁剪的多边形的边
    QList<QLine> vLine;    //裁剪窗口的边
    QList<InPoint> ppoint; //被裁剪的多边形插入交点之后的序列
    QList<InPoint> vpoint; //裁剪窗口的插入交点之后的序列
    QColor oldColor, newColor;

    //根据pLine、vLine的边数据，计算出所有交点，保存在ppoint，vpoint
    void SetPLane();
    //求直线AB与线段CD的交点，若有交点返回true
    // t代表直线AB与线段CD的交点在线段AB上的位置，运用定比分点公式
    bool IsInsect(const QPoint A, const QPoint B, const QPoint C, const QPoint D, QPoint &Insect, double &t);
    //将搜索出的多边形顶点依次存入PointInter
    // Num记录每个多边形的顶点个数，Num序列的大小代表多边形的个数
    void BoolIntersection(QList<QPoint> &PointInter, QList<int> &Num);
};

#endif // MAINWINDOW_H
