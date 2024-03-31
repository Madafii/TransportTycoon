#ifndef TTEOBJECT_H
#define TTEOBJECT_H

// #include <QPixmap>
#include <QPoint>
class QPixmap;

class TTEObject
{
public:
    TTEObject();

    void setVisible(bool visible);

    bool hasImage();
    bool isVisible() { return visible; }

    QPoint &getPos() { return pos; }
    QPixmap *getImage() { return pixImage; }

private:
    QPoint pos;
    QPixmap *pixImage = nullptr;
    bool visible = true;

};

#endif // TTEOBJECT_H
