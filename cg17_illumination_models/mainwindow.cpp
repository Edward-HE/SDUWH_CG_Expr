#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frameColor_ambient->setPalette(QPalette(Qt::black));
    ui->frameColor_diffuse->setPalette(QPalette(Qt::black));
    ui->frameColor_specular->setPalette(QPalette(Qt::black));
    ui->frameColor_diffuse->setPalette(QPalette(Qt::black));
    ui->frameColor_specular->setPalette(QPalette(Qt::white));
    ui->frameColor_ambient->setPalette(QPalette(Qt::white));


    setWindowTitle(tr("光照模型"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter* ptr = new QPainter(this);
    ui->widget_draw->setFixedSize(width()-185, height()-20);
    delete ptr;
}
void MainWindow::on_checkBox_lightEnable_stateChanged(int arg1)
{
    if(arg1)
        ui->widget_draw->setLightEnable(true);
    else
        ui->widget_draw->setLightEnable(false);
}

void MainWindow::on_checkBox_doubleFace_stateChanged(int arg1)
{
    if(arg1)
        ui->widget_draw->setDoubleFaceEnable(true);
    else
        ui->widget_draw->setDoubleFaceEnable(false);
}

void MainWindow::on_checkBox_infinite_stateChanged(int arg1)
{
    if(arg1)
        ui->widget_draw->setInfiniteEnable(true);
    else
        ui->widget_draw->setInfiniteEnable(false);
}

void MainWindow::on_checkBox_global_stateChanged(int arg1)
{
    if(arg1)
        ui->widget_draw->setGlobalAmbientEnable(true);
    else
        ui->widget_draw->setGlobalAmbientEnable(false);
}

void MainWindow::on_pushButton_diffuse_clicked()
{
    diffuseColor = QColorDialog::getColor(static_cast<int>(Qt::black));
    ui->frameColor_diffuse->setPalette(QPalette(diffuseColor));
    ui->widget_draw->setDiffuseColor(diffuseColor);
}

void MainWindow::on_pushButton_specular_clicked()
{
    specularColor = QColorDialog::getColor(static_cast<int>(Qt::black));
    ui->frameColor_specular->setPalette(QPalette(specularColor));
    ui->widget_draw->setSpecularColor(specularColor);
}

void MainWindow::on_pushButton_ambient_clicked()
{
    ambientColor = QColorDialog::getColor(static_cast<int>(Qt::black));
    ui->frameColor_ambient->setPalette(QPalette(ambientColor));
    ui->widget_draw->setAmbientColor(ambientColor);
}

void MainWindow::on_comboBox_material_activated(int index)
{
    ui->widget_draw->setComboIndex(index);
}

