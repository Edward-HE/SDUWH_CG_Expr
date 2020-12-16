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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_set = new QGroupBox(centralwidget);
        groupBox_set->setObjectName(QString::fromUtf8("groupBox_set"));
        groupBox_set->setGeometry(QRect(30, 50, 181, 410));
        checkBox_lightEnable = new QCheckBox(groupBox_set);
        checkBox_lightEnable->setObjectName(QString::fromUtf8("checkBox_lightEnable"));
        checkBox_lightEnable->setGeometry(QRect(20, 20, 90, 20));
        groupBox_light = new QGroupBox(groupBox_set);
        groupBox_light->setObjectName(QString::fromUtf8("groupBox_light"));
        groupBox_light->setGeometry(QRect(10, 50, 161, 231));
        checkBox_doubleFace = new QCheckBox(groupBox_light);
        checkBox_doubleFace->setObjectName(QString::fromUtf8("checkBox_doubleFace"));
        checkBox_doubleFace->setGeometry(QRect(10, 20, 131, 20));
        checkBox_infinete = new QCheckBox(groupBox_light);
        checkBox_infinete->setObjectName(QString::fromUtf8("checkBox_infinete"));
        checkBox_infinete->setGeometry(QRect(10, 50, 131, 20));
        checkBox_global = new QCheckBox(groupBox_light);
        checkBox_global->setObjectName(QString::fromUtf8("checkBox_global"));
        checkBox_global->setGeometry(QRect(10, 80, 131, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\205\211\347\205\247\346\250\241\345\236\213", nullptr));
        groupBox_set->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\235\242\346\235\277", nullptr));
        checkBox_lightEnable->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250\345\205\211\347\205\247", nullptr));
        groupBox_light->setTitle(QCoreApplication::translate("MainWindow", "\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_doubleFace->setText(QCoreApplication::translate("MainWindow", "\345\217\214\351\235\242\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_infinete->setText(QCoreApplication::translate("MainWindow", "\346\227\240\347\251\267\350\277\234\345\205\211\347\205\247\346\250\241\345\274\217", nullptr));
        checkBox_global->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\234\272\347\216\257\345\242\203\345\205\211\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
