#include "tterailbuildermenu.h"
#include "ui_tterailbuildermenu.h"

TTERailBuilderMenu::TTERailBuilderMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TTERailBuilderMenu)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    //setStyleSheet("QWidget { border: 1px solid black; border-radius: 0px; }");

    // set icons for the buttons
    ui->pushButtonRailHorizontal->setIcon(QIcon(":/icons/build_rail_icon.jpg"));
    ui->pushButtonRailVertical->setIcon(QIcon(":/icons/build_rail_icon.jpg"));
}

TTERailBuilderMenu::~TTERailBuilderMenu()
{
    delete ui;
}
