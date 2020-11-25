/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_ww;
    QLabel *label_wh;
    QLabel *label_vw;
    QLabel *label_vh;
    QSpinBox *spinBox_ww;
    QSpinBox *spinBox_wh;
    QSpinBox *spinBox_vw;
    QSpinBox *spinBox_vh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1089, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_ww = new QLabel(centralwidget);
        label_ww->setObjectName(QString::fromUtf8("label_ww"));
        label_ww->setGeometry(QRect(50, 20, 72, 21));
        label_wh = new QLabel(centralwidget);
        label_wh->setObjectName(QString::fromUtf8("label_wh"));
        label_wh->setGeometry(QRect(320, 20, 72, 21));
        label_vw = new QLabel(centralwidget);
        label_vw->setObjectName(QString::fromUtf8("label_vw"));
        label_vw->setGeometry(QRect(570, 20, 72, 21));
        label_vh = new QLabel(centralwidget);
        label_vh->setObjectName(QString::fromUtf8("label_vh"));
        label_vh->setGeometry(QRect(820, 20, 72, 21));
        spinBox_ww = new QSpinBox(centralwidget);
        spinBox_ww->setObjectName(QString::fromUtf8("spinBox_ww"));
        spinBox_ww->setGeometry(QRect(150, 20, 111, 22));
        spinBox_wh = new QSpinBox(centralwidget);
        spinBox_wh->setObjectName(QString::fromUtf8("spinBox_wh"));
        spinBox_wh->setGeometry(QRect(410, 20, 111, 22));
        spinBox_vw = new QSpinBox(centralwidget);
        spinBox_vw->setObjectName(QString::fromUtf8("spinBox_vw"));
        spinBox_vw->setGeometry(QRect(660, 20, 111, 22));
        spinBox_vh = new QSpinBox(centralwidget);
        spinBox_vh->setObjectName(QString::fromUtf8("spinBox_vh"));
        spinBox_vh->setGeometry(QRect(910, 20, 111, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1089, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\236\351\252\21413 \350\247\206\347\252\227\345\217\230\346\215\242", nullptr));
        label_ww->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\345\256\275\345\272\246\357\274\232", nullptr));
        label_wh->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\351\253\230\345\272\246\357\274\232", nullptr));
        label_vw->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\217\243\345\256\275\345\272\246\357\274\232", nullptr));
        label_vh->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\217\243\351\253\230\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
