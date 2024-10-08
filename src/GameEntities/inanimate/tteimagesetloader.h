#ifndef TTEIMAGESETLOADER_H
#define TTEIMAGESETLOADER_H

#include <QList>
#include <QPixmap>
#include <QHash>
#include <QDebug>
#include <QElapsedTimer>
#include <QObject>

#include "imagereader.h"
#include "tteinanimatetype.h"

class TTEImageSetLoaderBase {};

template <class C>
class TTEImageSetLoader
{
    // Extract the enum types of C for outside use
    using EType        = typename C::FirstType;
    using EOrientation = typename C::SecondType;

    static_assert(std::is_base_of<TTEInanimateType<EType, EOrientation>, C>::value, "C must inherit from TTEInanimateType<T1, T2>");
public:
    TTEImageSetLoader(QString filePath, const quint16 typeSize, const quint16 orientationSize);

    void initTypes(const QString &filePath);
    const C* getTypePtrAt(const EType type, const EOrientation orientation) const;
    const C& getTypeAt(const EType type, const EOrientation orientation) const;
    const QList<C>& getTypes() const;
    const quint16& getTypeWidth() const { return typeWidth; }
    const quint16& getTypeHeight() const { return typeHeight; }

private:
    const quint16 typeWidth = 50;
    const quint16 typeHeight = 50;
    quint16 typeSize, orientationSize;
    QList<C> types;
    QHash<std::pair<EType, EOrientation>, const C*> typeMap;
};

// !------------------------implement templates--------------------!

template <typename C>
TTEImageSetLoader<C>::TTEImageSetLoader(QString filePath, const quint16 typeSize, const quint16 orientationSize)
    : typeSize(typeSize), orientationSize(orientationSize)
{
    initTypes(filePath);
}

///
/// \brief TTEImageSetLoader::initTypes inits a list of types with the order: type^orientation
/// \param filePath
///
template <typename C>
void TTEImageSetLoader<C>::initTypes(const QString &filePath)
{
    QElapsedTimer timer;
    timer.start();

    const QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);

    QPixmap defaultPixmap(50, 50);
    defaultPixmap.fill(QColor(Qt::white));

    quint16 counterType = 0;
    quint16 counterOrientation = 0;

    for (const QPixmap &pixmap : pixmapList) {
        if (counterOrientation < orientationSize) {
            types.append(C(static_cast<EType>(counterType), static_cast<EOrientation>(counterOrientation), pixmap));
            counterOrientation++;
        } else {
            counterType++;
            if (counterType < typeSize) {
                counterOrientation = 0;
            } else {
                qDebug() << "TTEImageSetLoader: all types got a image assigned: " << filePath;
                break;
            }
        }
    }

    // Fill the remaining slots with defaultPixmap
    while (counterType < typeSize) {
        while (counterOrientation < orientationSize) {
            types.append(C(static_cast<EType>(counterType), static_cast<EOrientation>(counterOrientation), defaultPixmap));
            counterOrientation++;
            qWarning() << QString("TTEImageSetLoader: added blank QPixmap for type pair: %1, %2").arg(counterType).arg(counterOrientation);
        }
        counterType++;
        counterOrientation = 0;
    }

    // Initialize typeMap once
    for (const C& type : types) {
        typeMap.emplace(std::make_pair(type.getType(), type.getOrientation()), &type);
    }

    qDebug() << "TTEImageSetLoader: initializing images for types took: " << timer.elapsed() << "milliseconds";
}

template <typename C>
const QList<C>& TTEImageSetLoader<C>::getTypes() const
{
    return types;
}

template <typename C>
const C* TTEImageSetLoader<C>::getTypePtrAt(const EType type, const EOrientation orientation) const
{
    const C* typePtr = typeMap.value(std::make_pair(type, orientation), nullptr);
    if (!typePtr) {
        throw std::runtime_error("Type or orientation not found");
    }
    return typePtr;
}

template <typename C>
const C& TTEImageSetLoader<C>::getTypeAt(const EType type, const EOrientation orientation) const
{
    return *getTypePtrAt(type, orientation);
}




#endif // TTEIMAGESETLOADER_H
