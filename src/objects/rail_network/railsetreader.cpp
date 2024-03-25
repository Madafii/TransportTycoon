#include "railsetreader.h"

#include <QImage>
#include <QDebug>
#include "imagereader.h"

RailSetReader::RailSetReader(QString filePath)
{

}

void RailSetReader::initRailSet(QString filePath)
{
    QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);
}
