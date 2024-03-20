#ifndef MAPTILE_H
#define MAPTILE_H

#include <QGraphicsItem>
#include <QPainter>

#include "tiletype.h"


class MapTile : public QGraphicsItem
{
public:
    MapTile(const TileType *tileType, QRectF rect);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    const TileType *tileType;
    QRectF rect;

private:
};

#endif // MAPTILE_H
