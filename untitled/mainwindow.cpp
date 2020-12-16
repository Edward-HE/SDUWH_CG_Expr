#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //
    ui->setupUi(this);
    setWindowTitle(tr("interactive drawing"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter* pt = new QPainter(this);
    ui->splitter->setFixedSize(width(), height());
    //ui->widget1->setFixedSize(width()/3, height());
    //ui->widget2->setFixedSize(width()*2/3, height());
}
void MainWindow::on_action_C_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_XY);
    ui->widget1->setcurrentShow(ID_SHOW_XY);
    ui->widget1->startOperat();
}

void MainWindow::on_action_B_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_RUBBERBAND);
    ui->widget1->setcurrentShow(ID_SHOW_RUBBERBAND);
    ui->widget1->startOperat();
}

void MainWindow::on_action_T_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_TRANSLATE);
    ui->widget1->setcurrentShow(ID_SHOW_TRANSLATE);
    ui->widget1->startOperat();
}

void MainWindow::on_action_S_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_SCALE);
    ui->widget1->setcurrentShow(ID_SHOW_SCALE);
    ui->widget1->startOperat();
}

void MainWindow::on_action_R_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_ROTATE);
    ui->widget1->setcurrentShow(ID_SHOW_ROTATE);
    ui->widget1->startOperat();
}

void MainWindow::on_action_G_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_GRAVITY);
    ui->widget1->setcurrentShow(ID_SHOW_GRAVITY);
    ui->widget1->startOperat();
}

void MainWindow::on_action_D_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_DIRECTIONAL);
    ui->widget1->setcurrentShow(ID_SHOW_DIRECTIONAL);
    ui->widget1->startOperat();
}

void MainWindow::on_action_I_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_GRID);
    ui->widget1->setcurrentShow(ID_SHOW_GRID);
    ui->widget1->startOperat();
}

void MainWindow::on_action_U_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_RULER);
    ui->widget1->setcurrentShow(ID_SHOW_RULER);
    ui->widget1->startOperat();
}

void MainWindow::on_action_L_triggered()
{
    ui->widget2->setcurrentShow(ID_SHOW_GUIDE);
    ui->widget1->setcurrentShow(ID_SHOW_GUIDE);
    ui->widget1->startOperat();
}

