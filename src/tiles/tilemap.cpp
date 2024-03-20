#include "tilemap.h"

TileMap::TileMap(int size_x, int size_y, TileLoader *tileLoader) :
    tileLoader(tileLoader),
    size_x(size_x),
    size_y(size_y)
{
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            const TileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::GRASS);
            const int size = tileType->getTileImage().height();
            MapTile *tile = new MapTile(tileType, QRectF(x * size, y * size, size, size));
            tileList.append(tile);
        }
    }
}

void TileMap::loadMapIntoScene(QGraphicsScene *gS) {
    foreach (MapTile *tile, tileList) {
        tile->setPos(tile->rect.x(), tile->rect.y());
        tile->setFlag(QGraphicsItem::ItemIsSelectable);
        gS->addItem(tile);
    }
}
