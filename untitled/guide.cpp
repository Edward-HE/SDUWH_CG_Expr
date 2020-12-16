#include "guide.h"

Guide::Guide()
{
    gravity=10;
}

void Guide::ShowGuides(QPainter *pt, QRect win,QPoint point,bool vline,bool drawline)
{
    ruler.HideVernier(win,pt);
    pt->drawLine(line);
}

void Guide::SetGravity(int gravity)
{
    this->gravity=gravity;
}

int Guide::getGravity()
{
   return gravity;
}

bool Guide::isInRuler(QPoint point)
{
    if((ruler.GetCursorPosition(point)==CP_HORIZONTAL||ruler.GetCursorPosition(point)==CP_VERTICAL)&&ruler.GetCursorPosition(point)!=CP_CORNER)
        return true;
    return false;
}

bool Guide::isVRuler(QPoint point)
{
   if(ruler.GetCursorPosition(point)==CP_VERTICAL)
       return true;
   if(ruler.GetCursorPosition(point)==CP_HORIZONTAL)
       return false;
}

void Guide::setLine(bool vline, QPoint point)
{
    if(vline)line=QLine(QPoint(ruler.GetWidth(),point.y()),point);
    if(!vline)line=QLine(QPoint(point.x(),ruler.GetWidth()),point);
}

bool Guide::isInClient(QPoint point)
{
    return ruler.GetCursorPosition(point)==CP_CLIENT;
}

QLine Guide::getLine()
{
   return line;
}

