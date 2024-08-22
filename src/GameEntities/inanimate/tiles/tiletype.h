#ifndef TILETYPE_H
#define TILETYPE_H

#include <QPixmap>
#include <QString>

#include "tteinanimatetype.h"

class TileType : public TTEInanimateType<TILE_TYPE, TILE_ORIENTATION>
{
public:
    TileType(const TILE_TYPE tileType, const TILE_ORIENTATION tileOrientation, const QPixmap &tileImage);
private:
};

#endif // TILETYPE_H
