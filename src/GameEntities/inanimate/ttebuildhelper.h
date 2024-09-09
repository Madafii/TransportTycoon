#ifndef TTEBUILDHELPER_H
#define TTEBUILDHELPER_H

#include "tterailtype.h"
#include "ttetiletype.h"

class TTEBuildHelper
{
public:
    TTEBuildHelper() = delete;

    static bool buildHereAllowed(const TTETileType &buildOn, const TTERailType &buildWhat);
    static bool buildHereAllowed(const TTETileType &buildOn, const TTETileType &buildWhat);
};

#endif // TTEBUILDHELPER_H
