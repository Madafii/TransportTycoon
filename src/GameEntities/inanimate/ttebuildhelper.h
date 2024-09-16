#ifndef TTEBUILDHELPER_H
#define TTEBUILDHELPER_H

#include "tteinanimateobject.h"
#include "tterailtype.h"
#include "ttetiletype.h"
#include "ttestreettype.h"

class TTEBuildHelper
{
public:
    TTEBuildHelper() = delete;

    using typeVariant = std::variant<TTERailType*, TTEStreetType*, TTETileType*>;

    static bool buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTERailType &buildWhat);
    static bool buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTETileType &buildWhat);
    static bool buildHereAllowed(const TTEInanimateObjectBase &buildOn, const TTEStreetType &buildWhat);
};

#endif // TTEBUILDHELPER_H
