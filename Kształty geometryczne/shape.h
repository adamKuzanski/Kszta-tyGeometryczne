#ifndef SHAPE_H
#define SHAPE_H
#include<QColor>
#include<QPoint>
#include <QPixmap>

class Shape
{
protected:
    QColor color;
    QPoint p0;

public:
    Shape():color(Qt::black), p0(100,100) {}
    virtual ~Shape(){}
    Shape(QColor c){color = c;}
    Shape(QPoint aa){p0 = aa;}

    virtual void drawShape( QPixmap* ) {}

    void setColor( const QColor &c ) { color = c; }
    void setOrg( QPoint p ){ p0 = p; }


};

#endif // SHAPE_H


