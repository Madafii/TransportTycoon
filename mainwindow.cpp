#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ttetileloader.h"
#include "tterailloader.h"
#include "ttestreetloader.h"
#include "ttemainviewmap.h"
#include "tterailbuildermenu.h"
#include "ttestreetbuildermenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const QString userPath = qgetenv("TTEUSER");

    // create image loaders for different types
    tileLoader = new TTETileLoader(userPath + "/images/test.png");
    railLoader = new TTERailLoader(userPath + "/images/TestRails.png");
    streetLoader = new TTEStreetLoader(userPath + "/images/TestStreet.png");

    initMainView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainView()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    
    tileMap = new TTEMainViewMap(scene, 1000, 1000, tileLoader, this);
    tileMap->setObjectName("graphicsViewMain");

    ui->verticalLayout->addWidget(tileMap);
    tileMap->setScene(scene);
    tileMap->setBackgroundBrush(Qt::lightGray);
    tileMap->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::on_pushButtonAddRail_clicked()
{
    tileMap->setCursorPreviewVisible(!tileMap->isCursorPreviewVisible());
}

void MainWindow::on_pushButtonRails_clicked()
{
    // createBuildWindow<TTERailBuilderMenu, TTERailLoader>(ui->pushButtonRails);
    if (isOpenWindow<TTERailBuilderMenu>()) {
        qDebug() << "can not open windown because it is already open";
        return;
    }

    auto builderMenu = std::make_unique<TTERailBuilderMenu>(railLoader, this);
    builderMenu->show();

    const QRect buttonRect = ui->pushButtonRails->geometry();
    const QPoint buttonGlobalPos = ui->pushButtonRails->mapToGlobal(QPoint(0, 0));

    const int bx = buttonGlobalPos.x();
    const int by = buttonGlobalPos.y() + buttonRect.height();
    builderMenu->move(bx, by);

    // setup connection for closing the window
    connect(builderMenu.get(), &TTERailBuilderMenu::closeWindow, this, &MainWindow::on_windowClosed);
    connect(builderMenu.get(), &TTERailBuilderMenu::railSelected, tileMap, &TTEMainViewMap::setBuildItem);

    // move the menu to a opened window list
    openWindowsList.push_back(buttonWindowPair(ui->pushButtonRails, std::move(builderMenu)));
    ui->pushButtonRails->setEnabled(false);
 // setup rail selection
    // if (TTERailBuilderMenu* openedRailBuilder = getOpenWindow<TTERailBuilderMenu>()) {
    //     connect(openedRailBuilder, &TTERailBuilderMenu::railSelected, tileMap, &TTEMainViewMap::setCursorPreviewItem);
    // }
}

void MainWindow::on_pushButtonStreets_clicked()
{
    if (isOpenWindow<TTEStreetBuilderMenu>()) {
        qDebug() << "can not open windown because it is already open";
        return;
    }

    auto builderMenu = std::make_unique<TTEStreetBuilderMenu>(streetLoader, this);
    builderMenu->show();

    const QRect buttonRect = ui->pushButtonStreets->geometry();
    const QPoint buttonGlobalPos = ui->pushButtonStreets->mapToGlobal(QPoint(0, 0));

    const int bx = buttonGlobalPos.x();
    const int by = buttonGlobalPos.y() + buttonRect.height();
    builderMenu->move(bx, by);

    // setup connection for closing the window
    connect(builderMenu.get(), &TTEStreetBuilderMenu::closeWindow, this, &MainWindow::on_windowClosed);
    connect(builderMenu.get(), &TTEStreetBuilderMenu::streetSelected, tileMap, &TTEMainViewMap::setBuildItem);

    // move the menu to a opened window list
    openWindowsList.push_back(buttonWindowPair(ui->pushButtonStreets, std::move(builderMenu)));
    ui->pushButtonStreets->setEnabled(false);
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

