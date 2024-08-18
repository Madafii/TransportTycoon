#include "railsetreader.h"

#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "imagereader.h"
#include "railtype.h"

RailSetReader::RailSetReader(QString filePath)
{
    // for testing use this file
    filePath = QString(qgetenv("TTEUSER") + "/images/test.png");

    initRailSet(filePath);
}

void RailSetReader::initRailSet(QString filePath)
{
    QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);

    // require this to be fixed for now.
    tileTypes.append(RailType(RAIL_TYPE::STRAIGHT, pixmapList[0]));
    tileTypes.append(RailType(RAIL_TYPE::DIAGONAL, pixmapList[1]));
}
