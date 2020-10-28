#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "line.h"
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
  QVector<QPoint> points;
  QColor color;
};

#endif // MAINWINDOW_H
