#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QPolygon>
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
  void on_pushButton_oldColor_clicked();

  void on_pushButton_newColor_clicked();

  void on_pushButton_ok_clicked();

private:
  Ui::MainWindow *ui;
  int n;
  QPoint p[8];
  QRect rect;
  QColor oldColor, newColor;

  QPolygon polyClip(QPolygon poly1, QRect &rect1);
  QPolygon edgeClip(QPolygon poly1, QPoint p0, QPoint p1);
  bool isInsideEdge(QPoint p, QPoint p0, QPoint p1);
  QPoint intersect(QPoint s, QPoint p, QPoint p0, QPoint p1);
};

#endif // MAINWINDOW_H
