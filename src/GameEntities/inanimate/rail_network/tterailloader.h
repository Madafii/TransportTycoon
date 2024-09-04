#ifndef TTERAILLOADER_H
#define TTERAILLOADER_H

#include "tterailtype.h"
#include "tteimagesetloader.h"

class QString;

class TTERailLoader : public TTEImageSetLoader<TTERailType>
{
public:
    TTERailLoader(const QString filePath, const quint16 typeSize = RAIL_TYPE_COUNT, const quint16 orientationSize = RAIL_ORIENTATION_COUNT);

private:
};

#endif // TTERAILLOADER_H
