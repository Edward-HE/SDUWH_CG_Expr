#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  n = ui->lineEdit_n->text().toInt();
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
  color = ui->frame_color->palette().background().color();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_color_clicked() {
  color = QColorDialog::getColor();
  ui->frame_color->setPalette(QPalette(color));
}

void MainWindow::on_pushButton_ok_clicked() {
  n = ui->lineEdit_n->text().toInt();
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
  update();
}

void MainWindow::paintEvent(QPaintEvent *) {
  int w = ui->groupBox_set->width();
  int h = ui->groupBox_set->height();
  int x = width() - w - 10;
  int y = ui->groupBox_set->y();
  ui->groupBox_set->setGeometry(QRect(x, y, w, h));
  QPainter *ptr = new QPainter(this);
  QVector<QPoint> points;
  for (int i = 0; i < n; i++)
    points.append(p[i]);
  polygon poly(points, color);
  poly.showPolygonInEdgeFlag(ptr);
  delete ptr;
}
