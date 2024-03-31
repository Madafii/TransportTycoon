#include "tile.h"

#include <QGraphicsSceneHoverEvent>

Tile::Tile(const TileType *tileType, QRectF rect)
    : tileType(tileType), rect(rect)
{

}


QRectF Tile::boundingRect() const
{
    return tileType->getImage().rect();
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF imageRect = tileType->getImage().rect();
    painter->drawPixmap(imageRect, tileType->getImage(), imageRect);
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //qDebug() << "entered at: " << rect.x() << " | " << rect.y();
    //emit itemMouseEntered(this);
}
