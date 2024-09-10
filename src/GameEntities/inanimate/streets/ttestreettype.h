#ifndef TTESTREETTYPE_H
#define TTESTREETTYPE_H

#include <tteinanimatetype.h>

class TTEStreetType : public TTEInanimateType<STREET_TYPE, STREET_ORIENTATION>
{
public:
    TTEStreetType(STREET_TYPE railType, STREET_ORIENTATION railOrientation, const QPixmap &railImage);
};

#endif // TTESTREETTYPE_H
