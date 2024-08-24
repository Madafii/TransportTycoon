#ifndef TTETILELOADER_H
#define TTETILELOADER_H

#include <QString>
#include <QImage>

#include "ttetiletype.h"
#include "tteimagesetloader.h"

class TTETileLoader : public TTEImageSetLoader<TTETileType>
{
public:
    TTETileLoader(const QString filePath, quint16 typeSize = TILE_TYPE_COUNT, quint16 orientationSize = TILE_ORIENTATION_COUNT);

private:

};

#endif // TTETILELOADER_H
