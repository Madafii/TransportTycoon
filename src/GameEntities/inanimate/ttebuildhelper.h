#ifndef TTEBUILDHELPER_H
#define TTEBUILDHELPER_H

#include "tteinanimateobject.h"
#include "tterailtype.h"
#include "ttetiletype.h"

class TTEBuildHelper
{
public:
    TTEBuildHelper() = delete;

    static bool buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTERailType &buildWhat);
    static bool buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTETileType &buildWhat);
};

#endif // TTEBUILDHELPER_H
