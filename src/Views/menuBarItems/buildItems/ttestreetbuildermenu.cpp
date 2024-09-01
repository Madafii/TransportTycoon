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

    // set button sizes
    const QSize &buttonSize = buttonH->size();
    buttonH->setIconSize(buttonSize);
    buttonV->setIconSize(buttonSize);
}
