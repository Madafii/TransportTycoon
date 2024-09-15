#include "tterailbuildermenu.h"

#include "tterailloader.h"
#include "ttestreettype.h"
#include "ttetiletype.h"

TTERailBuilderMenu::TTERailBuilderMenu(TTERailLoader *loader, QWidget *parent)
    : TTEBuilderMenuBase(parent), railLoader(loader)
{
    initButtonIcons();
    initButtonConnections();
}

void TTERailBuilderMenu::initButtonIcons()
{
    buttonH->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonV->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
}

void TTERailBuilderMenu::initButtonConnections()
{
    createButtonConnection(buttonH, HORIZONTAL_RAIL);
    createButtonConnection(buttonV, VERTICAL_RAIL);
}

void TTERailBuilderMenu::createButtonConnection(const QPushButton *button, const RAIL_ORIENTATION orientation)
{
    connect(button, &QPushButton::clicked, this, [this, orientation]() {
        const TTERailType &railType = railLoader->getTypeAt(ELECTRIC, orientation);
        emit railSelected(railType);
    });
}

void TTERailBuilderMenu::setRailLoader(TTERailLoader *loader)
{
    railLoader = loader;
}
