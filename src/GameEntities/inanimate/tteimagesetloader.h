#ifndef TTEIMAGESETLOADER_H
#define TTEIMAGESETLOADER_H

#include <QList>
#include <QPixmap>
#include <QHash>
#include <QDebug>
#include <QString>

#include "imagereader.h"
#include "tteinanimatetype.h"


template <class C>
class TTEImageSetLoader
{
    // Extract the enums types of C
    using EType        = typename C::FirstType;
    using EOrientation = typename C::SecondType;

    // Ensure that C is derived from BaseClass
    static_assert(std::is_base_of<TTEInanimateType<EType, EOrientation>, C>::value, "C must inherit from TTEInanimateType<T1, T2>");
public:
    TTEImageSetLoader(QString filePath, quint16 typeSize, quint16 orientationSize);

    void initTypes(QString filePath);
    const C* getTypeAt(EType type, EOrientation orienation);
    const QList<C>& getTypes();
    const quint16& getTypeWidth() const { return typeWidth; }
    const quint16& getTypeHeight() const { return typeHeight; }

private:
    quint16 typeWidth, typeHeight, typeAmount, typeSize, orientationSize;
    QList<C> types;
};

// !------------------------implement templates--------------------!

template <typename C>
TTEImageSetLoader<C>::TTEImageSetLoader(QString filePath, quint16 typeSize, quint16 orientationSize)
    : typeSize(typeSize), orientationSize(orientationSize)
{
    initTypes(filePath);
}

///
/// \brief TTEImageSetLoader::initTypes inits a list of types with the order: type^orientation
/// \param filePath
///
template <typename C>
void TTEImageSetLoader<C>::initTypes(QString filePath)
{
    QList<QPixmap> pixmapList = ImageReader::loadPixMapImagesFromFile(filePath);

    quint16 counterType = 0;
    quint16 counterOrientation = 0;
    foreach (QPixmap pixmap, pixmapList) {
        if (counterType < typeSize) {
            types.append(C(static_cast<EType>(counterType), static_cast<EOrientation>(counterOrientation), pixmap));
            counterType++;
        }
        else {
            if (counterOrientation < orientationSize) {
                counterOrientation++;
                counterType = 0;
            }
            else {
                qDebug() << "TileLoader: reached end of TileType enums no more TileImages can be loaded from: " << filePath;
                return;
            }
        }
    }
}

template <typename C>
const QList<C>& TTEImageSetLoader<C>::getTypes()
{
    return types;
}

template <typename C>
const C* TTEImageSetLoader<C>::getTypeAt(EType type, EOrientation orientation)
{
    static QHash<EType, const C*> typeMap;

    if (typeMap.isEmpty()) {
        foreach (const C& tileType, types) {
            typeMap.insert(tileType.getType(), &tileType);
        }
    }

    return typeMap.value(type, nullptr);
}

#endif // TTEIMAGESETLOADER_H
