#ifndef TILETYPE_H
#define TILETYPE_H

#include <QPixmap>
#include <QString>

// set enums 0, 1, 2,... without jumps from like 3, 5,...
enum TILE_TYPE {
    GRASS = 0,
    RAIL = 1,
    NONE = 2
};

class TileType
{
public:
    TileType(TILE_TYPE tileType, QPixmap image);
    TILE_TYPE getTileType() const { return tileType; }
    QPixmap getTileImage() const { return tileImage; }

private:
    TILE_TYPE tileType;
    QPixmap tileImage;
};

#endif // TILETYPE_H
