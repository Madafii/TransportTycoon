#include "tterailbuildermenu.h"
#include "ui_tterailbuildermenu.h"

TTERailBuilderMenu::TTERailBuilderMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TTERailBuilderMenu)
{
    ui->setupUi(this);
}

TTERailBuilderMenu::~TTERailBuilderMenu()
{
    delete ui;
}
