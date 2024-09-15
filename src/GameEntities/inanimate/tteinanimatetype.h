#ifndef TTEINANIMATETYPE_H
#define TTEINANIMATETYPE_H

#include <QPixmap>

// a helper class for checking the base without using template params
class TTEInanimateTypeBase {
public:
    virtual const QPixmap& getImage() const = 0;
    // virtual bool canIBuildThis(TTEInanimateTypeBase *type) = 0;
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
    const QPixmap& getImage() const override { return image; }

    // virtual bool canIBuildThis(TTEInanimateTypeBase *type) override = 0;

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
