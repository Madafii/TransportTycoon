#ifndef TILETYPE_H
#define TILETYPE_H

#include <QPixmap>
#include <QString>

#include "typeobject.h"

class TileType : public TypeObject<TILE_TYPE>
{
public:
    TileType(TILE_TYPE tileType, const QPixmap &tileImage);
private:
};

#endif // TILETYPE_H
