#include "ttetypeobject.h"

template <typename T>
TTETypeObject<T>::TTETypeObject(T tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

// have to specify because of some linking error i guess. Maybe should try to fix it.
template<> TTETypeObject<TILE_TYPE>::TTETypeObject(TILE_TYPE tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

template<> TTETypeObject<RAIL_TYPE>::TTETypeObject(RAIL_TYPE tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

