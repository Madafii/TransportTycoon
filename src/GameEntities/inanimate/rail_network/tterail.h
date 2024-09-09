#ifndef TTERAIL_H
#define TTERAIL_H

#include "tteinanimateobject.h"
#include "tterailtype.h"

class TTERail : public TTEInanimateObject<TTERailType>
{
public:
    TTERail(const TTERailType &railType);
};

#endif // TTERAIL_H
