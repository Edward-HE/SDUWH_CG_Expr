#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QString>
#include <QRectF>

class textWidget : public QWidget
{
    Q_OBJECT
public:
    explicit textWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
        void setcurrentShow(int cur);
        void startOperat();
signals:

public slots:
private:
    int currentShow;
    bool isOperating;
    QVector<QString> text;


};

#endif // TEXTWIDGET_H
