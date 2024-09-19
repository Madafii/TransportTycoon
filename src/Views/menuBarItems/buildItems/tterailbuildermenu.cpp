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
    buttonWO->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonSN->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
    buttonSW_NO->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonSO_NW->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
    buttonDelete->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
}

void TTERailBuilderMenu::initButtonConnections()
{
    createButtonConnection(buttonWO, HORIZONTAL_RAIL);
    createButtonConnection(buttonSN, VERTICAL_RAIL);
}

void TTERailBuilderMenu::createButtonConnection(const QPushButton *button, const RAIL_ORIENTATION orientation)
{
    connect(button, &QPushButton::clicked, this, [this, orientation]() {
        const TTERailType *railType = railLoader->getTypePtrAt(ELECTRIC, orientation);
        emit railSelected(railType);
    });
}

void TTERailBuilderMenu::setRailLoader(TTERailLoader *loader)
{
    railLoader = loader;
}
