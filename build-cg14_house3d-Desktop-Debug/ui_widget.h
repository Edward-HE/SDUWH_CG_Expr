/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "layoutwidget.h"
#include "projectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSplitter *splitter;
    layoutWidget *widget_1;
    projectionWidget *widget_2;
    QGroupBox *groupBox_set;
    QPushButton *pushButton_apply;
    QGroupBox *groupBox_projection;
    QLineEdit *lineEdit_n_2;
    QRadioButton *radioButton_parallel;
    QRadioButton *radioButton_perspective;
    QPushButton *pushButton_restore;
    QGroupBox *groupBox_vrp;
    QLineEdit *lineEdit_n_3;
    QLabel *label_x;
    QLineEdit *lineEdit_vrpx;
    QLabel *label_y;
    QLineEdit *lineEdit_vrpy;
    QLineEdit *lineEdit_vrpz;
    QLabel *label_z;
    QGroupBox *groupBox_angle;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_theta;
    QLabel *label_theta;
    QLabel *label_phi;
    QLineEdit *lineEdit_phi;
    QLabel *label_delta;
    QLineEdit *lineEdit_delta;
    QGroupBox *groupBox_prp;
    QLineEdit *lineEdit_n_5;
    QLabel *label_u;
    QLineEdit *lineEdit_prpu;
    QLabel *label_v;
    QLineEdit *lineEdit_prpv;
    QLineEdit *lineEdit_prpn;
    QLabel *label_n;
    QGroupBox *groupBox_cw;
    QLineEdit *lineEdit_n_6;
    QLabel *label_cwu;
    QLineEdit *lineEdit_cwu;
    QLabel *label_cwv;
    QLineEdit *lineEdit_cwv;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 650);
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(330, 20, 641, 591));
        splitter->setOrientation(Qt::Vertical);
        widget_1 = new layoutWidget(splitter);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        splitter->addWidget(widget_1);
        widget_2 = new projectionWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        splitter->addWidget(widget_2);
        groupBox_set = new QGroupBox(Widget);
        groupBox_set->setObjectName(QString::fromUtf8("groupBox_set"));
        groupBox_set->setGeometry(QRect(0, 0, 313, 611));
        pushButton_apply = new QPushButton(groupBox_set);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(20, 550, 93, 28));
        groupBox_projection = new QGroupBox(groupBox_set);
        groupBox_projection->setObjectName(QString::fromUtf8("groupBox_projection"));
        groupBox_projection->setGeometry(QRect(20, 50, 281, 71));
        lineEdit_n_2 = new QLineEdit(groupBox_projection);
        lineEdit_n_2->setObjectName(QString::fromUtf8("lineEdit_n_2"));
        lineEdit_n_2->setGeometry(QRect(-230, 340, 113, 21));
        radioButton_parallel = new QRadioButton(groupBox_projection);
        radioButton_parallel->setObjectName(QString::fromUtf8("radioButton_parallel"));
        radioButton_parallel->setGeometry(QRect(10, 30, 115, 19));
        radioButton_perspective = new QRadioButton(groupBox_projection);
        radioButton_perspective->setObjectName(QString::fromUtf8("radioButton_perspective"));
        radioButton_perspective->setGeometry(QRect(140, 30, 115, 19));
        pushButton_restore = new QPushButton(groupBox_set);
        pushButton_restore->setObjectName(QString::fromUtf8("pushButton_restore"));
        pushButton_restore->setGeometry(QRect(200, 550, 93, 28));
        groupBox_vrp = new QGroupBox(groupBox_set);
        groupBox_vrp->setObjectName(QString::fromUtf8("groupBox_vrp"));
        groupBox_vrp->setGeometry(QRect(20, 130, 281, 91));
        lineEdit_n_3 = new QLineEdit(groupBox_vrp);
        lineEdit_n_3->setObjectName(QString::fromUtf8("lineEdit_n_3"));
        lineEdit_n_3->setGeometry(QRect(-230, 340, 113, 21));
        label_x = new QLabel(groupBox_vrp);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setGeometry(QRect(20, 30, 21, 16));
        lineEdit_vrpx = new QLineEdit(groupBox_vrp);
        lineEdit_vrpx->setObjectName(QString::fromUtf8("lineEdit_vrpx"));
        lineEdit_vrpx->setGeometry(QRect(40, 30, 71, 21));
        label_y = new QLabel(groupBox_vrp);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setGeometry(QRect(130, 30, 21, 16));
        lineEdit_vrpy = new QLineEdit(groupBox_vrp);
        lineEdit_vrpy->setObjectName(QString::fromUtf8("lineEdit_vrpy"));
        lineEdit_vrpy->setGeometry(QRect(150, 30, 71, 21));
        lineEdit_vrpz = new QLineEdit(groupBox_vrp);
        lineEdit_vrpz->setObjectName(QString::fromUtf8("lineEdit_vrpz"));
        lineEdit_vrpz->setGeometry(QRect(40, 60, 71, 21));
        label_z = new QLabel(groupBox_vrp);
        label_z->setObjectName(QString::fromUtf8("label_z"));
        label_z->setGeometry(QRect(20, 60, 21, 16));
        groupBox_angle = new QGroupBox(groupBox_set);
        groupBox_angle->setObjectName(QString::fromUtf8("groupBox_angle"));
        groupBox_angle->setGeometry(QRect(20, 230, 281, 121));
        lineEdit = new QLineEdit(groupBox_angle);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(-230, 340, 113, 21));
        lineEdit_theta = new QLineEdit(groupBox_angle);
        lineEdit_theta->setObjectName(QString::fromUtf8("lineEdit_theta"));
        lineEdit_theta->setGeometry(QRect(100, 30, 91, 21));
        label_theta = new QLabel(groupBox_angle);
        label_theta->setObjectName(QString::fromUtf8("label_theta"));
        label_theta->setGeometry(QRect(30, 30, 61, 16));
        label_phi = new QLabel(groupBox_angle);
        label_phi->setObjectName(QString::fromUtf8("label_phi"));
        label_phi->setGeometry(QRect(30, 60, 61, 16));
        lineEdit_phi = new QLineEdit(groupBox_angle);
        lineEdit_phi->setObjectName(QString::fromUtf8("lineEdit_phi"));
        lineEdit_phi->setGeometry(QRect(100, 60, 91, 21));
        label_delta = new QLabel(groupBox_angle);
        label_delta->setObjectName(QString::fromUtf8("label_delta"));
        label_delta->setGeometry(QRect(30, 90, 61, 16));
        lineEdit_delta = new QLineEdit(groupBox_angle);
        lineEdit_delta->setObjectName(QString::fromUtf8("lineEdit_delta"));
        lineEdit_delta->setGeometry(QRect(100, 90, 91, 21));
        groupBox_prp = new QGroupBox(groupBox_set);
        groupBox_prp->setObjectName(QString::fromUtf8("groupBox_prp"));
        groupBox_prp->setGeometry(QRect(20, 370, 271, 91));
        lineEdit_n_5 = new QLineEdit(groupBox_prp);
        lineEdit_n_5->setObjectName(QString::fromUtf8("lineEdit_n_5"));
        lineEdit_n_5->setGeometry(QRect(-230, 340, 113, 21));
        label_u = new QLabel(groupBox_prp);
        label_u->setObjectName(QString::fromUtf8("label_u"));
        label_u->setGeometry(QRect(20, 30, 21, 16));
        lineEdit_prpu = new QLineEdit(groupBox_prp);
        lineEdit_prpu->setObjectName(QString::fromUtf8("lineEdit_prpu"));
        lineEdit_prpu->setGeometry(QRect(40, 30, 71, 21));
        label_v = new QLabel(groupBox_prp);
        label_v->setObjectName(QString::fromUtf8("label_v"));
        label_v->setGeometry(QRect(130, 30, 21, 16));
        lineEdit_prpv = new QLineEdit(groupBox_prp);
        lineEdit_prpv->setObjectName(QString::fromUtf8("lineEdit_prpv"));
        lineEdit_prpv->setGeometry(QRect(150, 30, 71, 21));
        lineEdit_prpn = new QLineEdit(groupBox_prp);
        lineEdit_prpn->setObjectName(QString::fromUtf8("lineEdit_prpn"));
        lineEdit_prpn->setGeometry(QRect(40, 60, 71, 21));
        label_n = new QLabel(groupBox_prp);
        label_n->setObjectName(QString::fromUtf8("label_n"));
        label_n->setGeometry(QRect(20, 60, 21, 16));
        groupBox_cw = new QGroupBox(groupBox_set);
        groupBox_cw->setObjectName(QString::fromUtf8("groupBox_cw"));
        groupBox_cw->setGeometry(QRect(20, 470, 271, 71));
        lineEdit_n_6 = new QLineEdit(groupBox_cw);
        lineEdit_n_6->setObjectName(QString::fromUtf8("lineEdit_n_6"));
        lineEdit_n_6->setGeometry(QRect(-230, 340, 113, 21));
        label_cwu = new QLabel(groupBox_cw);
        label_cwu->setObjectName(QString::fromUtf8("label_cwu"));
        label_cwu->setGeometry(QRect(20, 30, 21, 16));
        lineEdit_cwu = new QLineEdit(groupBox_cw);
        lineEdit_cwu->setObjectName(QString::fromUtf8("lineEdit_cwu"));
        lineEdit_cwu->setGeometry(QRect(40, 30, 71, 21));
        label_cwv = new QLabel(groupBox_cw);
        label_cwv->setObjectName(QString::fromUtf8("label_cwv"));
        label_cwv->setGeometry(QRect(130, 30, 21, 16));
        lineEdit_cwv = new QLineEdit(groupBox_cw);
        lineEdit_cwv->setObjectName(QString::fromUtf8("lineEdit_cwv"));
        lineEdit_cwv->setGeometry(QRect(150, 30, 71, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox_set->setTitle(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\351\235\242\346\235\277", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("Widget", "\345\272\224\347\224\250", nullptr));
        groupBox_projection->setTitle(QCoreApplication::translate("Widget", "\346\212\225\345\275\261\347\261\273\345\236\213", nullptr));
        lineEdit_n_2->setText(QCoreApplication::translate("Widget", "0", nullptr));
        radioButton_parallel->setText(QCoreApplication::translate("Widget", "\351\200\217\350\247\206\346\212\225\345\275\261", nullptr));
        radioButton_perspective->setText(QCoreApplication::translate("Widget", "\345\271\263\350\241\214\346\212\225\345\275\261", nullptr));
        pushButton_restore->setText(QCoreApplication::translate("Widget", "\346\201\242\345\244\215", nullptr));
        groupBox_vrp->setTitle(QCoreApplication::translate("Widget", "\350\247\206\345\233\276\345\217\202\350\200\203\347\202\271VRP(WC)", nullptr));
        lineEdit_n_3->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_x->setText(QCoreApplication::translate("Widget", "x:", nullptr));
        lineEdit_vrpx->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_y->setText(QCoreApplication::translate("Widget", "y:", nullptr));
        lineEdit_vrpy->setText(QCoreApplication::translate("Widget", "0", nullptr));
        lineEdit_vrpz->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_z->setText(QCoreApplication::translate("Widget", "z:", nullptr));
        groupBox_angle->setTitle(QCoreApplication::translate("Widget", "\350\247\206\345\233\276\345\217\202\350\200\203\345\235\220\346\240\207\347\263\273\345\201\217\350\275\254\350\247\222", nullptr));
        lineEdit->setText(QCoreApplication::translate("Widget", "0", nullptr));
        lineEdit_theta->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_theta->setText(QCoreApplication::translate("Widget", "theta\357\274\232", nullptr));
        label_phi->setText(QCoreApplication::translate("Widget", "phi\357\274\232", nullptr));
        lineEdit_phi->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_delta->setText(QCoreApplication::translate("Widget", "delta\357\274\232", nullptr));
        lineEdit_delta->setText(QCoreApplication::translate("Widget", "0", nullptr));
        groupBox_prp->setTitle(QCoreApplication::translate("Widget", "\346\212\225\345\275\261\345\217\202\350\200\203\347\202\271PRP(VRC)", nullptr));
        lineEdit_n_5->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_u->setText(QCoreApplication::translate("Widget", "u:", nullptr));
        lineEdit_prpu->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_v->setText(QCoreApplication::translate("Widget", "v:", nullptr));
        lineEdit_prpv->setText(QCoreApplication::translate("Widget", "0", nullptr));
        lineEdit_prpn->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_n->setText(QCoreApplication::translate("Widget", "n:", nullptr));
        groupBox_cw->setTitle(QCoreApplication::translate("Widget", "\347\252\227\345\217\243\344\270\255\345\277\203CW(VRC)", nullptr));
        lineEdit_n_6->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_cwu->setText(QCoreApplication::translate("Widget", "u:", nullptr));
        lineEdit_cwu->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_cwv->setText(QCoreApplication::translate("Widget", "v:", nullptr));
        lineEdit_cwv->setText(QCoreApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
