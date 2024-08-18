#ifndef TILELOADER_H
#define TILELOADER_H

#include <QString>
#include <QImage>
#include "tiletype.h"

class TileLoader
{
public:
    TileLoader();
    TileLoader(quint16 tileWidth, quint16 tileHeight, quint16 tileAmount);

    void initTileTypes(QString filePath);

    const QList<TileType>& getTileTypes();
    const TileType* getTileTypeAt(TILE_TYPE type);
    const quint16& getTileWidth() const { return tileWidth; }
    const quint16& getTileHeight() const { return tileHeight; }

private:
    quint16 tileWidth, tileHeight, tileAmount;
    QList<TileType> tileTypes;
};

#endif // TILELOADER_H
