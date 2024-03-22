#ifndef TILEMAP_H
#define TILEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "tile.h"
#include "tileloader.h"

class TileType;

class TileMap : public QGraphicsView
{
public:
    TileMap(QGraphicsScene *scene, int size_x, int size_y, TileLoader *tileLoader, QWidget *parent = nullptr);

    void loadMapIntoScene(QGraphicsScene *gS);

    QList<Tile*>& getTileList() { return tileList; }

    void setCursorVisible(bool visible);

    bool isCursorVisible();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    //void buildPreview();

private:
    TileLoader *tileLoader;
    QGraphicsScene *mapScene;
    QGraphicsPixmapItem *cursorItem;
    int size_x, size_y;
    QList<Tile*> tileList;
};

#endif // TILEMAP_H
