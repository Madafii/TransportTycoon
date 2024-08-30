#include "imagereader.h"

#include <QImage>
#include <QDebug>
#include <QPixmap>

QList<QPixmap> ImageReader::loadPixMapImagesFromFile(QString filePath) {
    QImage image(filePath);
    QList<QPixmap> pixmapList;

    // fixed for all images
    const int tileSize = 50;

    if (image.isNull()) {
        qCritical() << "ImageReader: Failed to load image from the file: " << filePath;
        return pixmapList;
    }

    const QRect &imageRect = image.rect();
    for (int i = 0; i < imageRect.width()/tileSize; i++) {
        for (int j = 0; j < imageRect.height()/tileSize; j++) {
            pixmapList.append(QPixmap::fromImage(image.copy(j * tileSize, i * tileSize, tileSize, tileSize)));
        }
    }
    return pixmapList;
}
