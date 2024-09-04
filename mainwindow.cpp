#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ttetileloader.h"
#include "tterailloader.h"
#include "ttemainviewmap.h"
#include "tterailbuildermenu.h"
#include "ttestreetbuildermenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create image loaders for different types
    tileLoader = new TTETileLoader(qgetenv("TTEUSER") + "/images/test.png");
    railLoader = new TTERailLoader(qgetenv("TTEUSER") + "/images/test.png");

    initMainView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainView()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    
    tileMap = new TTEMainViewMap(scene, 100, 100, tileLoader, this);
    tileMap->setObjectName("graphicsViewMain");

    ui->verticalLayout->addWidget(tileMap);
    tileMap->setScene(scene);
    tileMap->setBackgroundBrush(Qt::lightGray);
    tileMap->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsViewMain->setDragMode(QGraphicsView::ScrollHandDrag);
}

void MainWindow::on_pushButtonAddRail_clicked()
{
    tileMap->setCursorPreviewVisible(!tileMap->isCursorPreviewVisible());
}

void MainWindow::on_pushButtonRails_clicked()
{
    createBuildWindow<TTERailBuilderMenu>(ui->pushButtonRails);
    if (TTERailBuilderMenu* openedRailBuilder = getOpenWindow<TTERailBuilderMenu>()) {
        openedRailBuilder->setRailLoader(railLoader);
        connect(openedRailBuilder, &TTERailBuilderMenu::railSelected, this, &MainWindow::set_selectedBuildingType);
    }
}

void MainWindow::on_pushButtonStreets_clicked()
{
    createBuildWindow<TTEStreetBuilderMenu>(ui->pushButtonStreets);
}

void MainWindow::on_windowClosed(QWidget *closedWidget)
{
    auto it = std::find_if(openWindowsList.begin(), openWindowsList.end(), [&](const buttonWindowPair &pair) {
        return pair.second.get() == closedWidget;
    });

    if (it !=openWindowsList.end()) {
        it->first->setEnabled(true);
        openWindowsList.erase(it);
    }
}

void MainWindow::set_selectedBuildingType(const TTERailType *railType)
{
    selectBuildType = railType;
    tileMap->setCursorPreviewItem(railType);
}
