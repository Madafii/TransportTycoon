#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "tileloader.h"
#include "tilemap.h"
#include "rail.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonAddRail_clicked();

private:
    Ui::MainWindow *ui;
    TileLoader *tileLoader;
    TileMap *tileMap;

    // TODO:
    bool buildRail = false;
};
#endif // MAINWINDOW_H
