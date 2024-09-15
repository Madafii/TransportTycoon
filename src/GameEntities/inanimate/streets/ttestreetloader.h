#ifndef TTESTREETLOADER_H
#define TTESTREETLOADER_H

#include <tteimagesetloader.h>
#include "ttestreettype.h"

class TTEStreetLoader : public TTEImageSetLoader<TTEStreetType>
{
public:
    TTEStreetLoader(const QString filePath, const quint16 typeSize = STREET_TYPE_COUNT, const quint16 orientationSize = STREET_ORIENTATION_END);
};

#endif // TTESTREETLOADER_H
