#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QLabel>
#include "shape.h"



class Ellipse : public Shape
{
private:
    unsigned width;
    unsigned height;
public:
    Ellipse( QPoint, int, int );
    Ellipse();

    void drawShape( QPixmap* );

    void setWidth ( unsigned int );
    void setHeight ( unsigned int );
};

#endif // ELLIPSE_H




