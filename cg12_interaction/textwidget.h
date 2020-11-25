//textWidget.h
#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QPainter>
#include <QRectF>
#include <QString>
#include <QVector>
#include <QWidget>

class textWidget : public QWidget {
    Q_OBJECT
public:
    explicit textWidget(QWidget* parent = nullptr);
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
