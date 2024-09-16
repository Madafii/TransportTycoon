#ifndef TTEMAINVIEWMAPH_H
#define TTEMAINVIEWMAPH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "ttetile.h"
#include "ttetileloader.h"
#include "ttebuildhelper.h"

class TTETileType;
class TTERailType;

class TTEMainViewMap : public QGraphicsView
{
public:
    TTEMainViewMap(QGraphicsScene *scene, int size_x, int size_y, TTETileLoader *tileLoader, QWidget *parent = nullptr);

    using typeVariant = TTEBuildHelper::typeVariant;

    void initScene();

    void setCursorPreviewVisible(bool visible);
    bool isCursorPreviewVisible();
    
    QList<TTETile*>& getTileList() { return tileList; }
    TTETile* getTileAt(int x, int y);
    TTETile* getTileAtScen(const QPointF &pos);

public slots:
    void setBuildItem(typeVariant type);

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
    typeVariant selectedType;
    // const TTEInanimateTypeBase *selectedType = nullptr;
    QGraphicsPixmapItem *cursorItem;

    static constexpr double scaleFactor = 1.15;
    static constexpr int tileSize = 50;

    QPointF accumulatedDelta;

    int sizeX, sizeY;
    QList<TTETile*> tileList;

    template <typename CType, typename CObj>
    void buildObj(TTEInanimateObjectBase &headObj, const QPointF &buildPos);
};

template <typename CType, typename CObj>
void TTEMainViewMap::buildObj(TTEInanimateObjectBase &headObj, const QPointF &buildPos)
{
    static_assert(std::is_base_of<TTEInanimateTypeBase, CType>::value, "CType has to be inherited from TTEInanimateTypeBase");

    const CType &typeRef = *std::get<const CType*>(selectedType);

    if (!TTEBuildHelper::buildHereAllowed(headObj, typeRef)) {
        qDebug() << "can't build here";
        return;
    }

    auto newBuildObj = std::make_unique<CObj>(typeRef);
    newBuildObj->setPos(buildPos);
    newBuildObj->setZValue(2);
    mapScene->addItem(newBuildObj.get());
    headObj.next = std::move(newBuildObj);
}

#endif // TTEMAINVIEWMAPH_H
