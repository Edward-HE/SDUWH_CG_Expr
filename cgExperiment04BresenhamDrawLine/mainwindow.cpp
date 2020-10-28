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

void MainWindow::on_pushButton_color_clicked() {
  color = QColorDialog::getColor();
  ui->frame_color->setPalette(QPalette(color));
}

void MainWindow::on_pushButton_ok_clicked() {
  points[0].setX(ui->lineEdit_x0->text().toInt());
  points[0].setY(ui->lineEdit_y0->text().toInt() + ui->mainToolBar->height());
  points[1].setX(ui->lineEdit_x1->text().toInt());
  points[1].setY(ui->lineEdit_y1->text().toInt() + ui->mainToolBar->height());
  update();
}

void MainWindow::paintEvent(QPaintEvent *) {
  int w = ui->groupBox_set->width();
  int h = ui->groupBox_set->height();
  int x = width() - w - 10;
  int y = ui->groupBox_set->y();
  ui->groupBox_set->setGeometry(QRect(x, y, w, h));

  QPainter *ptr = new QPainter(this);
  ptr->save();
  ptr->setPen(color);
  line l(points[0], points[1], color);
  l.showLineInBresenham(ptr);
  ptr->restore();
  delete ptr;
}
