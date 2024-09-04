#ifndef TTERAILLOADER_H
#define TTERAILLOADER_H

#include "tterailtype.h"
#include "tteimagesetloader.h"

class QString;

class TTERailLoader : public TTEImageSetLoader<TTERailType>
{
public:
    TTERailLoader(const QString filePath, const quint16 typeSize = RAIL_TYPE_COUNT, const quint16 orientationSize = RAIL_ORIENTATION_COUNT);

    // void initRailSet(QString filePath);

    // const QList<RailType>& getRailTypes();
    // const RailType* getRailTypeAt(RAIL_TYPE railType);
    // const quint16& getRailWidth() const { return railWidth; }
    // const quint16& getRailHeight() const { return railHeight; }

private:
    // quint16 railWidth, railHeight;
    // QList<RailType> tileTypes;
};

#endif // TTERAILLOADER_H
