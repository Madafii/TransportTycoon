#include "ttestreetbuildermenu.h"

TTEStreetBuilderMenu::TTEStreetBuilderMenu(QWidget *parent)
    : TTEBuilderMenuBase(parent)
{
    initButtonIcons();
}

void TTEStreetBuilderMenu::initButtonIcons()
{
    buttonH->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonV->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
}
