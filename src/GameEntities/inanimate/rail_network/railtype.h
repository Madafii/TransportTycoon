#ifndef RAILTYPE_H
#define RAILTYPE_H

#include "tteinanimatetype.h"

class QPixmap;

class RailType : public TTEInanimateType<RAIL_TYPE, RAIL_ORIENTATION>
{
public:
    RailType(RAIL_TYPE railType, RAIL_ORIENTATION railOrientation, const QPixmap &railImage);
};

#endif // RAILTYPE_H
