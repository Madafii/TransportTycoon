#include "tterailbuildermenu.h"

#include "tterailtype.h"
#include "tterailloader.h"

TTERailBuilderMenu::TTERailBuilderMenu(QWidget *parent)
    : TTEBuilderMenuBase(parent)
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
    // connect(buttonH, &QPushButton::clicked, this, [this]() {
    //     auto railType = railLoader->getTypeAt(ELECTRIC, HORIZONTAL_RAIL);
    //     emit railSelected(railType);
    // });
    // connect(buttonV, &QPushButton::clicked, this, [this]() {
    //     auto railType = railLoader->getTypeAt(ELECTRIC, VERTICAL_RAIL);
    //     emit railSelected(railType);
    // });
    createButtonConnection(buttonH, HORIZONTAL_RAIL);
    createButtonConnection(buttonV, VERTICAL_RAIL);
}

void TTERailBuilderMenu::createButtonConnection(const QPushButton *button, const RAIL_ORIENTATION orientation)
{
    connect(button, &QPushButton::clicked, this, [this, orientation]() {
        auto railType = railLoader->getTypeAt(ELECTRIC, orientation);
        emit railSelected(railType);
    });
}

void TTERailBuilderMenu::setRailLoader(TTERailLoader *loader)
{
    railLoader = loader;
}
