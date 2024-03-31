#ifndef RAILTYPE_H
#define RAILTYPE_H

#include <typeobject.h>

class QPixmap;

class RailType : public TypeObject<RAIL_TYPE>
{
public:
    RailType(RAIL_TYPE railType, const QPixmap &railImage);

private:
};

#endif // RAILTYPE_H
