#ifndef TTERAILBUILDERMENU_H
#define TTERAILBUILDERMENU_H

#include <QWidget>
#include "ttebuildhelper.h"
#include "ttebuildermenubase.h"
#include "tterailtype.h"

class TTERailLoader;

class TTERailBuilderMenu : public TTEBuilderMenuBase
{
    Q_OBJECT
public:
    explicit TTERailBuilderMenu(TTERailLoader *loader, QWidget *parent = nullptr);

    void setRailLoader(TTERailLoader *loader);

signals:
    void railSelected(const TTEBuildHelper::typeVariant *railType);

private:
    TTERailLoader *railLoader;
    TTERailType *item = nullptr;

    void initButtonIcons();
    void initButtonConnections();

    void createButtonConnection(const QPushButton *button, const RAIL_ORIENTATION orientation);
};

#endif // TTERAILBUILDERMENU_H
