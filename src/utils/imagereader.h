#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <QList>

class QPixmap;
class QString;

namespace ImageReader {
    QList<QPixmap> loadPixMapImagesFromFile(QString filePath);
};

#endif // IMAGEREADER_H
