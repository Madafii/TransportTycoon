#include "railtype.h"

RailType::RailType(RAIL_TYPE railType, RAIL_ORIENTATION railOrientation, const QPixmap &railImage)
    : TTEInanimateType(railType, railOrientation, railImage), railTypeSize(RAIL_TYPE_COUNT), railOrientationSize(RAIL_ORIENTATION_COUNT)
{

}
