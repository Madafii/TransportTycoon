#include "ttetileloader.h"

TTETileLoader::TTETileLoader(const QString filePath, quint16 typeSize, quint16 orientationSize) :
    TTEImageSetLoader<TTETileType>(filePath, typeSize, orientationSize)
{

}

// void TileLoader::initTileTypes(QString filePath)
// {
//     QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);

//     // !!! set enumSize manually to highest enum from TILE_TYPE
//     quint16 enumSize    = 2;

//     quint16 counter     = 0;
//     foreach (QPixmap pixmap, pixmapList) {
//         if (counter < enumSize) {
//             tileTypes.append(TileType(static_cast<TILE_TYPE>(counter), pixmap));
//         }
//         else {
//             qDebug() << "TileLoader: reached end of TileType enums no more TileImages can be loaded from: " << filePath;
//             return;
//             // tileTypes.append(TileType(TILE_TYPE::NONE,
//             //                           QPixmap::fromImage(image.copy(0, 0, i * tileWidth, j * tileHeight))));
//         }
//         counter++;
//     }
// }

// const QList<TileType>& TileLoader::getTileTypes() {
//     return tileTypes;
// }

// const TileType* TileLoader::getTileTypeAt(TILE_TYPE type) {
//     static QHash<TILE_TYPE, const TileType*> typeMap;

//     if (typeMap.isEmpty()) {
//         foreach(const TileType& tileType, tileTypes) {
//             typeMap.insert(tileType.getType(), &tileType);
//         }
//     }

//     return typeMap.value(type, nullptr);
// }
