#ifndef TTETILETYPE_H
#define TTETILETYPE_H

#include <QPixmap>
#include <QString>

#include "tteinanimatetype.h"

enum TILE_ORIENTATION {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    TILE_ORIENTATION_COUNT
};

enum TILE_TYPE {
    GRASS,
    DESERT,
    EXTRA,
    NONE_TILE,
    TILE_TYPE_COUNT
};

class TTETileType : public TTEInanimateType<TILE_TYPE, TILE_ORIENTATION>
{
public:
    TTETileType(const TILE_TYPE tileType, const TILE_ORIENTATION tileOrientation, const QPixmap &tileImage);

    // virtual bool canIBuildThis(TTEInanimateTypeBase *type) override;
private:
};

#endif // TTETILETYPE_H
