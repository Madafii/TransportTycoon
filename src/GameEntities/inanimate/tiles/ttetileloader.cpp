#include "ttetileloader.h"

TTETileLoader::TTETileLoader(const QString filePath, quint16 typeSize, quint16 orientationSize) :
    TTEImageSetLoader<TTETileType>(filePath, typeSize, orientationSize)
{

}
