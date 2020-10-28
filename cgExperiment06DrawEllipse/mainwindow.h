#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QColor>
#include <QColorDialog>
#include <QPainter>
#include <QRect>
#include "ellipse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_color_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p0;
    int a, b;
    QColor color;
};

#endif // MAINWINDOW_H
