#ifndef RAILTYPE_H
#define RAILTYPE_H

#include <ttetypeobject.h>

class QPixmap;

class RailType : public TTETypeObject<RAIL_TYPE>
{
public:
    RailType(RAIL_TYPE railType, const QPixmap &railImage);

private:
};

#endif // RAILTYPE_H
