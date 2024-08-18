#ifndef TILETYPE_H
#define TILETYPE_H

#include <QPixmap>
#include <QString>

#include "ttetypeobject.h"

class TileType : public TTETypeObject<TILE_TYPE>
{
public:
    TileType(TILE_TYPE tileType, const QPixmap &tileImage);
private:
};

#endif // TILETYPE_H
