#ifndef TTEINANIMATETYPE_H
#define TTEINANIMATETYPE_H

#include <QPixmap>

// !-------------------count all the enums up from zero---------------------!//

// give all enums a last value ending with '_COUNT' and count them up from 0

enum RAIL_ORIENTATION {
    HORIZONTAL_RAIL,
    DIAGONAL_RAIL,
    LEFTDOWNUPRIGHT_RAIL,
    LEFTUPRIGHTDOWN_RAIL, // TODO: add end of the line types when the rail is disconected aka has no adjacent tile make it look different(like a stop sign or something)
    RAIL_ORIENTATION_COUNT
};

enum RAIL_TYPE {
    ELECTRIC,
    RAIL_TYPE_COUNT
};

enum TILE_ORIENTATION {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    TILE_ORIENTATION_COUNT
};

enum TILE_TYPE {
    GRASS,
    DESERT,
    EXTRA,
    NONE_TILE,
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
