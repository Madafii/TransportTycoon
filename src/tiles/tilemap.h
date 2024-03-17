#ifndef TILEMAP_H
#define TILEMAP_H

#include "tile.h"
#include "tiletype.h"
#include "tileloader.h"

class TileMap
{
public:
    TileMap(int size_x, int size_y, TileLoader *tileLoader);
    QList<Tile>& getTileList() { return tileList; }

private:
    TileLoader *tileLoader;
    int size_x, size_y;
    QList<Tile> tileList;
};

#endif // TILEMAP_H
