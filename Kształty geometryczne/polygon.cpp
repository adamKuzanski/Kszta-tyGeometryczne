#include "polygon.h"
#define FULL_ANGLE 6.28

Polygon::Polygon()
{

}

Polygon::Polygon(QPoint mousePosition, int userNumberOfNodes, int userRadius ) : Shape(Qt::green)
{
    p0 = mousePosition;
    numberOfNodes = userNumberOfNodes;
    radius = userRadius;
}

void Polygon::drawShape( QPixmap* pixmap )
{
    QPainter painter( pixmap );
    double difference = 6.28 / numberOfNodes;       // ANGLE IN RADIANS
    double alfa = 0;
    painter.setPen( QPen( color ));  

    // make our polygon

    QPolygon poly;
    for ( int i = 0; i< numberOfNodes; i++)
    {
        poly << QPoint( p0.x() + static_cast<int>( radius*cos(alfa)) , p0.y() + static_cast<int>(radius * sin(alfa)));
        alfa = alfa + difference;
    }

    painter.drawPolygon(poly);

}
/*
 * x=rcos(a)
 * y=rsin(a)
 * a=360/nb
*/
