#ifndef TTERAILTYPE_H
#define TTERAILTYPE_H

#include "tteinanimatetype.h"

class QPixmap;

enum RAIL_ORIENTATION {
    BEGIN_RAIL = 0,                             // for enumeration begin
    HORIZONTAL_RAIL = 0,
    VERTICAL_RAIL,
    LEFTDOWNUPRIGHT_RAIL,
    LEFTUPRIGHTDOWN_RAIL,
    HORIZONTAL_RAIL_END,
    VERTICAL_RAIL_END,
    LEFTDOWNUPRIGHT_RAIL_END,
    LEFTUPRIGHTDOWN_RAIL_END,
    HORIZONTAL_RAIL_FORTESTING,
    VERTICAL_RAIL_FORTESTING,
    LEFTDOWNUPRIGHT_RAIL_FORTESTING,
    LEFTUPRIGHTDOWN_RAIL_FORTESTING,
    HORIZONTAL_RAIL_END_FORTESTING,
    VERTICAL_RAIL_END_FORTESTING,
    LEFTDOWNUPRIGHT_RAIL_END_FORTESTING,
    LEFTUPRIGHTDOWN_RAIL_END_FORTESTING,
    RAIL_ORIENTATION_END                        // for enumeration end
};

enum RAIL_TYPE {
    RAIL_TYPE_BEGIN = 0,                             // for enumeration begin
    ELECTRIC = 0,
    STEAM,
    MONO,
    ELECTRIC_FORTESATIN,
    STEAM_FORTESATIN,
    MONO_FORTE,
    RAIL_TYPE_END                               // for enumeration end
};

class TTERailType : public TTEInanimateType<RAIL_TYPE, RAIL_ORIENTATION>
{
public:
    TTERailType(RAIL_TYPE railType, RAIL_ORIENTATION railOrientation, const QPixmap &railImage);

    // virtual bool canIBuildThis(TTEInanimateTypeBase *type) override;
};

#endif // TTERAILTYPE_H
