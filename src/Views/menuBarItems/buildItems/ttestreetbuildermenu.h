#ifndef TTESTREETBUILDERMENU_H
#define TTESTREETBUILDERMENU_H

#include "ttebuildermenubase.h"
#include "ttestreetloader.h"
#include "ttestreettype.h"

class TTEStreetBuilderMenu : public TTEBuilderMenuBase
{
    Q_OBJECT
public:
    explicit TTEStreetBuilderMenu(TTEStreetLoader *loader, QWidget *parent = nullptr);

    void setStreetLoader(TTEStreetLoader *loader);
signals:
    void streetSelected(const TTEInanimateTypeBase &streetType);

private:
    TTEStreetLoader *streetLoader;
    TTEStreetType *item = nullptr;

    void initButtonIcons();
    void initButtonConnections();

    void createButtonConnection(const QPushButton *button, const STREET_ORIENTATION orientation);
};

#endif // TTESTREETBUILDERMENU_H
