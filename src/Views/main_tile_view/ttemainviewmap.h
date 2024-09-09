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
    // bool eventFilter(QObject *obj, QEvent *event) override;
    // bool event(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QGraphicsScene *mapScene;
    TTETileLoader *tileLoader;

    QPoint lastPanPoint;
    QGraphicsItem *lastHoveredItem = nullptr;
    const TTEInanimateTypeBase *selectedType = nullptr;
    QGraphicsPixmapItem *cursorItem;

    static constexpr double scaleFactor = 1.15;
    QPointF accumulatedDelta;

    int sizeX, sizeY;
    int tileSize;
    QList<TTETile*> tileList;
};

#endif // TTEMAINVIEWMAPH_H
