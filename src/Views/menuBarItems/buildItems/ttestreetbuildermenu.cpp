#include "ttestreetbuildermenu.h"
#include "tterailtype.h"
#include "ttetiletype.h"

TTEStreetBuilderMenu::TTEStreetBuilderMenu(TTEStreetLoader *loader, QWidget *parent)
    : TTEBuilderMenuBase(parent), streetLoader(loader)
{
    initButtonIcons();
    initButtonConnections();
}

void TTEStreetBuilderMenu::initButtonIcons()
{
    buttonWO->setIcon(QIcon(":/icons/build_rail_iconH.jpg"));
    buttonSN->setIcon(QIcon(":/icons/build_rail_iconV.jpg"));
}

void TTEStreetBuilderMenu::initButtonConnections()
{
    createButtonConnection(buttonWO, HORIZONTAL_STREET);
    createButtonConnection(buttonSN, VERTICAL_STREET);
}

void TTEStreetBuilderMenu::createButtonConnection(const QPushButton *button, const STREET_ORIENTATION orientation)
{
    connect(button, &QPushButton::clicked, this, [this, orientation]() {
        const TTEStreetType *streetType = streetLoader->getTypePtrAt(CONCRETE_FANCY, orientation);
        emit streetSelected(streetType);
    });
}

void TTEStreetBuilderMenu::setStreetLoader(TTEStreetLoader *loader)
{
    streetLoader = loader;
}
