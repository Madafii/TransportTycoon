#include "tileloader.h"

#include <QPixmap>
#include <QDebug>
#include "imagereader.h"

TileLoader::TileLoader() {
    // standard tile settings
    tileWidth   = 50;
    tileHeight  = 50;

    QString stdFileName = QString(qgetenv("TTEUSER") + "/images/test.png");

    initTileTypes(stdFileName);
}

// TODO: do this later working with default values first
TileLoader::TileLoader(quint16 tileWidth, quint16 tileHeight, quint16 tileAmount) :
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    tileAmount(tileAmount)
{

}

void TileLoader::initTileTypes(QString filePath)
{
    QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);

    // !!! set enumSize manually to highest enum from TILE_TYPE
    quint16 enumSize    = 2;

    quint16 counter     = 0;
    foreach (QPixmap pixmap, pixmapList) {
        if (counter < enumSize) {
            tileTypes.append(TileType(static_cast<TILE_TYPE>(counter), pixmap));
        }
        else {
            qDebug() << "TileLoader: reached end of TileType enums no more TileImages can be loaded from: " << filePath;
            return;
            // tileTypes.append(TileType(TILE_TYPE::NONE,
            //                           QPixmap::fromImage(image.copy(0, 0, i * tileWidth, j * tileHeight))));
        }
        counter++;
    }
}

const QList<TileType>& TileLoader::getTileTypes() {
    return tileTypes;
}

const TileType* TileLoader::getTileTypeAt(TILE_TYPE type) {
    static QHash<TILE_TYPE, const TileType*> typeMap;

    if (typeMap.isEmpty()) {
        foreach(const TileType& tileType, tileTypes) {
            typeMap.insert(tileType.getType(), &tileType);
        }
    }

    return typeMap.value(type, nullptr);
}
