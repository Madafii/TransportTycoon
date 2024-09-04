#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <QList>

class QPixmap;
class QString;

namespace ImageReader {
    QList<QPixmap> loadPixMapImagesFromFile(const QString &filePath);
};

#endif // IMAGEREADER_H
