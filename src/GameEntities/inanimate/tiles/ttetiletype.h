#ifndef TTETILETYPE_H
#define TTETILETYPE_H

#include <QPixmap>
#include <QString>

#include "tteinanimatetype.h"

class TTETileType : public TTEInanimateType<TILE_TYPE, TILE_ORIENTATION>
{
public:
    TTETileType(const TILE_TYPE tileType, const TILE_ORIENTATION tileOrientation, const QPixmap &tileImage);

private:
};

#endif // TTETILETYPE_H
