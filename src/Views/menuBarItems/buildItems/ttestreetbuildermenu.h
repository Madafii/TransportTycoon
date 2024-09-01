#ifndef TTESTREETBUILDERMENU_H
#define TTESTREETBUILDERMENU_H

#include "ttebuildermenubase.h"

class TTEStreetBuilderMenu : public TTEBuilderMenuBase
{
public:
    explicit TTEStreetBuilderMenu(QWidget *parent = nullptr);

private:
    void initButtonIcons();
};

#endif // TTESTREETBUILDERMENU_H
