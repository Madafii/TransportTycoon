#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tileLoader = new TTETileLoader("D:/Finn Pittermann/Documents/QtProjects/TransportTycoon/user/images/test.png");
    QGraphicsScene *scene = new QGraphicsScene(this);
    tileMap = new TTETileMap(scene, 100, 100, tileLoader, this);

    tileMap->setObjectName("graphicsViewMain");

    ui->verticalLayout->addWidget(tileMap);
    tileMap->setScene(scene);
    tileMap->setBackgroundBrush(Qt::lightGray);
    tileMap->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsViewMain->setDragMode(QGraphicsView::ScrollHandDrag);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddRail_clicked()
{
    tileMap->setCursorVisible(!tileMap->isCursorVisible());
}

