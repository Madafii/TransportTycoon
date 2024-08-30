#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPushButton>

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

public slots:
    void on_windowClosed(QWidget* closedWidget);

private:
    Ui::MainWindow *ui;
    TTETileLoader *tileLoader;
    TTETileMap *tileMap;

    typedef std::pair<QPushButton*, std::unique_ptr<QWidget>> buttonWindowPair;
    std::vector<buttonWindowPair> openWindowsList;

    void initMainView();

    template <typename T>
    inline bool isOpenWindow() {
        for (const auto &openWidget : openWindowsList) {
            if (qobject_cast<T*>(openWidget.second.get()) != nullptr) {
                return true;
            }
        }
        return false;
    }

    bool buildRail = false;
};



// template <typename T>
// inline bool isOpenWindow(QList<QWidget*> &list) {
//     foreach (QWidget *openWidget, list) {
//         if (qobject_cast<T*>(openWidget) != nullptr) {
//             return true;
//         }
//     }
//     return false;
// }

#endif // MAINWINDOW_H
