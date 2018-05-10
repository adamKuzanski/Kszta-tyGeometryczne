#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "polygon.h"
#include "shape.h"
#include "ellipse.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"

#include <QMouseEvent>
#include <QList>



QList<Shape*> list;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    QPixmap pixmap;
    ui->setupUi(this);
    ui->label->setFixedSize(1000,600);  //resize pixmap to the size of label component
    ui->label->installEventFilter(this);
    pixmap = QPixmap(ui->label->width(),ui->label->height());
    pixmap.fill(Qt::darkMagenta);
    ui->label->setPixmap( pixmap );

    ui->radioButton_Circle->setChecked(true);

    ui->spinBox_PolyNodes->setValue(5);

    ui->horizontalSlider_ellpseWidth->setValue(30);
    ui->horizontalSlider_ellpsHeight->setValue(60);
    ui->horizontalSlider_PolyRadius->setValue(100);
    ui->horizontalSlider_SquareSize->setValue(75);
    ui->horizontalSlider_rectangleHeight->setValue(50);
    ui->horizontalSlider_rectangleWidth->setValue(100);
    ui->horizontalSlider_CircleRadius->setValue(100);
    ui->horizontalSlider_TriangleSize->setValue(100);

    ui->label_valueHeight->setText(QString::number( ui->horizontalSlider_ellpsHeight->value()));
    ui->label_valueWidth->setText( QString::number(  ui->horizontalSlider_ellpseWidth->value()));
    ui->label_PolyRadius->setText( QString::number( ui->horizontalSlider_PolyRadius->value()));
    ui->label_valueRectWidth->setText( QString::number( ui->horizontalSlider_rectangleHeight->value()));
    ui->label_valueRectHeight->setText( QString::number( ui->horizontalSlider_rectangleWidth->value()));
    ui->label_valueSquareSize->setText( QString::number( ui->horizontalSlider_SquareSize->value()));
    ui->label_valueCircleRadius->setText( QString::number( ui->horizontalSlider_CircleRadius->value()));
    ui->label_valueTriangle->setText( QString::number( ui->horizontalSlider_TriangleSize->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object==ui->label)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if( ui->radioButton_Ellipse->isChecked())        {
                list.push_back( new Ellipse( mouseEvent->pos(),  ui->horizontalSlider_ellpseWidth->value(), ui->horizontalSlider_ellpsHeight->value() ));
            }
            else if( ui->radioButton_Rectangle->isChecked())        {
                list.push_back( new Rectangle( mouseEvent->pos(), ui->horizontalSlider_rectangleWidth->value(), ui->horizontalSlider_rectangleHeight->value()));
            }
            else if( ui->radioButton_Polygon->isChecked())        {
                list.push_back( new Polygon( mouseEvent->pos(), ui->spinBox_PolyNodes->value(), ui->horizontalSlider_PolyRadius->value()));
            }
            else if( ui->radioButton_Square->isChecked() ){
                list.push_back( new Square( mouseEvent->pos(), ui->horizontalSlider_SquareSize->value() ) );
            }
            else if( ui->radioButton_Circle->isChecked())
            {
                list.push_back( new Circle( mouseEvent->pos(), ui->horizontalSlider_CircleRadius->value()) );
            }
            else if( ui->radioButton_Triangle->isChecked())
            {
                list.push_back( new Triangle( mouseEvent->pos(), ui->horizontalSlider_TriangleSize->value()));
            }

            drawShape();

        }
    }
    return QMainWindow::eventFilter(object,event);
}

void MainWindow::drawShape()
{
    QPixmap pixmap;
    pixmap = QPixmap(ui->label->width(),ui->label->height());
    pixmap.fill(Qt::darkMagenta);

        for( int i =0; i<list.count(); i++ )
            list[i]->drawShape( &pixmap );

    ui->label->setPixmap( pixmap );
}




void MainWindow::on_horizontalSlider_PolyRadius_sliderMoved(int position)
{
    ui->label_PolyRadius->setText(QString::number(position));
}
void MainWindow::on_horizontalSlider_ellpsHeight_sliderMoved(int position)
{
    ui->label_valueHeight->setText( QString::number(position));
}

void MainWindow::on_horizontalSlider_ellpseWidth_sliderMoved(int position)
{
    ui->label_valueWidth->setText( QString::number( position ));
}

void MainWindow::on_horizontalSlider_rectangleHeight_sliderMoved(int position)
{
    ui->label_valueRectHeight->setText( QString::number(position));
}

void MainWindow::on_horizontalSlider_rectangleWidth_sliderMoved(int position)
{
    ui->label_valueRectWidth->setText( QString::number(position));
}

void MainWindow::on_horizontalSlider_SquareSize_sliderMoved(int position)
{
    ui->label_valueSquareSize->setText( QString::number(position));
}

void MainWindow::on_horizontalSlider_CircleRadius_sliderMoved(int position)
{
    ui->label_valueCircleRadius->setText( QString::number(position));
}

void MainWindow::on_horizontalSlider_TriangleSize_sliderMoved(int position)
{
    ui->label_valueTriangle->setText( QString::number(position));
}

void MainWindow::on_pushButton_delete_clicked()
{
    int index = list.count()-1;
    if( index >= 0 )
    {
        delete list[index];
        list.removeAt(index);
        drawShape();
    }
}
