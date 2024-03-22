#include "tile.h"

#include <QGraphicsSceneHoverEvent>

Tile::Tile(const TileType *tileType, QRectF rect)
    : tileType(tileType), rect(rect)
{

}


QRectF Tile::boundingRect() const
{
    return tileType->getTileImage().rect();
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF imageRect = tileType->getTileImage().rect();
    painter->drawPixmap(imageRect, tileType->getTileImage(), imageRect);
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //qDebug() << "entered at: " << rect.x() << " | " << rect.y();
    //emit itemMouseEntered(this);
}
