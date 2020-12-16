#include "ruler.h"
Ruler::Ruler()
{
    width=30;
    spacing=5;
}

int Ruler::GetWidth()
{
    return width;
}

int Ruler::GetCursorPosition(QPoint point)
{
   QRect rect1=hrect;
   QRect rect2=vrect;
   rect1.adjust(0,0,0,2);
   rect2.adjust(0,0,2,0);
   if(rect1.contains(point)&&rect2.contains(point))
       return CP_CORNER;
   if(rect1.contains(point))
       return CP_HORIZONTAL;
   if(rect2.contains(point))
       return CP_VERTICAL;
   rect1.setTop(rect1.bottom());
   rect1.setLeft(rect2.right());
   rect1.setBottom(rect2.bottom());
   if(rect1.contains(point))
       return CP_CLIENT;
   return CP_OUTER;
}

void Ruler::Show(QRect win,QPainter *pt)
{
    size.setWidth(win.width());
    size.setHeight(win.height());
    hrect=vrect=win;
    hrect.setBottom(width);
    vrect.setRight(width);
    pt->save();
    pt->setPen(QPen(QColor(Qt::black)));
    pt->drawRect(hrect);
    pt->drawRect(vrect);
    for(int i=0;i<size.width();i+=spacing)
    {
        pt->drawLine(QPoint(i,hrect.bottom()),QPoint(i,hrect.bottom()-width/4));
        if(i%(spacing*10)==0){
            pt->drawLine(QPoint(i,hrect.bottom()),QPoint(i,hrect.bottom()-width*3/4));
           pt->drawText(i+2,hrect.bottom()-width/2+2,QString::number(i));
        }
    }
    for(int i = 0;i<size.height();i+=spacing)
    {
        pt->drawLine(QPoint(vrect.right(),i),QPoint(vrect.right()-width/4,i));
        if(i%(spacing*10)==0){
            pt->drawLine(QPoint(vrect.right(),i),QPoint(vrect.right()-width*3/4,i));
           pt->drawText(0,i+2,QString::number(i));
        }
    }
}

void Ruler::ShowVernier(QRect win,QPainter *pt, QPoint point)
{
    Show(win,pt);
    if(point.x()==0&&point.y()==0)return;
    pt->drawLine(QPoint(point.x(),width-1),QPoint(point.x(),width/8));
    pt->drawLine(QPoint(width-1,point.y()),QPoint(width/8,point.y()));
}

void Ruler::HideVernier(QRect win,QPainter *pt)
{
    ShowVernier(win,pt,QPoint(0,0));
}


