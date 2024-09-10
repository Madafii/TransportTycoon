#include "ttestreetbuildermenu.h"

TTEStreetBuilderMenu::TTEStreetBuilderMenu(TTEStreetLoader *loader, QWidget *parent)
    : TTEBuilderMenuBase(parent), streetLoader(loader)
{
    initButtonIcons();
    initButtonConnections();
}

void TTEStreetBuilderMenu::initButtonIcons()
{
    buttonH->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonV->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
}

void TTEStreetBuilderMenu::initButtonConnections()
{
    createButtonConnection(buttonH, HORIZONTAL_STREET);
    createButtonConnection(buttonV, VERTICAL_STREET);
}

void TTEStreetBuilderMenu::createButtonConnection(const QPushButton *button, const STREET_ORIENTATION orientation)
{
    connect(button, &QPushButton::clicked, this, [this, orientation]() {
        const TTEStreetType &streetType = streetLoader->getTypeAt(CONCRETE_FANCY, orientation);
        emit streetSelected(streetType);
    });
}

void TTEStreetBuilderMenu::setStreetLoader(TTEStreetLoader *loader)
{
    streetLoader = loader;
}
