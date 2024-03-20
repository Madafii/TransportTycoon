#ifndef TILEMAP_H
#define TILEMAP_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "maptile.h"
#include "tileloader.h"

class TileType;

class TileMap
{
public:
    TileMap(int size_x, int size_y, TileLoader *tileLoader);

    void loadMapIntoScene(QGraphicsScene *gS);

    QList<MapTile*>& getTileList() { return tileList; }

private:
    TileLoader *tileLoader;
    int size_x, size_y;
    QList<MapTile*> tileList;
};

#endif // TILEMAP_H
