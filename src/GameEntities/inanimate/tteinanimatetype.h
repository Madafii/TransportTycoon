#ifndef TTEINANIMATETYPE_H
#define TTEINANIMATETYPE_H

#include <QPixmap>

// !-------------------count all the enums up from zero---------------------!//
// give all enums a last value ending with '_COUNT'

enum RAIL_ORIENTATION {
    HORIZONTAL_RAIL = 0,
    DIAGONAL_RAIL = 1,
    LEFTDOWNUPRIGHT_RAIL = 2,
    LEFTUPRIGHTDOWN_RAIL = 3, // TODO: add end of the line types when the rail is disconected aka has no adjacent tile make it look different(like a stop sign or something)
    RAIL_ORIENTATION_COUNT
};

enum RAIL_TYPE {
    ELECTRIC = 0,
    RAIL_TYPE_COUNT
};

enum TILE_ORIENTATION {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    TILE_ORIENTATION_COUNT
};

enum TILE_TYPE {
    GRASS = 0,
    DESERT = 1,
    EXTRA = 2,
    NONE_TILE = 3,
    TILE_TYPE_COUNT
};

template <typename T1, typename T2>
class TTEInanimateType
{
public:
    TTEInanimateType(T1 type, T2 orientation, const QPixmap &image);

    using FirstType = T1;
    using SecondType = T2;

    T1 getType() const { return type; }
    T2 getOrientation() const { return orientation; }
    const QPixmap getImage() const { return image; }

private:
    T1 type;
    T2 orientation;
    QPixmap image;
};

template <typename T1, typename T2>
TTEInanimateType<T1, T2>::TTEInanimateType(T1 type, T2 orientation, const QPixmap &image)
    : type(type), orientation(orientation), image(image)
{}

#endif // TTEINANIMATETYPE_H
