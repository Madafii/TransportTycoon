#include "tteinanimateobject.h"

TTEInanimateObject::TTEInanimateObject() {}

bool TTEInanimateObject::hasImage()
{
    return (pixImage != nullptr) ? true : false;
}

void TTEInanimateObject::setVisible(bool objVisible)
{
    visible = objVisible;
}
