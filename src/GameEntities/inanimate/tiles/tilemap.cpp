#include "tilemap.h"

#include <QMouseEvent>

TTETileMap::TTETileMap(QGraphicsScene *scene, int sizeX, int sizeY, TTETileLoader *tileLoader, QWidget *parent) :
    QGraphicsView(scene, parent),
    tileLoader(tileLoader),
    mapScene(scene),
    sizeX(sizeX),
    sizeY(sizeY)
{
    tileSize = tileLoader->getTileTypeAt(TILE_TYPE::GRASS)->getImage().height();

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            const TTETileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::GRASS);
            const int size = tileType->getImage().height();
            TTETile *tile = new TTETile(tileType, QRectF(x * size, y * size, size, size));
            //tile->setAcceptHoverEvents(true);
            tileList.append(tile);
        }
    }
    initScene();

    setMouseTracking(true);

    // setting up coursor Item
    const TTETileType *tileType = tileLoader->getTileTypeAt(TILE_TYPE::RAIL);
    const QPixmap &image = tileType->getImage();
    cursorItem = new QGraphicsPixmapItem(image);
    cursorItem->setVisible(false);
    mapScene->addItem(cursorItem);
}

void TTETileMap::initScene()
{
    foreach (TTETile *tile, tileList) {
        tile->setPos(tile->rect.x(), tile->rect.y());
        tile->setZValue(0);
        tile->setFlag(QGraphicsItem::ItemIsSelectable);
        mapScene->addItem(tile);
    }
}

void TTETileMap::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsItem *hoveredItem = mapScene->itemAt(this->mapToScene(event->pos()), this->transform());
    cursorItem->setPos(hoveredItem->pos());
}

void TTETileMap::setCursorVisible(bool visible)
{
    cursorItem->setVisible(visible);
}

bool TTETileMap::isCursorVisible()
{
    return cursorItem->isVisible();
}

TTETile* TTETileMap::getTileAt(int x, int y)
{
    return tileList.at(x * tileSize + y * tileSize);
}
