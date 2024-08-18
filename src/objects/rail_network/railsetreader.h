#ifndef RAILSETREADER_H
#define RAILSETREADER_H

#include "railtype.h"

class QString;

class RailSetReader
{
public:
    RailSetReader(QString filePath);

    void initRailSet(QString filePath);

    const QList<RailType>& getRailTypes();
    const RailType* getRailTypeAt(RAIL_TYPE railType);
    const quint16& getRailWidth() const { return railWidth; }
    const quint16& getRailHeight() const { return railHeight; }

private:
    quint16 railWidth, railHeight;
    QList<RailType> tileTypes;
};

#endif // RAILSETREADER_H
