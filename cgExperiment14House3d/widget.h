#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_apply_clicked();
    void on_pushButton_restore_clicked();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
