#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pn = ui->lineEdit_pn->text().toInt();
    pp[0].setX(ui->lineEdit_px0->text().toInt());
    pp[0].setY(ui->lineEdit_py0->text().toInt());
    pp[1].setX(ui->lineEdit_px1->text().toInt());
    pp[1].setY(ui->lineEdit_py1->text().toInt());
    pp[2].setX(ui->lineEdit_px2->text().toInt());
    pp[2].setY(ui->lineEdit_py2->text().toInt());
    pp[3].setX(ui->lineEdit_px3->text().toInt());
    pp[3].setY(ui->lineEdit_py3->text().toInt());
    pp[4].setX(ui->lineEdit_px4->text().toInt());
    pp[4].setY(ui->lineEdit_py4->text().toInt());
    pp[5].setX(ui->lineEdit_px5->text().toInt());
    pp[5].setY(ui->lineEdit_py5->text().toInt());
    pp[6].setX(ui->lineEdit_px6->text().toInt());
    pp[6].setY(ui->lineEdit_py6->text().toInt());
    pp[7].setX(ui->lineEdit_px7->text().toInt());
    pp[7].setY(ui->lineEdit_py7->text().toInt());
    vn = ui->lineEdit_vn->text().toInt();
    vp[0].setX(ui->lineEdit_vx0->text().toInt());
    vp[0].setY(ui->lineEdit_vy0->text().toInt());
    vp[1].setX(ui->lineEdit_vx1->text().toInt());
    vp[1].setY(ui->lineEdit_vy1->text().toInt());
    vp[2].setX(ui->lineEdit_vx2->text().toInt());
    vp[2].setY(ui->lineEdit_vy2->text().toInt());
    vp[3].setX(ui->lineEdit_vx3->text().toInt());
    vp[3].setY(ui->lineEdit_vy3->text().toInt());
    vp[4].setX(ui->lineEdit_vx4->text().toInt());
    vp[4].setY(ui->lineEdit_vy4->text().toInt());
    vp[5].setX(ui->lineEdit_vx5->text().toInt());
    vp[5].setY(ui->lineEdit_vy5->text().toInt());
    vp[6].setX(ui->lineEdit_vx6->text().toInt());
    vp[6].setY(ui->lineEdit_vy6->text().toInt());
    vp[7].setX(ui->lineEdit_vx7->text().toInt());
    vp[7].setY(ui->lineEdit_vy7->text().toInt());
    oldColor = ui->frame_oldColor->palette().background().color();
    newColor = ui->frame_newColor->palette().background().color();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_oldColor_clicked() {
    oldColor = QColorDialog::getColor();
    ui->frame_oldColor->setPalette(QPalette(oldColor));
}

void MainWindow::on_pushButton_newColor_clicked() {
    newColor = QColorDialog::getColor();
    ui->frame_oldColor->setPalette(QPalette(newColor));
}

void MainWindow::on_pushButton_ok_clicked() {
    pn = ui->lineEdit_pn->text().toInt();
    pp[0].setX(ui->lineEdit_px0->text().toInt());
    pp[0].setY(ui->lineEdit_py0->text().toInt());
    pp[1].setX(ui->lineEdit_px1->text().toInt());
    pp[1].setY(ui->lineEdit_py1->text().toInt());
    pp[2].setX(ui->lineEdit_px2->text().toInt());
    pp[2].setY(ui->lineEdit_py2->text().toInt());
    pp[3].setX(ui->lineEdit_px3->text().toInt());
    pp[3].setY(ui->lineEdit_py3->text().toInt());
    pp[4].setX(ui->lineEdit_px4->text().toInt());
    pp[4].setY(ui->lineEdit_py4->text().toInt());
    pp[5].setX(ui->lineEdit_px5->text().toInt());
    pp[5].setY(ui->lineEdit_py5->text().toInt());
    pp[6].setX(ui->lineEdit_px6->text().toInt());
    pp[6].setY(ui->lineEdit_py6->text().toInt());
    pp[7].setX(ui->lineEdit_px7->text().toInt());
    pp[7].setY(ui->lineEdit_py7->text().toInt());
    vn = ui->lineEdit_vn->text().toInt();
    vp[0].setX(ui->lineEdit_vx0->text().toInt());
    vp[0].setY(ui->lineEdit_vy0->text().toInt());
    vp[1].setX(ui->lineEdit_vx1->text().toInt());
    vp[1].setY(ui->lineEdit_vy1->text().toInt());
    vp[2].setX(ui->lineEdit_vx2->text().toInt());
    vp[2].setY(ui->lineEdit_vy2->text().toInt());
    vp[3].setX(ui->lineEdit_vx3->text().toInt());
    vp[3].setY(ui->lineEdit_vy3->text().toInt());
    vp[4].setX(ui->lineEdit_vx4->text().toInt());
    vp[4].setY(ui->lineEdit_vy4->text().toInt());
    vp[5].setX(ui->lineEdit_vx5->text().toInt());
    vp[5].setY(ui->lineEdit_vy5->text().toInt());
    vp[6].setX(ui->lineEdit_vx6->text().toInt());
    vp[6].setY(ui->lineEdit_vy6->text().toInt());
    vp[7].setX(ui->lineEdit_vx7->text().toInt());
    vp[7].setY(ui->lineEdit_vy7->text().toInt());
    update();
}

void MainWindow::paintEvent(QPaintEvent *) {
    //设置自动调整窗口大小
    int w = ui->groupBox_set->width();
    int h = ui->groupBox_set->height();
    int x = width() - w - 10;
    int y = ui->groupBox_set->y();
    ui->groupBox_set->setGeometry(QRect(x, y, w, h));

    //将输入的点从存放到vector中
    QVector<QPoint> points_p, points_v;
    for (int i = 0; i < pn; ++i)
        points_p.append(pp[i]);
    if (points_p.size() < 3)
        return;
    for (int i = 0; i < vn; ++i)
        points_v.append(vp[i]);
    if (points_v.size() < 3)
        return;

    //先分别画出窗口以及被裁减的多边形
    QPainter *ptr = new QPainter(this);
    QPolygon polyp(points_p);
    QPolygon polyv(points_v);
    ptr->save();
    ptr->setPen(oldColor);
    ptr->drawPolygon(polyp);
    ptr->drawPolygon(polyv);
    ptr->restore();

    //清理之前的绘图数据
    pLine.clear();
    vLine.clear();

    QPoint A, B;
    //对于被裁减多边形，从起点到终点的所有边顺时针插入多边形边链表
    for (int i = 0; i < pn - 1; ++i) {
        A.setX(pp[i].x());
        A.setY(pp[i].y());
        B.setX(pp[i + 1].x());
        B.setY(pp[i + 1].y());
        pLine.push_back(QLine(A, B));
        A = B;
    }
    B.setX(pp[0].x());
    B.setY(pp[0].y());
    pLine.push_back(QLine(A, B));

    //对于裁剪窗口，从起点到终点的所有边顺时针插入多边形边链表
    for (int i = 0; i < vn - 1; ++i) {
        A.setX(vp[i].x());
        A.setY(vp[i].y());
        B.setX(vp[i + 1].x());
        B.setY(vp[i + 1].y());
        vLine.push_back(QLine(A, B));
        A = B;
    }
    B.setX(vp[0].x());
    B.setY(vp[0].y());
    vLine.push_back(QLine(A, B));

    //根据线段表pLine、vLine得出交点表ppoint,vpoint
    SetPLane();

    QList<QPoint> PointInter; //裁剪之后的多边形的坐标
    QList<int> Num;           //每个裁剪后多边形的坐标个数，Num的size表示交集面的个数
    //根据插入好入点出点还有端点的序列ppoint、vpoint，找裁剪后的多边形
    BoolIntersection(PointInter, Num);

    ptr->save();
    ptr->setBrush(newColor);

    QList<QPoint>::iterator it;
    QList<int>::iterator itN;
    QVector<QPoint> points_ans; //保留每个裁剪后多边形的顶点
    it = PointInter.begin();
    for (itN = Num.begin(); itN != Num.end(); itN++) {
        points_ans.clear();
        for (int i = 0; i < *itN; i++) {
            points_ans.push_back(*it);
            it++;
        }
        ptr->drawPolygon(points_ans);
    }
    ptr->restore();

    delete ptr;
}
//根据pLine、vLine的边数据，计算出所有交点，保存在ppoint，vpoint
void MainWindow::SetPLane() {
    //先清空之前的绘图数据
    ppoint.clear();
    vpoint.clear();

    QList<QLine>::iterator itp, itv;
    QVector<double> t; //用于保存每条边与其他边相交时交点在线段上的位置
    QPoint tp;
    double tt; //对于线段A->B，tt<0代表交点在A左侧，tt==0代表在A，0<tt<1代表在AB中间，tt==1代表在B，tt>1代表在B右侧

    //对于多边形的每一条边，找到窗口的每一条边（看作线段）与那条边（看作直线）的交点
    for (itp = pLine.begin(); itp != pLine.end(); itp++) {
        for (itv = vLine.begin(); itv != vLine.end(); itv++) {
            if (IsInsect(itp->p1(), itp->p2(), itv->p1(), itv->p2(), tp, tt)) {
                t.push_back(tt);
            }
        }
        sort(t.begin(), t.end()); //把交点从小到大排序
        InPoint tInp;
        int nt = 0;
        int nt_in = 0;
        for (int i = 0; i < t.size(); i++) {
            if (i != 0 && t[i] == t[i - 1]) //避免相交在两条线段的同一个点导致出点入点判断失误的。
                continue;
            nt_in++; // 判断交点是出去还是进入 被2整除出 余1进

            if (t[i] <= 1)
                nt++; //统计小于1的个数 用于判断B点是否在内部 被2整除不在 余1在

            if (t[i] > 0 && t[i] <= 1) {
                tInp.setPoint(itp->p1() + (itp->p2() - itp->p1()) * t[i]);

                if (nt_in % 2 == 0)
                    tInp.setJudge(2); //交点，出点
                else
                    tInp.setJudge(1); // 交点，入点

                ppoint.push_back(tInp);
            }
        }
        tInp.setPoint(itp->p2());
        if (nt % 2 == 0)
            tInp.setJudge(0); //端点
        else
            tInp.setJudge(1); //交点，入点
        ppoint.push_back(tInp);
        t.clear();
    }

    //对于VIEW的每一条边，找到POLYGON的每一条边与那条边的交点
    for (itv = vLine.begin(); itv != vLine.end(); itv++) {
        for (itp = pLine.begin(); itp != pLine.end(); itp++) {
            if (IsInsect(itv->p1(), itv->p2(), itp->p1(), itp->p2(), tp, tt)) {
                t.push_back(tt);
            }
        }
        sort(t.begin(), t.end());
        InPoint tInp;
        int nt = 0;
        int nt_in = 0;
        for (int i = 0; i < t.size(); i++) {
            // if(i!=0&&t[i]==t[i-1])//避免相交在两条线段的同一个点导致出点入点判断失误的
            //     continue;
            nt_in++;
            if (t[i] <= 1)
                nt++; //统计小于1的个数（也就是B点之前交点的个数）用于判断B点是否在内部
                      //被2整除不在 余1在

            if (t[i] > 0 && t[i] <= 1) {
                tInp.setPoint(itv->p1() + (itv->p2() - itv->p1()) * t[i]);
                if (nt_in % 2 == 0)
                    tInp.setJudge(2); // 交点，出点
                else
                    tInp.setJudge(1); // 交点，入点
                vpoint.push_back(tInp);
            }
        }
        tInp.setPoint(itv->p2());
        if (nt % 2 == 0)
            tInp.setJudge(0); //端点在外部
        else
            tInp.setJudge(1); //端点在内部，当作入点标记
        vpoint.push_back(tInp);
        t.clear();
    }
}
//将搜索出的多边形顶点依次存入PointInter，Num记录每个多边形的顶点个数，Num序列的大小代表多边形的个数
void MainWindow::BoolIntersection(QList<QPoint> &PointInter, QList<int> &Num) {
    bool jumpP = true; // true代表跳转到被裁剪多边形，false代表跳转到窗口多边形
    int state = 0;     // 0代表在遍历被裁剪多边形
    QList<InPoint>::iterator itp, ittemp_back, ittemp;

    //先遍历ppoint
    itp = ppoint.begin();

    // P代表被裁剪多边形，V代表窗口多边形
    while (true) {
        if (itp->getJudge() == 1) { //如果是入点
            int Npoint = 0;
            PointInter.push_back(QPoint(itp->getPoint().x(), itp->getPoint().y()));
            Npoint++;
            int a = itp->getPoint().x();
            int b = itp->getPoint().y();
            ittemp_back = itp;
            itp++;
            ittemp = itp;

            //如果之前的跳转是跳转到P，那么现在跳转过来之后下次就跳转到V；反之亦然
            if (!jumpP)
                jumpP = true;
            else
                jumpP = false;

            //找到一个入点，以这个入点为起点找这个裁剪区域的其他点
            while (a != ittemp->getPoint().x() || b != ittemp->getPoint().y()) {
                if (ittemp->getJudge() == 1) //入点
                {
                    PointInter.push_back(QPoint(ittemp->getPoint().x(), ittemp->getPoint().y()));
                    ittemp->setJudge(3); // 标记已经pick的点
                    Npoint++;
                    ittemp_back = ittemp;
                    ittemp++;
                }                                 // end入点的情况
                else if (ittemp->getJudge() == 2) //出点，跳转
                {
                    PointInter.push_back(QPoint(ittemp->getPoint().x(), ittemp->getPoint().y()));
                    ittemp->setJudge(3); // 标记已经pick的点
                    Npoint++;
                    ittemp_back = ittemp;

                    if (!jumpP) { //应该跳转到V
                        ittemp = vpoint.begin();
                        jumpP = true; //表明下一次应该跳转到P
                    } else            //应该跳转到P
                    {
                        ittemp = ppoint.begin();
                        jumpP = false; //下一次跳转到V
                    }
                    //在跳转到的数组中找到对应的点
                    while (ittemp->getPoint().x() != ittemp_back->getPoint().x() ||
                           ittemp->getPoint().y() != ittemp_back->getPoint().y()) {
                        ittemp++;
                    }
                    ittemp->setJudge(3); // 标记已经pick的点
                    ittemp++;
                    if (ittemp->getJudge() == 0)
                        break; // 交点为一个的情况
                }              // end出点的情况

                if (!jumpP) {
                    if (ittemp == ppoint.end())
                        ittemp = ppoint.begin();
                } else {
                    if (ittemp == vpoint.end())
                        ittemp = vpoint.begin();
                }
            }
            Num.push_back(Npoint);
            Npoint = 0; //重新计数
        }               //找完一个裁剪后的区域了

        //继续找下一个点，作为裁剪区域的起点
        itp++;
        if (state == 0) {              //当前在遍历P数组
            if (itp == ppoint.end()) { //如果P数组遍历到结尾，那么下次从V开始，并且跳转标记为P
                itp = vpoint.begin();
                jumpP = true;
                state = 1;
            }
        } else { //当前在遍历V数组，V遍历结束，说明整个都结束了
            if (itp == vpoint.end())
                break;
        }
    } //搜索完全部的顶点序列了
}
//求向量a、b的数量积
double dot(const QPoint &a, const QPoint &b) {
    return a.x() * b.x() + a.y() * b.y();
}

//求直线AB与线段CD的交点，若有交点返回true，Insect代表交点，t代表直线AB与线段CD的交点在线段AB上的位置，运用定比分点公式
bool MainWindow::IsInsect(const QPoint A, const QPoint B, const QPoint C, const QPoint D, QPoint &Insect, double &t) {
    QPoint b = B - A; //向量
    QPoint d = D - C;
    QPoint c = C - A;

    QPoint d_V(d.y(), -d.x()); // d的垂线
    if (dot(b, d_V) == 0)
        return false; //平行
    else {
        t = dot(c, d_V) / dot(b, d_V);
        QPoint b_V(b.y(), -b.x());
        double u = dot(c, b_V) / dot(b, d_V);
        if (u < 0 || u > 1)
            return false; //线段不相交
        else {            //线段相交
            Insect = A + b * t;
            return true;
        }
    }
}
