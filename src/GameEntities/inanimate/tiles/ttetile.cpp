#include "ttetile.h"

// #include <QGraphicsSceneHoverEvent>

TTETile::TTETile(const TTETileType *tileType, QRectF rect)
    : TTEInanimateObject<TTETileType>(tileType, rect)
{

}


// QRectF Tile::boundingRect() const
// {
//     return tileType->getImage().rect();
// }

// void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
//     QRectF imageRect = tileType->getImage().rect();
//     painter->drawPixmap(imageRect, tileType->getImage(), imageRect);
// }

// void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
// {
//     //qDebug() << "entered at: " << rect.x() << " | " << rect.y();
//     //emit itemMouseEntered(this);
// }
