#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  points.append(
      QPoint(ui->lineEdit_x0->text().toInt(),
             ui->lineEdit_y0->text().toInt() + ui->mainToolBar->height()));
  points.append(
      QPoint(ui->lineEdit_x1->text().toInt(),
             ui->lineEdit_y1->text().toInt() + ui->mainToolBar->height()));
  color = ui->frame_color->palette().background().color();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::paintEvent(QPaintEvent *) {
  int w = ui->groupBox_set->width();
  int h = ui->groupBox_set->height();
  int x = width() - w - 10;
  int y = ui->groupBox_set->y();
  ui->groupBox_set->setGeometry(QRect(x, y, w, h));
  QPainter *ptr = new QPainter(this);
  if (points.size() >= 2) {
    ptr->save();
    ptr->setPen(color);
    ptr->drawLine(points[0], points[1]);
    ptr->restore();
  }
  delete ptr;
}

void MainWindow::on_pushButton_color_clicked() {
  color = QColorDialog::getColor();
  ui->frame_color->setPalette(QPalette(color));
}

void MainWindow::on_pushButton_ok_clicked() {
  points[0] =
      QPoint(ui->lineEdit_x0->text().toInt(),
             ui->lineEdit_y0->text().toInt() + ui->mainToolBar->height());
  points[1] =
      QPoint(ui->lineEdit_x1->text().toInt(),
             ui->lineEdit_y1->text().toInt() + ui->mainToolBar->height());
  update();
}
