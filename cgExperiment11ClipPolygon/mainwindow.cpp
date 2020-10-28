#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  n = ui->lineEdit_vertexNum->text().toInt();
  p[0].setX(ui->lineEdit_x0->text().toInt());
  p[0].setY(ui->lineEdit_y0->text().toInt());
  p[1].setX(ui->lineEdit_x1->text().toInt());
  p[1].setY(ui->lineEdit_y1->text().toInt());
  p[2].setX(ui->lineEdit_x2->text().toInt());
  p[2].setY(ui->lineEdit_y2->text().toInt());
  p[3].setX(ui->lineEdit_x3->text().toInt());
  p[3].setY(ui->lineEdit_y3->text().toInt());
  p[4].setX(ui->lineEdit_x4->text().toInt());
  p[4].setY(ui->lineEdit_y4->text().toInt());
  p[5].setX(ui->lineEdit_x5->text().toInt());
  p[5].setY(ui->lineEdit_y5->text().toInt());
  p[6].setX(ui->lineEdit_x6->text().toInt());
  p[6].setY(ui->lineEdit_y6->text().toInt());
  p[7].setX(ui->lineEdit_x7->text().toInt());
  p[7].setY(ui->lineEdit_y7->text().toInt());
  rect.setLeft(ui->lineEdit_topX->text().toInt());
  rect.setTop(ui->lineEdit_topY->text().toInt());
  rect.setWidth(ui->lineEdit_rectWidth->text().toInt());
  rect.setHeight(ui->lineEdit_rectHeight->text().toInt());
  oldColor = ui->frame_oldColor->palette().background().color();
  newColor = ui->frame_newColor->palette().background().color();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_oldColor_clicked() {
  oldColor = QColorDialog::getColor();
  ui->frame_oldColor->setPalette(QPalette(oldColor));
}

void MainWindow::on_pushButton_newColor_clicked() {
  newColor = QColorDialog::getColor();
  ui->frame_oldColor->setPalette(QPalette(newColor));
}

void MainWindow::on_pushButton_ok_clicked() {
  n = ui->lineEdit_vertexNum->text().toInt();
  p[0].setX(ui->lineEdit_x0->text().toInt());
  p[0].setY(ui->lineEdit_y0->text().toInt());
  p[1].setX(ui->lineEdit_x1->text().toInt());
  p[1].setY(ui->lineEdit_y1->text().toInt());
  p[2].setX(ui->lineEdit_x2->text().toInt());
  p[2].setY(ui->lineEdit_y2->text().toInt());
  p[3].setX(ui->lineEdit_x3->text().toInt());
  p[3].setY(ui->lineEdit_y3->text().toInt());
  p[4].setX(ui->lineEdit_x4->text().toInt());
  p[4].setY(ui->lineEdit_y4->text().toInt());
  p[5].setX(ui->lineEdit_x5->text().toInt());
  p[5].setY(ui->lineEdit_y5->text().toInt());
  p[6].setX(ui->lineEdit_x6->text().toInt());
  p[6].setY(ui->lineEdit_y6->text().toInt());
  p[7].setX(ui->lineEdit_x7->text().toInt());
  p[7].setY(ui->lineEdit_y7->text().toInt());
  rect.setLeft(ui->lineEdit_topX->text().toInt());
  rect.setTop(ui->lineEdit_topY->text().toInt());
  rect.setWidth(ui->lineEdit_rectWidth->text().toInt());
  rect.setHeight(ui->lineEdit_rectHeight->text().toInt());
  update();
}

void MainWindow::paintEvent(QPaintEvent *) {
  int w = ui->groupBox_set->width();
  int h = ui->groupBox_set->height();
  int x = width() - w - 10;
  int y = ui->groupBox_set->y();
  ui->groupBox_set->setGeometry(QRect(x, y, w, h));
  QVector<QPoint> points;
  for (int i = 0; i < n; i++)
    points.append(p[i]);
  if (points.size() < 3)
    return;

  QPainter *ptr = new QPainter(this);
  QPolygon poly(points);
  ptr->save();
  ptr->setPen(oldColor);
  ptr->drawRect(rect);
  ptr->drawPolygon(poly);
  ptr->restore();

  QPolygon poly1 = polyClip(poly, rect);
  if (poly1.size() < 3)
    return;
  ptr->save();
  ptr->setBrush(newColor);
  ptr->drawPolygon(poly1);
  ptr->restore();

  delete ptr;
}

QPolygon MainWindow::polyClip(QPolygon poly1, QRect &rect1) {
  int x0, y0, x1, y1;
  QPolygon py0, py1, py2, py3;
  //裁剪左边
  x0 = rect1.x();
  y0 = rect1.y() + rect1.height();
  x1 = rect1.x();
  y1 = rect1.y();
  py0 = edgeClip(poly1, QPoint(x0, y0), QPoint(x1, y1));
  //裁剪下边
  x0 = rect1.x() + rect1.width();
  y0 = rect1.y() + rect1.height();
  x1 = rect1.x();
  y1 = rect1.y() + rect1.height();
  py1 = edgeClip(py0, QPoint(x0, y0), QPoint(x1, y1));
  //裁剪右边
  x0 = rect1.x() + rect1.width();
  y0 = rect1.y();
  x1 = rect1.x() + rect1.width();
  y1 = rect1.y() + rect1.height();
  py2 = edgeClip(py1, QPoint(x0, y0), QPoint(x1, y1));
  //裁剪上边
  x0 = rect1.x();
  y0 = rect1.y();
  x1 = rect1.x() + rect1.width();
  y1 = rect1.y();
  py3 = edgeClip(py2, QPoint(x0, y0), QPoint(x1, y1));
  return py3;
}

QPolygon MainWindow::edgeClip(QPolygon poly1, QPoint p0, QPoint p1) {
  QVector<QPoint> v;
  int i;
  int m = poly1.length();
  QPoint s, p;
  QPoint pt;
  s = poly1.point(m - 1);
  for (i = 0; i < m; i++) {
    p = poly1.point(i);
    if (isInsideEdge(p, p0, p1)) //点p在边(p0,p1)的内侧
    {
      if (isInsideEdge(s, p0, p1)) //情况1
        v.append(p);
      else //情况4
      {
        pt = intersect(s, p, p0, p1);
        v.append(pt);
        v.append(p);
      }
    } else if (isInsideEdge(s, p0, p1)) { //情况2
      pt = intersect(s, p, p0, p1);
      v.append(pt);
    } //情况3没有输出
    s = p;
  }
  return QPolygon(v);
}

//判断点p位于矩形边(p0,p1)的内侧还是外侧
bool MainWindow::isInsideEdge(QPoint p, QPoint p0, QPoint p1) {
  if (p0.x() > p1.x()) //裁剪边为窗口的下边
  {
    if (p.y() <= p0.y())
      return true;
  } else if (p0.x() < p1.x()) //裁剪边为窗口的上边
  {
    if (p.y() >= p0.y())
      return true;
  } else if (p0.y() < p1.y()) //裁减边为窗口的右边
  {
    if (p.x() <= p0.x())
      return true;
  } else if (p0.y() > p1.y()) //裁减边为窗口的左边
  {
    if (p.x() >= p0.x())
      return true;
  }
  return false;
}

QPoint MainWindow::intersect(QPoint s, QPoint p, QPoint p0, QPoint p1) {
  double m;
  int x, y;
  if (p0.y() == p1.y()) //水平裁剪边
  {
    m = (double)(p.x() - s.x()) / (double)(p.y() - s.y());
    x = s.x() + (int)((p0.y() - s.y()) * m);
    y = p0.y();
  } else //竖直裁剪边
  {
    m = (double)(p.y() - s.y()) / (double)(p.x() - s.x());
    x = p0.x();
    y = s.y() + (int)((p0.x() - s.x()) * m);
  }
  return QPoint(x, y);
}
