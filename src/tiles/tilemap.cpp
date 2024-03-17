#include "tilemap.h"

TileMap::TileMap(int size_x, int size_y, TileLoader *tileLoader) :
    tileLoader(tileLoader),
    size_x(size_x),
    size_y(size_y)
{
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            tileList.append(Tile(tileLoader->getTileTypeAt(TILE_TYPE::GRASS), x * 50, y * 50));
        }
    }
}
