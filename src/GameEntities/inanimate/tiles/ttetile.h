#ifndef MAPTILE_H
#define MAPTILE_H

#include <QGraphicsItem>
#include <QPainter>

#include "ttetiletype.h"
#include "tteinanimateobject.h"


class TTETile : public TTEInanimateObject<TTETileType>
{

public:
    TTETile(const TTETileType &tileType, QRectF rect);

private:
};

#endif // MAPTILE_H
