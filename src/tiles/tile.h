#ifndef TILE_H
#define TILE_H

class TileType;

class Tile
{
public:
    Tile(const TileType *tileType, int posX, int posY);
    const TileType *tileType;
    int posX, posY;

private:

};

#endif // TILE_H
