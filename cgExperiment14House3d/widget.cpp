#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_vrpx->setText("0");
    ui->lineEdit_vrpy->setText("0");
    ui->lineEdit_vrpz->setText("0");
    ui->lineEdit_theta->setText("0");
    ui->lineEdit_phi->setText("0");
    ui->lineEdit_delta->setText("0");
    ui->lineEdit_prpu->setText("250");
    ui->lineEdit_prpv->setText("100");
    ui->lineEdit_prpn->setText("250");
    ui->lineEdit_cwu->setText("0");
    ui->lineEdit_cwv->setText("0");
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent*)
{
    QPainter* ptr = new QPainter(this);
    ui->groupBox_set->setFixedSize(313, height() - 20);
    ui->splitter->setFixedSize(width() - 318, height() - 20);
}
void Widget::on_pushButton_apply_clicked()
{
    if (ui->radioButton_perspective->isChecked()) {
        ui->widget_1->o3d.setProjectionType(0);
        ui->widget_2->o3d.setProjectionType(0);
    } else {
        ui->widget_1->o3d.setProjectionType(1);
        ui->widget_2->o3d.setProjectionType(1);
    }

    ui->widget_1->o3d.setVRP(ui->lineEdit_vrpx->text().toInt(),
        ui->lineEdit_vrpy->text().toInt(),
        ui->lineEdit_vrpz->text().toInt());
    ui->widget_2->o3d.setVRP(ui->lineEdit_vrpx->text().toInt(),
        ui->lineEdit_vrpy->text().toInt(),
        ui->lineEdit_vrpz->text().toInt());

    ui->widget_1->o3d.setAngle(ui->lineEdit_theta->text().toInt(),
        ui->lineEdit_phi->text().toInt(),
        ui->lineEdit_delta->text().toInt());
    ui->widget_2->o3d.setAngle(ui->lineEdit_theta->text().toInt(),
        ui->lineEdit_phi->text().toInt(),
        ui->lineEdit_delta->text().toInt());

    ui->widget_1->o3d.setPRP(ui->lineEdit_prpu->text().toInt(),
        ui->lineEdit_prpv->text().toInt(),
        ui->lineEdit_prpn->text().toInt());
    ui->widget_2->o3d.setPRP(ui->lineEdit_prpu->text().toInt(),
        ui->lineEdit_prpv->text().toInt(),
        ui->lineEdit_prpn->text().toInt());

    ui->widget_1->o3d.setCW(ui->lineEdit_cwu->text().toInt(),
        ui->lineEdit_cwv->text().toInt());
    ui->widget_2->o3d.setCW(ui->lineEdit_cwu->text().toInt(),
        ui->lineEdit_cwv->text().toInt());

    ui->widget_1->update();
    ui->widget_2->update();
}

void Widget::on_pushButton_restore_clicked()
{
    ui->lineEdit_vrpx->setText("0");
    ui->lineEdit_vrpy->setText("0");
    ui->lineEdit_vrpz->setText("0");
    ui->lineEdit_theta->setText("0");
    ui->lineEdit_phi->setText("0");
    ui->lineEdit_delta->setText("0");
    ui->lineEdit_prpu->setText("250");
    ui->lineEdit_prpv->setText("100");
    ui->lineEdit_prpn->setText("250");
    ui->lineEdit_cwu->setText("0");
    ui->lineEdit_cwv->setText("0");

    ui->widget_1->o3d.setProjectionType(0);
    ui->widget_2->o3d.setProjectionType(0);

    ui->widget_1->o3d.setVRP(ui->lineEdit_vrpx->text().toInt(),
        ui->lineEdit_vrpy->text().toInt(),
        ui->lineEdit_vrpz->text().toInt());
    ui->widget_2->o3d.setVRP(ui->lineEdit_vrpx->text().toInt(),
        ui->lineEdit_vrpy->text().toInt(),
        ui->lineEdit_vrpz->text().toInt());

    ui->widget_1->o3d.setAngle(ui->lineEdit_theta->text().toInt(),
        ui->lineEdit_phi->text().toInt(),
        ui->lineEdit_delta->text().toInt());
    ui->widget_2->o3d.setAngle(ui->lineEdit_theta->text().toInt(),
        ui->lineEdit_phi->text().toInt(),
        ui->lineEdit_delta->text().toInt());

    ui->widget_1->o3d.setPRP(ui->lineEdit_prpu->text().toInt(),
        ui->lineEdit_prpv->text().toInt(),
        ui->lineEdit_prpn->text().toInt());
    ui->widget_2->o3d.setPRP(ui->lineEdit_prpu->text().toInt(),
        ui->lineEdit_prpv->text().toInt(),
        ui->lineEdit_prpn->text().toInt());

    ui->widget_1->o3d.setCW(ui->lineEdit_cwu->text().toInt(),
        ui->lineEdit_cwv->text().toInt());
    ui->widget_2->o3d.setCW(ui->lineEdit_cwu->text().toInt(),
        ui->lineEdit_cwv->text().toInt());

    ui->widget_1->update();
    ui->widget_2->update();
}
