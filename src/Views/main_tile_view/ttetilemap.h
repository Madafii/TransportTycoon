#ifndef TTETILEMAP_H
#define TTETILEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "ttetile.h"
#include "ttetileloader.h"

class TTETileType;
class TTEInanimateTypeBase;

class TTETileMap : public QGraphicsView
{
public:
    TTETileMap(QGraphicsScene *scene, int size_x, int size_y, TTETileLoader *tileLoader, QWidget *parent = nullptr);

    void initScene();

    void setCursorPreviewVisible(bool visible);
    void setCursorPreviewItem(const TTEInanimateTypeBase *type);
    bool isCursorPreviewVisible();
    
    QList<TTETile*>& getTileList() { return tileList; }
    TTETile* getTileAt(int x, int y);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    //void buildPreview();

private:
    TTETileLoader *tileLoader;
    QGraphicsScene *mapScene;

    TTEInanimateTypeBase *selectedType;
    QGraphicsPixmapItem *cursorItem;

    int sizeX, sizeY;
    int tileSize;
    QList<TTETile*> tileList;
};

#endif // TTETILEMAP_H
