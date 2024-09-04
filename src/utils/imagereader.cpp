#include "imagereader.h"

#include <QImage>
#include <QDebug>
#include <QPixmap>

QList<QPixmap> ImageReader::loadPixMapImagesFromFile(const QString &filePath) {
    QImage image(filePath);
    QList<QPixmap> pixmapList;

    // Fixed for all images
    const int tileSize = 50;

    if (image.isNull()) {
        qCritical() << "ImageReader: Failed to load image from the file:" << filePath;
        return pixmapList;
    }

    const QRect imageRect = image.rect();
    int numCols = (imageRect.width() + tileSize - 1) / tileSize;
    int numRows = (imageRect.height() + tileSize - 1) / tileSize;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int x = j * tileSize;
            int y = i * tileSize;
            int width = (x + tileSize > imageRect.width()) ? (imageRect.width() - x) : tileSize;
            int height = (y + tileSize > imageRect.height()) ? (imageRect.height() - y) : tileSize;
            pixmapList.append(QPixmap::fromImage(image.copy(x, y, width, height)));
        }
    }

    return pixmapList;
}
