#include "ttemainviewmap.h"

#include <QMouseEvent>
#include <QScrollBar>

#include "tterailtype.h"
#include "tterail.h"
#include "ttebuildhelper.h"

TTEMainViewMap::TTEMainViewMap(QGraphicsScene *scene, int sizeX, int sizeY, TTETileLoader *tileLoader, QWidget *parent) :
    QGraphicsView(scene, parent),
    tileLoader(tileLoader),
    mapScene(scene),
    sizeX(sizeX),
    sizeY(sizeY)
{
    QElapsedTimer timer;
    timer.start();
    // installEventFilter(this);

    // tileSize = tileLoader->getTypeAt(TILE_TYPE::GRASS, TILE_ORIENTATION::UP).getImage().height();

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            const TTETileType &tileType = tileLoader->getTypeAt(TILE_TYPE::GRASS, TILE_ORIENTATION::UP);
            const int &size = tileType.getImage().height();
            TTETile *tile = new TTETile(tileType);
            tile->setPos(x * size, y * size);
            tile->setZValue(0);
            tile->setFlag(QGraphicsItem::ItemIsSelectable);
            mapScene->addItem(tile);
            //tile->setAcceptHoverEvents(true);
            tileList.append(tile);
        }
    }
    // initScene();

    accumulatedDelta = QPointF(0,0);

    // setup all the view settings
    setMouseTracking(true);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // setting up a coursor Item
    cursorItem = new QGraphicsPixmapItem(QPixmap(50, 50));
    cursorItem->setZValue(99);
    cursorItem->setVisible(false);
    mapScene->addItem(cursorItem);

    qInfo() << "Initializing the mainView took: " << timer.elapsed() << "milliseconds";
}

void TTEMainViewMap::initScene()
{
    // for (TTETile *tile : tileList) {
    //     tile->setPos(tile->rect.x(), tile->rect.y());
    //     tile->setZValue(0);
    //     tile->setFlag(QGraphicsItem::ItemIsSelectable);
    //     mapScene->addItem(tile);
    // }
}

// bool TTEMainViewMap::eventFilter(QObject *obj, QEvent *event)
// {
//
// }

void TTEMainViewMap::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()) {
    case Qt::LeftButton: {
        // QGraphicsItem *clickedItem = mapScene->itemAt(mapToScene(event->pos()), transform());
        // TODO: maybe add dynamic_cast for non movable objects

        // get the head tile
        TTETile *tile = getTileAtScen(mapToScene(event->pos()));
        TTEInanimateObjectBase *headObj = tile;
        while (headObj->next.get() != nullptr) {
            headObj = headObj->next.get();
        }

        // item can be placed and is of rail type
        if (const TTERailType *railType = dynamic_cast<const TTERailType*>(selectedType)) {
            const TTERailType &railTypeRef = *railType;

            if (!TTEBuildHelper::buildHereAllowed(*headObj, railTypeRef)) {
                qDebug() << "can't build here";
                return;
            }

            std::unique_ptr<TTERail> rail = std::make_unique<TTERail>(railTypeRef);
            rail->setPos(tile->pos());
            rail->setZValue(2);
            mapScene->addItem(rail.get());
            headObj->next = std::move(rail);
        }
        event->accept();
        break;
    }
    case Qt::RightButton:
        // Start panning
        lastPanPoint = event->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        break;
    default:
        QGraphicsView::mousePressEvent(event);
        break;
    }
}

void TTEMainViewMap::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsItem *hoveredItem = mapScene->itemAt(this->mapToScene(event->pos()), this->transform());

    switch (event->buttons()) {
    case Qt::RightButton: {
        // Calculate distance moved and accumulate
        const QPointF currentDelta = mapToScene(event->pos()) - mapToScene(lastPanPoint);
        accumulatedDelta += currentDelta * transform().m11();

        const int moveX = static_cast<int>(accumulatedDelta.x());
        const int moveY = static_cast<int>(accumulatedDelta.y());

        if (std::abs(moveX) > 0 || std::abs(moveY) > 0) {
            QScrollBar* hScrollBar = horizontalScrollBar();
            QScrollBar* vScrollBar = verticalScrollBar();

            hScrollBar->setValue(hScrollBar->value() - moveX);
            vScrollBar->setValue(vScrollBar->value() - moveY);

            // Subtract the moved distance from accumulatedDelta
            accumulatedDelta -= QPointF(moveX, moveY);
        }
        lastPanPoint = event->pos();
        event->accept();
        break;
    }
    default:
        QGraphicsView::mouseMoveEvent(event);
        break;
    }

    // do this no matter if a button is pressed
    if (lastHoveredItem != hoveredItem) {
        if (cursorItem == nullptr || hoveredItem == nullptr) {
            return;
        }
        cursorItem->setPos(hoveredItem->pos());
        if (lastHoveredItem) {
            // when moving the view it could happen that the coursor is getting drawn on multiple tiles, so update the whole view
            // TODO: make it more efficient
            viewport()->update();
        }
        lastHoveredItem = hoveredItem;
    }
}

void TTEMainViewMap::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::RightButton: {
        setCursor(Qt::ArrowCursor);
        event->accept();
        break;
    }
    default:
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void TTEMainViewMap::wheelEvent(QWheelEvent *event)
{
    // Define min and max zoom levels
    const double minScale = 0.1;
    const double maxScale = 3.0;

    // Calculate the new scale factor
    double factor = transform().m11();  // m11() is the horizontal scaling factor, m22() would be vertical
    if (event->angleDelta().y() > 0) {
        factor *= scaleFactor;
    } else {
        factor /= scaleFactor;
    }

    // Apply constraints to the scale factor
    if (factor < minScale || factor > maxScale) {
        return;  // Do not scale if outside limits
    }

    // Apply the scaling
    if (event->angleDelta().y() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zoom out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void TTEMainViewMap::setCursorPreviewVisible(bool visible)
{
    cursorItem->setVisible(visible);
}

void TTEMainViewMap::setRailBuildItem(const TTEInanimateTypeBase &type)
{
    selectedType = &type;

    QPixmap image;
    if (const TTERailType *railType = dynamic_cast<const TTERailType*>(&type)) {
        image = railType->getImage();
    }
    if (image.isNull()) {
        qWarning() << "tried to set image to previewCursor";
        return;
    }
    cursorItem->setPixmap(image);
    cursorItem->setVisible(true);
}

bool TTEMainViewMap::isCursorPreviewVisible()
{
    return cursorItem->isVisible();
}

///
/// \brief TTEMainViewMap::getTileAt gets the tile maped with each x and y combination to a new element.
/// \param x
/// \param y
/// \return
///
TTETile* TTEMainViewMap::getTileAt(int x, int y)
{
    return tileList.at(y + x * sizeX);
}

TTETile* TTEMainViewMap::getTileAtScen(const QPointF &pos) {
    return getTileAt(static_cast<int>(pos.x()/tileSize), static_cast<int>(pos.y()/tileSize));
}
