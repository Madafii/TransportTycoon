#ifndef TTEINANIMATEOBJECT_H
#define TTEINANIMATEOBJECT_H

#include <QPoint>

class QPixmap;

class TTEInanimateObject
{
public:
    TTEInanimateObject();

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

#endif // TTEINANIMATEOBJECT_H
