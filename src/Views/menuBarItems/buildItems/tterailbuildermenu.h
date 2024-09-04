#ifndef TTERAILBUILDERMENU_H
#define TTERAILBUILDERMENU_H

#include <QWidget>
#include "ttebuildermenubase.h"
#include "tterailtype.h"

class TTERailLoader;
class QGraphicsItem;

class TTERailBuilderMenu : public TTEBuilderMenuBase
{
    Q_OBJECT
public:
    explicit TTERailBuilderMenu(QWidget *parent = nullptr);

    void setRailLoader(TTERailLoader *loader);

signals:
    void railSelected(const TTERailType *railType);

private:
    TTERailLoader *railLoader = nullptr;
    TTERailType *item = nullptr;

    void initButtonIcons();
    void initButtonConnections();

    void createButtonConnection(const QPushButton *button, const RAIL_ORIENTATION orientation);
};

#endif // TTERAILBUILDERMENU_H
