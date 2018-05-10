#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <QPixmap>
#include <QPainter>
#include <QPolygon>


class Polygon : public Shape
{
public:
    Polygon();
    Polygon(QPoint , int userNumberOfNodes, int userRadius);
    void drawShape( QPixmap* );

protected:
    int numberOfNodes;
    int radius;
};

#endif // POLYGON_H
