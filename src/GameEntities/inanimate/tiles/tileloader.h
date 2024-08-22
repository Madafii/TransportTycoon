#ifndef TILELOADER_H
#define TILELOADER_H

#include <QString>
#include <QImage>

#include "tiletype.h"
#include "tteimagesetloader.h"

class TileLoader : public TTEImageSetLoader<TileType>
{
public:
    TileLoader();

private:

};

#endif // TILELOADER_H
