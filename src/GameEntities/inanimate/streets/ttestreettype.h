#ifndef TTESTREETTYPE_H
#define TTESTREETTYPE_H

#include <tteinanimatetype.h>

enum STREET_ORIENTATION {
    STREET_BEGIN = 0,                           // enumeration begin
    HORIZONTAL_STREET = 0,
    VERTICAL_STREET,
    STREET_ORIENTATION_END                      // enumeration end
};

enum STREET_TYPE {
    CONCRETE_STANDARD,
    CONCRETE_FANCY,
    STREET_TYPE_COUNT
};

class TTEStreetType : public TTEInanimateType<STREET_TYPE, STREET_ORIENTATION>
{
public:
    TTEStreetType(STREET_TYPE railType, STREET_ORIENTATION railOrientation, const QPixmap &railImage);
};

#endif // TTESTREETTYPE_H
