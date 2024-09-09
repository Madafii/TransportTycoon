#include "ttebuildhelper.h"

#include "ttetile.h"
#include "tterail.h"

bool TTEBuildHelper::buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTERailType &buildWhat)
{
    if (auto tile = dynamic_cast<const TTETile*>(&buildOn)) {
        return true;
    }
    else if (auto rail = dynamic_cast<const TTERail*>(&buildOn)) {
        // TODO: probably can remove this later
        return false;
    }
    return false;
}

bool TTEBuildHelper::buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTETileType &buildWhat)
{
    // TODO: implement later for now just allow building on everything
    return true;
}
