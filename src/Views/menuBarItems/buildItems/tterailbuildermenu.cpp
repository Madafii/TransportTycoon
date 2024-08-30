#include "tterailbuildermenu.h"

TTERailBuilderMenu::TTERailBuilderMenu(QWidget *parent)
    : TTEBuilderMenuBase(parent)
{
    initButtonIcons();
}

TTERailBuilderMenu::~TTERailBuilderMenu()
{

}

void TTERailBuilderMenu::initButtonIcons()
{
    buttonH->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonV->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));

    // set button sizes
    const QSize &buttonSize = buttonH->size();
    buttonH->setIconSize(buttonSize);
    buttonV->setIconSize(buttonSize);
}
