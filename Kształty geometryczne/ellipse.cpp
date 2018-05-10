#include "ellipse.h"
#include "shape.h"

Ellipse::Ellipse(QPoint mousePosition , int userWidth , int userHeight ) : Shape(Qt::green)
{
    width = userWidth;
    height = userHeight;
    p0 = mousePosition;
}

void Ellipse::setWidth (unsigned int uWidth)
{
    width = uWidth;
}

void Ellipse::setHeight (unsigned int uHeight)
{
    height = uHeight;
}



void Ellipse::drawShape(QPixmap* pixmap)
{
    QPainter painter(pixmap);
    painter.setPen( QPen( color ) );
    painter.drawEllipse( p0.x() - width/2, p0.y() - height/2, width, height );
}
