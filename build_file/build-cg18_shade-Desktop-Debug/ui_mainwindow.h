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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "widgetdraw.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_lineFrame;
    QAction *action_surface;
    QWidget *centralwidget;
    widgetDraw *widget_draw;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_lineFrame = new QAction(MainWindow);
        action_lineFrame->setObjectName(QString::fromUtf8("action_lineFrame"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/lineFrame.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_lineFrame->setIcon(icon);
        action_surface = new QAction(MainWindow);
        action_surface->setObjectName(QString::fromUtf8("action_surface"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/surface.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_surface->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_draw = new widgetDraw(centralwidget);
        widget_draw->setObjectName(QString::fromUtf8("widget_draw"));
        widget_draw->setGeometry(QRect(20, 20, 761, 501));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_lineFrame);
        menu->addAction(action_surface);
        toolBar->addAction(action_lineFrame);
        toolBar->addAction(action_surface);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_lineFrame->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\241\206\346\250\241\345\274\217", nullptr));
        action_surface->setText(QCoreApplication::translate("MainWindow", "\350\241\250\351\235\242\346\250\241\345\274\217", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
