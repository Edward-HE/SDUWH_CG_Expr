#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QRect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void paintEvent(QPaintEvent *);
  bool lineClip(QPoint &p0, QPoint &p1, QRect rt);
  char getCSCode(int x, int y, QRect rt);
private slots:
  void on_pushButton_oldColor_clicked();

  void on_pushButton_newColor_clicked();

  void on_pushButton_ok_clicked();

private:
  Ui::MainWindow *ui;
  QColor oldColor, newColor;
  int x, y, w, h;
  int x0, y0, x1, y1;
};

#endif // MAINWINDOW_H
