#ifndef TTEINANIMATEOBJECT_H
#define TTEINANIMATEOBJECT_H

#include <QGraphicsItem>
#include <QPainter>

#include "tteinanimatetype.h"

class QPixmap;

template<typename C>
class TTEInanimateObject : public QGraphicsItem
{
    // Ensure that C is derived from TTEInanimateType<T1, T2>
    static_assert(std::is_base_of<TTEInanimateType<typename C::FirstType, typename C::SecondType>, C>::value, "C must inherit from TTEInanimateType<T1, T2>");
public:
    TTEInanimateObject(const C &tileType, QRectF rect);

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    const C &type;
    QRectF rect;

protected:
    //void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void itemMouseEntered(TTEInanimateObject *typeElement);
};

template<typename C>
TTEInanimateObject<C>::TTEInanimateObject(const C &tileType, QRectF rect)
    : type(tileType), rect(rect)
{

}

template<typename C>
QRectF TTEInanimateObject<C>::boundingRect() const
{
    return QRect(0, 0, 50, 50);
}

template<typename C>
void TTEInanimateObject<C>::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPixmap &image = type.getImage();
    const QRectF &imageRect = image.rect();
    painter->drawPixmap(imageRect, image, imageRect);
}




#endif // TTEINANIMATEOBJECT_H
