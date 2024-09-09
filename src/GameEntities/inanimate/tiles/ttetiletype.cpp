#include "ttetiletype.h"

TTETileType::TTETileType(const TILE_TYPE tileType, const TILE_ORIENTATION tileOrientation, const QPixmap &tileImage)
    : TTEInanimateType(tileType, tileOrientation, tileImage)
{

}

bool TTETileType::canIBuildThis(TTEInanimateTypeBase *type)
{
    return true;
}
