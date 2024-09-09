#include "tterailtype.h"

TTERailType::TTERailType(RAIL_TYPE railType, RAIL_ORIENTATION railOrientation, const QPixmap &railImage)
    : TTEInanimateType(railType, railOrientation, railImage)
{

}

bool TTERailType::canIBuildThis(TTEInanimateTypeBase *type)
{
    return true;
}
