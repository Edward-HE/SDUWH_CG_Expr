#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  oldColor = ui->frame_oldColor->palette().background().color();
  newColor = ui->frame_newColor->palette().background().color();
  x = ui->lineEdit_leftx->text().toInt();
  y = ui->lineEdit_lefty->text().toInt();
  w = ui->lineEdit_w->text().toInt();
  h = ui->lineEdit_h->text().toInt();
  x0 = ui->lineEdit_x0->text().toInt();
  y0 = ui->lineEdit_y0->text().toInt();
  x1 = ui->lineEdit_x1->text().toInt();
  y1 = ui->lineEdit_y1->text().toInt();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::paintEvent(QPaintEvent *) {
  int ww = ui->groupBox_set->width();
  int hh = ui->groupBox_set->height();
  int xx = width() - ww - 10;
  int yy = ui->groupBox_set->y();
  ui->groupBox_set->setGeometry(QRect(xx, yy, ww, hh));

  QPainter *ptr = new QPainter(this);
  QPoint p0(x0, y0);
  QPoint p1(x1, y1);
  QRect rect(x, y, w, h);
  ptr->save();
  ptr->setPen(oldColor);
  ptr->drawLine(p0, p1);
  ptr->drawRect(rect);
  ptr->restore();

  if (lineClip(p0, p1, rect)) {
    ptr->save();
    ptr->setPen(newColor);
    ptr->drawLine(p0, p1);
    ptr->restore();
  }
  delete ptr;
}

bool MainWindow::lineClip(QPoint &p0, QPoint &p1, QRect rt) {
  bool accept, done;
  char c0, c1, code;
  int x0, y0, x1, y1, x, y;
  double m;
  accept = false; //线段可见标志
  done = false;   //裁剪完成标志
  x0 = p0.x();
  y0 = p0.y();
  x1 = p1.x();
  y1 = p1.y();
  c0 = getCSCode(x0, y0, rt); //返回线段起点的编码
  c1 = getCSCode(x1, y1, rt); //返回线段终点的编码
  while (!done) {
    if (!c0 && !c1) { //线段完全可见
      p0 = QPoint(x0, y0);
      p1 = QPoint(x1, y1);
      accept = true;
      done = true;
    } else if (c0 & c1) { //线段完全不可见
      p0 = QPoint(0, 0);
      p1 = QPoint(0, 0);
      accept = false;
      done = true;
    } else {    //处理非完全可见又非显然不可见的情况
      if (c0) { // p0不可见
        code = c0;
      } else { ////p0可见，则p1一定不可见
        code = c1;
      }
      if (code & 0x01) { //线段与窗口的左边有交
        x = rt.left();
        m = (double)(y1 - y0) / (double)(x1 - x0);
        y = y0 + (int)((x - x0) * m);
      } else if (code & 0x08) { //线段与窗口的下边有交
        y = rt.bottom();
        m = (double)(x1 - x0) / (double)(y1 - y0);
        x = x0 + (int)((y - y0) * m);
      } else if (code & 0x02) { //线段与窗口的右边有交
        x = rt.right();
        m = (double)(y1 - y0) / (double)(x1 - x0);
        y = y0 + (int)((x - x0) * m);
      } else if (code & 0x04) { //线段与窗口的上边有交
        y = rt.top();
        m = (double)(x1 - x0) / (double)(y1 - y0);
        x = x0 + (int)((y - y0) * m);
      }
      if (code == c0) {
        x0 = x;
        y0 = y;
        c0 = getCSCode(x0, y0, rt);
      } else {
        x1 = x;
        y1 = y;
        c1 = getCSCode(x1, y1, rt);
      }
    }
  }
  return accept;
}

char MainWindow::getCSCode(int x, int y, QRect rt) {
  char code = 0;
  if (x < rt.left()) //编码为***1,最后一位置1
    code = code | 0x01;
  else //编码为***0，最后一位置0
    code = code & 0xfe;
  if (x > rt.right()) //编码为**1*
    code = code | 0x02;
  else //编码为**0*
    code = code & 0xfd;
  if (y < rt.top()) //编码为*1**
    code = code | 0x04;
  else //编码为*0**
    code = code & 0xfb;
  if (y > rt.bottom()) //编码为1***
    code = code | 0x08;
  else //编码为0***
    code = code & 0xf7;
  return code;
}

void MainWindow::on_pushButton_oldColor_clicked() {
  oldColor = QColorDialog::getColor();
  ui->frame_oldColor->setPalette(QPalette(oldColor));
}

void MainWindow::on_pushButton_newColor_clicked() {
  newColor = QColorDialog::getColor();
  ui->frame_newColor->setPalette(QPalette(newColor));
}

void MainWindow::on_pushButton_ok_clicked() {
  x = ui->lineEdit_leftx->text().toInt();
  y = ui->lineEdit_lefty->text().toInt();
  w = ui->lineEdit_w->text().toInt();
  h = ui->lineEdit_h->text().toInt();
  x0 = ui->lineEdit_x0->text().toInt();
  y0 = ui->lineEdit_y0->text().toInt();
  x1 = ui->lineEdit_x1->text().toInt();
  y1 = ui->lineEdit_y1->text().toInt();
  update();
}
