#ifndef TILEMAP_H
#define TILEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "ttetile.h"
#include "ttetileloader.h"

class TTETileType;

class TTETileMap : public QGraphicsView
{
public:
    TTETileMap(QGraphicsScene *scene, int size_x, int size_y, TTETileLoader *tileLoader, QWidget *parent = nullptr);

    void initScene();

    void setCursorVisible(bool visible);

    bool isCursorVisible();
    
    QList<TTETile*>& getTileList() { return tileList; }
    TTETile* getTileAt(int x, int y);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    //void buildPreview();

private:
    TTETileLoader *tileLoader;
    QGraphicsScene *mapScene;

    QGraphicsPixmapItem *cursorItem;

    int sizeX, sizeY;
    int tileSize;
    QList<TTETile*> tileList;
};

#endif // TILEMAP_H
