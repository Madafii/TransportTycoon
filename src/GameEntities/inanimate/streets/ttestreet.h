#ifndef TTESTREET_H
#define TTESTREET_H

#include "tteinanimateobject.h"
#include "ttestreettype.h"

class TTEStreet : public TTEInanimateObject<TTEStreetType>
{
public:
    TTEStreet(const TTEStreetType &streetType);
};

#endif // TTESTREET_H
