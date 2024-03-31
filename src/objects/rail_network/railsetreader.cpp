#include "railsetreader.h"

#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "imagereader.h"

RailSetReader::RailSetReader(QString filePath)
{
    // for testing use this file
    filePath = QString(qgetenv("TTEUSER") + "/images/test.png");

    initRailSet(filePath);
}

void RailSetReader::initRailSet(QString filePath)
{
    QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);
}
