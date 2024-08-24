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
    // Extract the enum types of C
    using EType        = typename C::FirstType;
    using EOrientation = typename C::SecondType;

    // Ensure that C is derived from TTEInanimateType<T1, T2>
    static_assert(std::is_base_of<TTEInanimateType<EType, EOrientation>, C>::value, "C must inherit from TTEInanimateType<T1, T2>");
public:
    TTEImageSetLoader(QString filePath, const quint16 typeSize, const quint16 orientationSize);

    void initTypes(QString filePath);
    const C* getTypeAt(const EType type, const EOrientation orienation) const;
    const QList<C>& getTypes() const;
    const quint16& getTypeWidth() const { return typeWidth; }
    const quint16& getTypeHeight() const { return typeHeight; }

private:
    const quint16 typeWidth = 50;
    const quint16 typeHeight = 50;
    quint16 typeSize, orientationSize;
    QList<C> types;
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
const QList<C>& TTEImageSetLoader<C>::getTypes() const
{
    return types;
}

template <typename C>
const C* TTEImageSetLoader<C>::getTypeAt(const EType type, const EOrientation orientation) const
{
    static QHash<const std::pair<EType, EOrientation>, const C*> typeMap;

    if (typeMap.isEmpty()) {
        foreach (const C& type, types) {
            typeMap.insert(std::pair<EType, EOrientation>(type.getType(), type.getOrientation()), &type);
        }
    }

    return typeMap.value(std::pair<EType, EOrientation>(type, orientation), nullptr);
}

#endif // TTEIMAGESETLOADER_H
