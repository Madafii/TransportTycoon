#include "tteobject.h"

TTEObject::TTEObject() {}

bool TTEObject::hasImage()
{
    return (pixImage != nullptr) ? true : false;
}

void TTEObject::setVisible(bool objVisible)
{
    visible = objVisible;
}
