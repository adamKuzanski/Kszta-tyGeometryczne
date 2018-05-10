#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QPixmap>
#include <QPainter>
#include <QPolygon>
#include "polygon.h"


class Triangle : public Polygon
{
public:
    Triangle( QPoint,int);
};

#endif // TRIANGLE_H
