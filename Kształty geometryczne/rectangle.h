#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPixmap>
#include <QPainter>
#include "shape.h"

class Rectangle : public Shape
{
protected:
    unsigned int height, width;
public:
    Rectangle( QPoint, int userWidth, int userHeight );
    void setSize(QPoint,int, int );
    void drawShape( QPixmap* );

};

#endif // RECTANGLE_H
