#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "polygon.h"
#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void paintEvent(QPaintEvent *);

private slots:
  void on_pushButton_color_clicked();

  void on_pushButton_ok_clicked();

private:
  Ui::MainWindow *ui;
  QColor color;
  int n;
  QPoint p[8];
  QPoint seed;
};

#endif // MAINWINDOW_H
