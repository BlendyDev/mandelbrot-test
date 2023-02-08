#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <complex>
int sizeX = 1080;
int sizeY = 720;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    QImage image = QImage (sizeX, sizeY, QImage::Format_RGB32);
    paint(&image, sizeX, sizeY, 1, 20);

    //


    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}



MainWindow::~MainWindow()
{
    delete ui;
}

