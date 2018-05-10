#include "rectangle.h"

void Rectangle::setSize( QPoint userMouse, int userWidth, int userHeight)
{
    p0=userMouse;
    width   = userWidth;
    height  = userHeight;
}


Rectangle::Rectangle( QPoint mousePosition, int userWidth, int userHeight ) : Shape(Qt::green)
{
    p0 = mousePosition;
    height = userHeight;
    width = userWidth;
}

void Rectangle::drawShape( QPixmap* pixmap )
{
    QPainter painter( pixmap );
    painter.setPen( QPen( color ));
    painter.drawRect( p0.x() - width/2, p0.y() - height/2, width, height);
}
