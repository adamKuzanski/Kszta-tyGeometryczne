#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
#include <QPixmap>
#include <QPainter>


class Square : public Rectangle
{  
public:
    Square (QPoint, int);
};

#endif // SQUARE_H
