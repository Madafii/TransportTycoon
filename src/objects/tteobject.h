#ifndef TTEOBJECT_H
#define TTEOBJECT_H

// #include <QPixmap>
#include <QPoint>
class QPixmap;

class TTEObject
{
public:
    TTEObject();

    bool hasImage();

    QPoint &getPos() { return pos; }
    QPixmap *getImage() { return pixImage; }

private:
    QPoint pos;
    QPixmap *pixImage = nullptr;
};

#endif // TTEOBJECT_H
