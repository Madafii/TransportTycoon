#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TileLoader *tileLoader = new TileLoader();
    TileMap *tileMap = new TileMap(100, 100, tileLoader);

    QGraphicsScene *scene = new QGraphicsScene(this);
    foreach (Tile tile, tileMap->getTileList()) {
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(tile.tileType->getTileImage());
        pixmapItem->setPos(tile.posX, tile.posY);
        scene->addItem(pixmapItem);
    }

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setBackgroundBrush(Qt::lightGray);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
