#include "tilemap.h"

#include <QMouseEvent>

TileMap::TileMap(QGraphicsScene *scene, int size_x, int size_y, TileLoader *tileLoader, QWidget *parent) :
    QGraphicsView(scene, parent),
    mapScene(scene),
    tileLoader(tileLoader),
    size_x(size_x),
    size_y(size_y)
{
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            const TileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::GRASS);
            const int size = tileType->getTileImage().height();
            Tile *tile = new Tile(tileType, QRectF(x * size, y * size, size, size));
            tile->setAcceptHoverEvents(true);
            tileList.append(tile);
        }
    }
    loadMapIntoScene(mapScene);

    setMouseTracking(true);

    // setting up coursor Item
    const TileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::RAIL);
    const QPixmap &image = tileType->getTileImage();
    cursorItem = new QGraphicsPixmapItem(image);
    cursorItem->setVisible(false);
    mapScene->addItem(cursorItem);
}

void TileMap::loadMapIntoScene(QGraphicsScene *gS)
{
    foreach (Tile *tile, tileList) {
        tile->setPos(tile->rect.x(), tile->rect.y());
        tile->setZValue(0);
        tile->setFlag(QGraphicsItem::ItemIsSelectable);
        gS->addItem(tile);
    }
}

void TileMap::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsItem *hoveredItem = mapScene->itemAt(this->mapToScene(event->pos()), this->transform());
    cursorItem->setPos(hoveredItem->pos());
}

void TileMap::setCursorVisible(bool visible)
{
    cursorItem->setVisible(visible);
}

bool TileMap::isCursorVisible()
{
    return cursorItem->isVisible();
}
