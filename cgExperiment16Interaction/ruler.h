//Ruler.h
#ifndef RULER_H
#define RULER_H
#include <QPainter>

#define CP_OUTER 0
#define CP_HORIZONTAL 1
#define CP_VERTICAL 2
#define CP_CORNER 3
#define CP_CLIENT 4

class Ruler {
private:
    QRect vrect;
    QRect hrect;
    int width; //标尺宽度
    int spacing; //标尺刻度间距
    QSize size; //客户区大小
public:
    Ruler();
    int GetWidth(); //返回标尺宽度
    int GetCursorPosition(QPoint point); //返回指定点相对标尺的位置
    void Show(QRect win, QPainter* pt); //显示标尺
    void ShowVernier(QRect win, QPainter* pt, QPoint point); //显示游标
    void HideVernier(QRect win, QPainter* pt); //隐藏游标
};

#endif // RULER_H
