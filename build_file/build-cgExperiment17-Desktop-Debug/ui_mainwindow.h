/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "widgetdraw.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_set;
    QCheckBox *checkBox_lightEnable;
    QGroupBox *groupBox_light;
    QCheckBox *checkBox_doubleFace;
    QCheckBox *checkBox_infinete;
    QCheckBox *checkBox_global;
    QGroupBox *guoupBox_lightColor;
    QFrame *frameColor_diffuse;
    QFrame *frameColor_specular;
    QFrame *frameColor_ambient;
    QPushButton *pushButton_diffuse;
    QPushButton *pushButton_specular;
    QPushButton *pushButton_ambient;
    QGroupBox *groupBox_material;
    QComboBox *comboBox_material;
    widgetDraw *widget_draw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(560, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_set = new QGroupBox(centralwidget);
        groupBox_set->setObjectName(QString::fromUtf8("groupBox_set"));
        groupBox_set->setGeometry(QRect(10, 0, 170, 410));
        checkBox_lightEnable = new QCheckBox(groupBox_set);
        checkBox_lightEnable->setObjectName(QString::fromUtf8("checkBox_lightEnable"));
        checkBox_lightEnable->setGeometry(QRect(20, 20, 91, 20));
        groupBox_light = new QGroupBox(groupBox_set);
        groupBox_light->setObjectName(QString::fromUtf8("groupBox_light"));
        groupBox_light->setGeometry(QRect(10, 50, 150, 90));
        checkBox_doubleFace = new QCheckBox(groupBox_light);
        checkBox_doubleFace->setObjectName(QString::fromUtf8("checkBox_doubleFace"));
        checkBox_doubleFace->setGeometry(QRect(0, 20, 121, 19));
        checkBox_infinete = new QCheckBox(groupBox_light);
        checkBox_infinete->setObjectName(QString::fromUtf8("checkBox_infinete"));
        checkBox_infinete->setGeometry(QRect(0, 40, 131, 19));
        checkBox_global = new QCheckBox(groupBox_light);
        checkBox_global->setObjectName(QString::fromUtf8("checkBox_global"));
        checkBox_global->setGeometry(QRect(0, 60, 131, 19));
        guoupBox_lightColor = new QGroupBox(groupBox_set);
        guoupBox_lightColor->setObjectName(QString::fromUtf8("guoupBox_lightColor"));
        guoupBox_lightColor->setGeometry(QRect(10, 150, 150, 110));
        frameColor_diffuse = new QFrame(guoupBox_lightColor);
        frameColor_diffuse->setObjectName(QString::fromUtf8("frameColor_diffuse"));
        frameColor_diffuse->setGeometry(QRect(10, 20, 50, 20));
        frameColor_diffuse->setAutoFillBackground(true);
        frameColor_diffuse->setFrameShape(QFrame::Panel);
        frameColor_diffuse->setFrameShadow(QFrame::Sunken);
        frameColor_specular = new QFrame(guoupBox_lightColor);
        frameColor_specular->setObjectName(QString::fromUtf8("frameColor_specular"));
        frameColor_specular->setGeometry(QRect(10, 50, 50, 20));
        frameColor_specular->setAutoFillBackground(true);
        frameColor_specular->setFrameShape(QFrame::Panel);
        frameColor_specular->setFrameShadow(QFrame::Sunken);
        frameColor_ambient = new QFrame(guoupBox_lightColor);
        frameColor_ambient->setObjectName(QString::fromUtf8("frameColor_ambient"));
        frameColor_ambient->setGeometry(QRect(10, 80, 50, 20));
        frameColor_ambient->setAutoFillBackground(true);
        frameColor_ambient->setFrameShape(QFrame::Panel);
        frameColor_ambient->setFrameShadow(QFrame::Sunken);
        pushButton_diffuse = new QPushButton(guoupBox_lightColor);
        pushButton_diffuse->setObjectName(QString::fromUtf8("pushButton_diffuse"));
        pushButton_diffuse->setGeometry(QRect(70, 20, 60, 20));
        pushButton_specular = new QPushButton(guoupBox_lightColor);
        pushButton_specular->setObjectName(QString::fromUtf8("pushButton_specular"));
        pushButton_specular->setGeometry(QRect(70, 50, 60, 20));
        pushButton_ambient = new QPushButton(guoupBox_lightColor);
        pushButton_ambient->setObjectName(QString::fromUtf8("pushButton_ambient"));
        pushButton_ambient->setGeometry(QRect(70, 80, 60, 20));
        groupBox_material = new QGroupBox(groupBox_set);
        groupBox_material->setObjectName(QString::fromUtf8("groupBox_material"));
        groupBox_material->setGeometry(QRect(10, 280, 150, 50));
        comboBox_material = new QComboBox(groupBox_material);
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->setObjectName(QString::fromUtf8("comboBox_material"));
        comboBox_material->setGeometry(QRect(20, 20, 70, 20));
        widget_draw = new widgetDraw(centralwidget);
        widget_draw->setObjectName(QString::fromUtf8("widget_draw"));
        widget_draw->setGeometry(QRect(186, 10, 460, 400));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 560, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_set->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\235\242\346\235\277", nullptr));
        checkBox_lightEnable->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250\345\205\211\347\205\247", nullptr));
        groupBox_light->setTitle(QCoreApplication::translate("MainWindow", "\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_doubleFace->setText(QCoreApplication::translate("MainWindow", "\345\217\214\351\235\242\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_infinete->setText(QCoreApplication::translate("MainWindow", "\346\227\240\347\251\267\350\277\234\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_global->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\234\272\347\216\257\345\242\203\345\205\211\346\250\241\345\274\217", nullptr));
        guoupBox_lightColor->setTitle(QCoreApplication::translate("MainWindow", "\345\205\211\346\272\220\351\242\234\350\211\262", nullptr));
        pushButton_diffuse->setText(QCoreApplication::translate("MainWindow", "\346\274\253\345\217\215\345\260\204", nullptr));
        pushButton_specular->setText(QCoreApplication::translate("MainWindow", "\351\225\234\351\235\242\345\217\215\345\260\204", nullptr));
        pushButton_ambient->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\345\205\211", nullptr));
        groupBox_material->setTitle(QCoreApplication::translate("MainWindow", "\347\211\251\344\275\223\346\235\220\350\264\250", nullptr));
        comboBox_material->setItemText(0, QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\345\200\274", nullptr));
        comboBox_material->setItemText(1, QCoreApplication::translate("MainWindow", "\347\272\242\345\256\235\347\237\263", nullptr));
        comboBox_material->setItemText(2, QCoreApplication::translate("MainWindow", "\351\273\204\351\223\234", nullptr));
        comboBox_material->setItemText(3, QCoreApplication::translate("MainWindow", "\351\235\222\351\223\234", nullptr));
        comboBox_material->setItemText(4, QCoreApplication::translate("MainWindow", "\347\231\275\351\223\266", nullptr));
        comboBox_material->setItemText(5, QCoreApplication::translate("MainWindow", "\347\245\226\346\257\215\347\273\277", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
