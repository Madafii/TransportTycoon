#ifndef TILELOADER_H
#define TILELOADER_H

#include <QString>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "tiletype.h"

class TileLoader
{
public:
    TileLoader();
    TileLoader(quint16 tileWidth, quint16 tileHeight, quint16 tileAmount);

    void loadTileImagesFromFile(QString fileName);
    const QList<TileType>& getTileTypes();
    const TileType* getTileTypeAt(TILE_TYPE type);
    inline const quint16& getTileWidth()  { return tileWidth; }
    inline const quint16& getTileHeight() { return tileHeight; }

private:
    quint16 tileWidth, tileHeight, tileAmount;
    QList<TileType> tileTypes;
};

#endif // TILELOADER_H
