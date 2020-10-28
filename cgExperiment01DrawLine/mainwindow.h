#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public:
  void paintEvent(QPaintEvent *);

private slots:
  void on_pushButton_color_clicked();
  void on_pushButton_ok_clicked();

private:
  QVector<QPoint> points;
  QColor color;

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
