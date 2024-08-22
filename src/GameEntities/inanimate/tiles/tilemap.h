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

    void initScene();

    void setCursorVisible(bool visible);

    bool isCursorVisible();

    QList<Tile*>& getTileList() { return tileList; }
    Tile* getTileAt(int x, int y);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    //void buildPreview();

private:
    TileLoader *tileLoader;
    QGraphicsScene *mapScene;

    QGraphicsPixmapItem *cursorItem;

    int sizeX, sizeY;
    int tileSize;
    QList<Tile*> tileList;
};

#endif // TILEMAP_H
