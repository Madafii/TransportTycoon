#include "tterailloader.h"

#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "imagereader.h"

TTERailLoader::TTERailLoader(const QString filePath, const quint16 typeSize, const quint16 orientationSize)
    : TTEImageSetLoader<TTERailType>(filePath, typeSize, orientationSize)
{
}


