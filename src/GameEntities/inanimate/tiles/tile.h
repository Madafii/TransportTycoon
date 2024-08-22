#ifndef MAPTILE_H
#define MAPTILE_H

#include <QGraphicsItem>
#include <QPainter>

#include "tiletype.h"


class Tile : public QGraphicsItem
{

public:
    Tile(const TileType *tileType, QRectF rect);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    const TileType *tileType;
    QRectF rect;

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void itemMouseEntered(Tile *tile);

private:
};

#endif // MAPTILE_H
