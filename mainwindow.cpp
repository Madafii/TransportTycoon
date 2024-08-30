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
    // only have one instance of it open
    if (isOpenWindow<TTERailBuilderMenu>()) {
        return;
    }

    // create builder menu
    std::unique_ptr<QWidget> railBuilderMenu = std::make_unique<TTERailBuilderMenu>(this);
    connect(dynamic_cast<TTERailBuilderMenu*>(railBuilderMenu.get()), &TTERailBuilderMenu::closeWindow, this, &MainWindow::on_windowClosed);
    railBuilderMenu->show();
    openWindowsList.push_back(buttonWindowPair(ui->pushButtonRails, std::move(railBuilderMenu)));

    ui->pushButtonRails->setEnabled(false);
}

void MainWindow::on_windowClosed(QWidget *closedWidget)
{
    auto it = std::find_if(openWindowsList.begin(), openWindowsList.end(), [&](const buttonWindowPair &pair) {
        return pair.second.get() == closedWidget;
    });

    if (it !=openWindowsList.end()) {
        // set the button enabled then erase the widget
        it->first->setEnabled(true);
        openWindowsList.erase(it);
    }
}
