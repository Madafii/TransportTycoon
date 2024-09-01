#ifndef TTERAILBUILDERMENU_H
#define TTERAILBUILDERMENU_H

#include <QWidget>
#include "ttebuildermenubase.h"

class TTERailBuilderMenu : public TTEBuilderMenuBase
{
    Q_OBJECT

public:
    explicit TTERailBuilderMenu(QWidget *parent = nullptr);

private:
    void initButtonIcons();
};

#endif // TTERAILBUILDERMENU_H
