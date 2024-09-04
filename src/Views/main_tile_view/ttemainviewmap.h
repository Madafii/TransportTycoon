#ifndef TTEMAINVIEWMAPH_H
#define TTEMAINVIEWMAPH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "ttetile.h"
#include "ttetileloader.h"

class TTETileType;
class TTERailType;

class TTEMainViewMap : public QGraphicsView
{
public:
    TTEMainViewMap(QGraphicsScene *scene, int size_x, int size_y, TTETileLoader *tileLoader, QWidget *parent = nullptr);

    void initScene();

    void setCursorPreviewVisible(bool visible);
    bool isCursorPreviewVisible();
    
    QList<TTETile*>& getTileList() { return tileList; }
    TTETile* getTileAt(int x, int y);

public slots:
    void setRailBuildItem(const TTEInanimateTypeBase &type);

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

#endif // TTEMAINVIEWMAPH_H
