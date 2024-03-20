#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tileLoader = new TileLoader();
    tileMap = new TileMap(100, 100, tileLoader);
    QGraphicsScene *scene = new QGraphicsScene(this);

    tileMap->loadMapIntoScene(scene);

    ui->graphicsViewMain->setScene(scene);
    ui->graphicsViewMain->setBackgroundBrush(Qt::lightGray);
    ui->graphicsViewMain->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsViewMain->setDragMode(QGraphicsView::ScrollHandDrag);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddRail_clicked()
{
    buildRail = !buildRail;
}

