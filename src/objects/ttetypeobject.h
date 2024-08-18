#ifndef TTETYPEOBJECT_H
#define TTETYPEOBJECT_H

#include <QPixmap>

enum RAIL_TYPE {
    STRAIGHT = 0,
    DIAGONAL = 1,
    NONES = 1001
};

enum TILE_TYPE {
    GRASS = 0,
    RAIL = 1,
    EXTRA = 2,
    NONE = 3
};

template <typename T>
class TTETypeObject
{
public:
    TTETypeObject(T type, const QPixmap &image);

    T getType() const { return type; }
    const QPixmap getImage() const { return image; }

private:
    T type;
    QPixmap image;
};

#endif // TTETYPEOBJECT_H
