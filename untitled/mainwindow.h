#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_action_C_triggered();

    void on_action_B_triggered();

    void on_action_T_triggered();

    void on_action_S_triggered();

    void on_action_R_triggered();

    void on_action_G_triggered();

    void on_action_D_triggered();

    void on_action_I_triggered();

    void on_action_U_triggered();

    void on_action_L_triggered();

};
#endif // MAINWINDOW_H
