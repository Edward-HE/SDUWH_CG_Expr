#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  p0.setX(ui->lineEdit_cx->text().toInt());
  p0.setY(ui->lineEdit_cy->text().toInt() + ui->mainToolBar->height());
  a = ui->lineEdit_a->text().toInt();
  b = ui->lineEdit_b->text().toInt();
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
  ellipse e(p0, a, b, color);
  e.showEllipse(ptr);
  delete ptr;
}

void MainWindow::on_pushButton_color_clicked() {
  color = QColorDialog::getColor();
  ui->frame_color->setPalette(QPalette(color));
}

void MainWindow::on_pushButton_ok_clicked() {
  p0.setX(ui->lineEdit_cx->text().toInt());
  p0.setY(ui->lineEdit_cy->text().toInt() + ui->mainToolBar->height());
  a = ui->lineEdit_a->text().toInt();
  b = ui->lineEdit_b->text().toInt();
  color = ui->frame_color->palette().background().color();
  update();
}
