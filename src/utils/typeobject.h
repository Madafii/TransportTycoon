#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H

#include <QPixmap>

enum RAIL_TYPE {
    SINGLE = 0,
    NONES = 1001
};

enum TILE_TYPE {
    GRASS = 0,
    RAIL = 1,
    EXTRA = 2,
    NONE = 3
};

template <typename T>
class TypeObject
{
public:
    TypeObject(T type, const QPixmap &image);

    T getType() const { return type; }
    const QPixmap getImage() const { return image; }

private:
    T type;
    QPixmap image;
};

#endif // TYPEOBJECT_H
