#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter* ptr = new QPainter(this);
    ui->widget_draw->setFixedSize(width(), height());
    delete ptr;
}
void MainWindow::on_action_lineFrame_triggered()
{
    ui->widget_draw->setLineFrame();
}

void MainWindow::on_action_surface_triggered()
{
    ui->widget_draw->setSurface();
}
