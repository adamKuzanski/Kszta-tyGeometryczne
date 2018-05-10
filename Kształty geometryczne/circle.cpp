#include "circle.h"
#include "ellipse.h"
#include "shape.h"

Circle::Circle( QPoint mousePosition, int userRadius ) : Ellipse( mousePosition, userRadius, userRadius )
{

}

