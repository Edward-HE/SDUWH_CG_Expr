#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    isInWindow = false;
    isInView = false;

    wldOrg = QPoint(50, 120);               //记录世界坐标系原点
    scrOrg = QPoint(width() / 2 + 50, 120); //记录屏幕坐标系原点

    wldRect = QRect(0, 0, width() * 3 / 8, height() * 5 / 8);
    scrRect = wldRect;

    wldRect.translate(wldOrg);
    scrRect.translate(scrOrg);

    winRect = QRect(wldRect.width() * 1 / 8, wldRect.width() * 7 / 32, wldRect.width() * 6 / 8,
                    wldRect.width() * 18 / 32); //窗口矩形
    viewRect = winRect;                         //视口矩形

    winRect.translate(wldOrg);
    viewRect.translate(scrOrg);

    //初始化世界坐标系中的图形
    wldFigs.append(QRect(wldRect.width() / 20, wldRect.height() * 3 / 10, wldRect.width() * 17 / 20, wldRect.height() * 4 / 15));
    wldFigs.append(QRect(wldRect.width() * 11 / 26, wldRect.height() * 25 / 70, wldRect.width() * 5 / 13, wldRect.height() * 27 / 70));
    wldFigs.append(QRect(wldRect.width() / 10, wldRect.height() * 2 / 3, wldRect.width() * 17 / 30, wldRect.height() * 7 / 30));
    wldFigs.append(QRect(wldRect.width() * 3 / 10, wldRect.height() * 1 / 10, wldRect.width() * 9 / 20, wldRect.height() * 11 / 40));
    int i;
    for (i = 0; i < wldFigs.length(); i++)
        wldFigs[i].translate(wldOrg);

    //初始化屏幕坐标系中的图形
    scrFigs.resize(4);

    ui->spinBox_ww->setMaximum(wldRect.width() - 50);
    ui->spinBox_wh->setMaximum(wldRect.height() - 50);
    ui->spinBox_vw->setMaximum(scrRect.width() - 50);
    ui->spinBox_vh->setMaximum(scrRect.height() - 50);
    ui->spinBox_ww->setValue(winRect.width());
    ui->spinBox_wh->setValue(winRect.height());
    ui->spinBox_vw->setValue(viewRect.width());
    ui->spinBox_vh->setValue(viewRect.height());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::clip() {
    QRect wr;
    double sx = static_cast<double>(viewRect.width()) / winRect.width();
    double sy = static_cast<double>(viewRect.height()) / winRect.height();
    int dx = viewRect.x() - winRect.x();
    int dy = viewRect.y() - winRect.y();
    int xMin;
    int yMin;
    int uMin;
    int vMin;
    for (int i = 0; i < wldFigs.length(); i++) {
        wr = wldFigs[i].intersected(winRect);
        //当前矩形与窗口求交运算，得到裁剪后的矩形
        xMin = wr.x() - winRect.x();
        //当前矩形左上角相对于窗口左上角x坐标
        yMin = wr.y() - winRect.y();
        //当前矩形左上角相对于窗口左上角y坐标
        uMin = sx * xMin;               //当前矩形左上角相对于视口左上角x坐标
        vMin = sy * yMin;               //当前矩形左上角相对于视口左上角y坐标
        wr.translate(-xMin, -yMin);     //平移至窗口左上角
        wr.setWidth(sx * wr.width());   //沿x方向的放缩变换
        wr.setHeight(sy * wr.height()); //沿y方向的放缩变换
        wr.translate(dx, dy);           //平道至视口左上角
        wr.translate(uMin, vMin);       //平移至视口对应位置
        scrFigs[i] = wr;
    }
}

void MainWindow::drawRect(QPainter *ptr, QRect rect, QColor clr) {
    ptr->save();
    ptr->setPen(clr);
    ptr->drawRect(rect);
    ptr->restore();
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter *ptr = new QPainter(this);

    clip(); //对窗口中的图形进行裁剪，并变换到视口中去
            //生成视口中的图形数据
            // wldFigs -> scrFigs

    //显示标题
    double x, y, w, h;
    x = width() / 2 - 50.0;
    y = 80.0;
    w = 150.0;
    h = 20;
    ptr->save();
    ptr->setPen(Qt::red);
    ptr->drawText(QRectF(x, y, w, h), Qt::AlignCenter, tr("窗口到视口的变换"));
    ptr->restore();

    //处理世界坐标系
    ptr->save();
    ptr->setPen(Qt::blue);
    x = wldRect.x() + wldRect.width() / 2 - 20.0;
    y = wldRect.y() + 10.0;
    w = 40.0;
    ptr->drawText(QRectF(x, y, w, h), Qt::AlignCenter, tr("窗口"));
    ptr->setPen(Qt::green);
    x = wldRect.x() + wldRect.width() / 2 - 30.0;
    y = wldRect.y() + wldRect.height() - 30.0;
    w = 60.0;
    ptr->drawText(QRectF(x, y, w, h), Qt::AlignCenter, tr("世界坐标系"));
    ptr->restore();

    //处理屏幕坐标系
    ptr->save();
    ptr->setPen(Qt::blue);
    x = scrRect.x() + scrRect.width() / 2 - 20.0;
    y = scrRect.y() + 10.0;
    w = 40.0;
    ptr->drawText(QRectF(x, y, w, h), Qt::AlignCenter, tr("视口"));
    ptr->setPen(Qt::green);
    x = scrRect.x() + scrRect.width() / 2 - 30.0;
    y = scrRect.y() + scrRect.height() - 30.0;
    w = 60.0;
    ptr->drawText(QRectF(x, y, w, h), Qt::AlignCenter, tr("屏幕坐标系"));
    ptr->restore();

    //绘制世界坐标系图形
    drawRect(ptr, wldRect, Qt::green);
    drawRect(ptr, wldFigs[0], Qt::black);
    drawRect(ptr, wldFigs[1], Qt::black);
    drawRect(ptr, wldFigs[2], Qt::black);
    drawRect(ptr, wldFigs[3], Qt::black);
    drawRect(ptr, winRect, Qt::blue);

    //绘制屏幕坐标系图形
    drawRect(ptr, scrRect, Qt::green);
    drawRect(ptr, scrFigs[0], Qt::black);
    drawRect(ptr, scrFigs[1], Qt::black);
    drawRect(ptr, scrFigs[2], Qt::black);
    drawRect(ptr, scrFigs[3], Qt::black);
    drawRect(ptr, viewRect, Qt::blue);

    delete ptr;
}
void MainWindow::on_spinBox_ww_valueChanged(int arg1) {
    winRect.setWidth(arg1);
    clip();
    update();
}

void MainWindow::on_spinBox_wh_valueChanged(int arg1) {
    winRect.setHeight(arg1);
    clip();
    update();
}

void MainWindow::on_spinBox_vw_valueChanged(int arg1) {
    viewRect.setWidth(arg1);
    clip();
    update();
}

void MainWindow::on_spinBox_vh_valueChanged(int arg1) {
    viewRect.setHeight(arg1);
    clip();
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    QCursor csr;
    if (event->button() == Qt::LeftButton) {
        csr.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(csr);
        oldPos = event->pos();
        if (winRect.contains(event->pos()))
            isInWindow = true;
        else
            isInWindow = false;

        if (viewRect.contains(event->pos()))
            isInView = true;
        else
            isInView = false;
    }
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    QPoint newPos = event->pos();

    if (isInWindow)
        winRect.translate(newPos.x() - oldPos.x(), newPos.y() - oldPos.y());
    if (isInView)
        viewRect.translate(newPos.x() - oldPos.x(), newPos.y() - oldPos.y());
    oldPos = newPos;
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}
