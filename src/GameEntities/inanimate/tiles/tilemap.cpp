#include "tilemap.h"

#include <QMouseEvent>

TileMap::TileMap(QGraphicsScene *scene, int sizeX, int sizeY, TileLoader *tileLoader, QWidget *parent) :
    QGraphicsView(scene, parent),
    tileLoader(tileLoader),
    mapScene(scene),
    sizeX(sizeX),
    sizeY(sizeY)
{
    tileSize = tileLoader->getTileTypeAt(TILE_TYPE::GRASS)->getImage().height();

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            const TileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::GRASS);
            const int size = tileType->getImage().height();
            Tile *tile = new Tile(tileType, QRectF(x * size, y * size, size, size));
            //tile->setAcceptHoverEvents(true);
            tileList.append(tile);
        }
    }
    initScene();

    setMouseTracking(true);

    // setting up coursor Item
    const TileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::RAIL);
    const QPixmap &image = tileType->getImage();
    cursorItem = new QGraphicsPixmapItem(image);
    cursorItem->setVisible(false);
    mapScene->addItem(cursorItem);
}

void TileMap::initScene()
{
    foreach (Tile *tile, tileList) {
        tile->setPos(tile->rect.x(), tile->rect.y());
        tile->setZValue(0);
        tile->setFlag(QGraphicsItem::ItemIsSelectable);
        mapScene->addItem(tile);
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

Tile* TileMap::getTileAt(int x, int y)
{
    return tileList.at(x * tileSize + y * tileSize);
}
