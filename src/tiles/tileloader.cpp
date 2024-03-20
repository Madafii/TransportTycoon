#include "tileloader.h"

TileLoader::TileLoader() {
    // standard tile settings
    tileWidth   = 50;
    tileHeight  = 50;

    QString stdFileName = QString(qgetenv("TTEUSER") + "/images/test.png");

    loadTileImagesFromFile(stdFileName);
}

// TODO: do this later working with default values first
TileLoader::TileLoader(quint16 tileWidth, quint16 tileHeight, quint16 tileAmount) :
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    tileAmount(tileAmount)
{

}

void TileLoader::loadTileImagesFromFile(QString fileName) {
    QImage image(fileName);

    if (image.isNull()) {
        qCritical() << "Failed to load the image from the file: " << fileName;
        return;
    }

    const QRect &imageRect = image.rect();
    tileAmount = imageRect.width()/tileWidth + imageRect.height()/tileHeight;
    // !!! set enumSize manually to highest enum from TILE_TYPE
    quint16 enumSize    = 2;
    quint16 counter     = 0;

    for (int i = 0; i < imageRect.width()/tileWidth; i++) {
        for (int j = 0; j < imageRect.height()/tileHeight; j++) {
            if (counter < enumSize) {
                QPixmap pixImage = QPixmap::fromImage(image.copy(i * tileWidth, j * tileHeight, tileWidth, tileHeight));
                tileTypes.append(TileType(static_cast<TILE_TYPE>(counter), pixImage));
            }
            else {
                qDebug() << "TileLoader: reached end of TileType enums no more TileImages can be loaded from: " << fileName;
                return;
                // tileTypes.append(TileType(TILE_TYPE::NONE,
                //                           QPixmap::fromImage(image.copy(0, 0, i * tileWidth, j * tileHeight))));
            }
            counter++;
        }
    }
}

const QList<TileType>& TileLoader::getTileTypes() {
    return tileTypes;
}

const TileType* TileLoader::getTileTypeAt(TILE_TYPE type) {
    static QHash<TILE_TYPE, const TileType*> typeMap;

    if (typeMap.isEmpty()) {
        foreach(const TileType& tileType, tileTypes) {
            typeMap.insert(tileType.getTileType(), &tileType);
        }
    }

    return typeMap.value(type, nullptr);
}
