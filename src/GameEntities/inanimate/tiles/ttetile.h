#ifndef MAPTILE_H
#define MAPTILE_H

#include "ttetiletype.h"
#include "tteinanimateobject.h"


class TTETile : public TTEInanimateObject<TTETileType>
{

public:
    TTETile(const TTETileType &tileType);
private:
};

#endif // MAPTILE_H
