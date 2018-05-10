#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QEvent>
#include <QWidget>
#include <QMainWindow>
#include <QList>
#include "shape.h"
#include "ellipse.h"
#include "rectangle.h"
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    void drawShape();
    void clearScreen();

private slots:
    void on_horizontalSlider_PolyRadius_sliderMoved(int position);

    void on_horizontalSlider_ellpsHeight_sliderMoved(int position);

    void on_horizontalSlider_ellpseWidth_sliderMoved(int position);

    void on_horizontalSlider_rectangleHeight_sliderMoved(int position);

    void on_horizontalSlider_rectangleWidth_sliderMoved(int position);

    void on_horizontalSlider_SquareSize_sliderMoved(int position);

    void on_horizontalSlider_CircleRadius_sliderMoved(int position);

    void on_horizontalSlider_TriangleSize_sliderMoved(int position);

    void on_pushButton_delete_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
