#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class TTETileLoader;
class TTETileMap;

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

    void on_pushButtonRails_clicked();

private:
    Ui::MainWindow *ui;
    TTETileLoader *tileLoader;
    TTETileMap *tileMap;

    void initMainView();

    // TODO:
    bool buildRail = false;
};
#endif // MAINWINDOW_H
