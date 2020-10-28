#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "circle.h"
#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>

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
  QPoint p0;
  int r;
  QColor color;
};

#endif // MAINWINDOW_H
