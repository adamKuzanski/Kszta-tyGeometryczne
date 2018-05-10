#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"
#include <QPixmap>
#include <QPainter>
#include <QPoint>


class Circle : public Ellipse
{   
public:
    Circle( QPoint, int );
};

#endif // CIRCLE_H



