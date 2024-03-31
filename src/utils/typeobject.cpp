#include "typeobject.h"

template <typename T>
TypeObject<T>::TypeObject(T tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

// have to specify because of some linking error i guess. Maybe should try to fix it.
template<> TypeObject<TILE_TYPE>::TypeObject(TILE_TYPE tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

template<> TypeObject<RAIL_TYPE>::TypeObject(RAIL_TYPE tileType, const QPixmap &image)
    : type(tileType), image(image)
{}

