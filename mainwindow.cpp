#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ttetileloader.h"
#include "ttetilemap.h"
#include "tterailbuildermenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainView()
{
    tileLoader = new TTETileLoader(qgetenv("TTEUSER") + "/images/test.png");
    QGraphicsScene *scene = new QGraphicsScene(this);
    tileMap = new TTETileMap(scene, 100, 100, tileLoader, this);

    tileMap->setObjectName("graphicsViewMain");

    ui->verticalLayout->addWidget(tileMap);
    tileMap->setScene(scene);
    tileMap->setBackgroundBrush(Qt::lightGray);
    tileMap->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsViewMain->setDragMode(QGraphicsView::ScrollHandDrag);
}

void MainWindow::on_pushButtonAddRail_clicked()
{
    tileMap->setCursorVisible(!tileMap->isCursorVisible());
}

void MainWindow::on_pushButtonRails_clicked()
{
    TTERailBuilderMenu *railBuilderMenu = new TTERailBuilderMenu(this);
    //railBuilderMenu->setStyleSheet("border: 1px solid black; border-radius: 0px;");
    railBuilderMenu->show();
}

