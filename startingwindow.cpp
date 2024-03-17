#include "startingwindow.h"
#include "ui_startingwindow.h"

StartingWindow::StartingWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartingWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonCreate, &QPushButton::clicked, this, &StartingWindow::buttonCreateClicked);
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::buttonCreateClicked()
{
    accept();
}

