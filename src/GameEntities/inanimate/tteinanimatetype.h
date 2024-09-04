#ifndef TTEINANIMATETYPE_H
#define TTEINANIMATETYPE_H

#include <QPixmap>

// !-------------------count all the enums up from zero---------------------!//

// give all enums a last value ending with '_COUNT' and count them up from 0

enum RAIL_ORIENTATION {
    HORIZONTAL_RAIL,
    VERTICAL_RAIL,
    LEFTDOWNUPRIGHT_RAIL,
    LEFTUPRIGHTDOWN_RAIL,
    HORIZONTAL_RAIL_END,
    VERTICAL_RAIL_END,
    LEFTDOWNUPRIGHT_RAIL_END,
    LEFTUPRIGHTDOWN_RAIL_END,
    HORIZONTAL_RAIL_FORTESTING,
    VERTICAL_RAIL_FORTESTING,
    LEFTDOWNUPRIGHT_RAIL_FORTESTING,
    LEFTUPRIGHTDOWN_RAIL_FORTESTING,
    HORIZONTAL_RAIL_END_FORTESTING,
    VERTICAL_RAIL_END_FORTESTING,
    LEFTDOWNUPRIGHT_RAIL_END_FORTESTING,
    LEFTUPRIGHTDOWN_RAIL_END_FORTESTING,
    RAIL_ORIENTATION_COUNT
};

enum RAIL_TYPE {
    ELECTRIC,
    STEAM,
    MONO,
    ELECTRIC_FORTESATIN,
    STEAM_FORTESATIN,
    MONO_FORTE,
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

// a helper class for checking the base without using template params
class TTEInanimateTypeBase {
    virtual const QPixmap& getImage() const = 0;
};

template <typename T1, typename T2>
class TTEInanimateType : public TTEInanimateTypeBase
{
public:
    TTEInanimateType(T1 type, T2 orientation, const QPixmap &image);

    using FirstType = T1;
    using SecondType = T2;

    T1 getType() const { return type; }
    T2 getOrientation() const { return orientation; }
    const QPixmap& getImage() const { return image; }

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
