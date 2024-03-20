#include "maptile.h"

MapTile::MapTile(const TileType *tileType, QRectF rect)
    : tileType(tileType), rect(rect)
{

}


QRectF MapTile::boundingRect() const
{
    return tileType->getTileImage().rect();
}

void MapTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF imageRect = tileType->getTileImage().rect();
    painter->drawPixmap(imageRect, tileType->getTileImage(), imageRect);
}
