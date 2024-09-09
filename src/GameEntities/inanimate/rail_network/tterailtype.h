#ifndef TTERAILTYPE_H
#define TTERAILTYPE_H

#include "tteinanimatetype.h"

class QPixmap;

class TTERailType : public TTEInanimateType<RAIL_TYPE, RAIL_ORIENTATION>
{
public:
    TTERailType(RAIL_TYPE railType, RAIL_ORIENTATION railOrientation, const QPixmap &railImage);

    virtual bool canIBuildThis(TTEInanimateTypeBase *type) override;
};

#endif // TTERAILTYPE_H
