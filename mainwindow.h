#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <type_traits>

class TTETileLoader;
class TTERailLoader;
class TTERailType;
class TTETileMap;
class TTEBuilderMenuBase;
class TTEInanimateTypeBase;

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
    void on_pushButtonStreets_clicked();

public slots:
    void on_windowClosed(QWidget* closedWidget);
    void set_selectedBuildingType(const TTERailType *railType);

private:
    Ui::MainWindow *ui;
    TTETileLoader *tileLoader;
    TTERailLoader *railLoader;
    TTETileMap *tileMap;
    const TTERailType *selectBuildType = nullptr;

    typedef std::pair<QPushButton*, std::unique_ptr<QWidget>> buttonWindowPair;
    std::vector<buttonWindowPair> openWindowsList;

    void initMainView();

    template <typename T>
    inline bool isOpenWindow();
    template <typename T>
    inline T* getOpenWindow();
    template <typename T>
    void createBuildWindow(QPushButton *button);

    bool buildRail = false;
};


// -------------------template implementations------------------------

///
/// \brief MainWindow::isOpenWindow Check if the T type is already opened
/// \return if the window is open
///
template <typename T>
inline bool MainWindow::isOpenWindow()
{
    for (const auto &openWidget : openWindowsList) {
        if (qobject_cast<T*>(openWidget.second.get()) != nullptr) {
            return true;
        }
    }
    return false;
}

template <typename T>
inline T* MainWindow::getOpenWindow()
{
    for (const auto &openWidget : openWindowsList) {
        if (auto openWindow = qobject_cast<T*>(openWidget.second.get())) {
            return openWindow;
        }
    }
    return nullptr;
}

///
/// \brief MainWindow::createBuildWindow Creates a build menu if it is not already open.
/// \param button The button associated with the object creation.
///
template <typename T>
void MainWindow::createBuildWindow(QPushButton *button)
{
    static_assert(std::is_base_of<TTEBuilderMenuBase, T>::value, "T must be derived from TTEBuilderMenuBase");

    if (isOpenWindow<T>()) {
        qDebug() << "can not open windown because it is already open";
        return;
    }

    std::unique_ptr<QWidget> builderMenu = std::make_unique<T>(this);
    builderMenu->show();

    const QRect buttonRect = button->geometry();
    const QPoint buttonGlobalPos = button->mapToGlobal(QPoint(0, 0));

    const int bx = buttonGlobalPos.x();
    const int by = buttonGlobalPos.y() + buttonRect.height();
    builderMenu->move(bx, by);

    // setup connection for closing the window
    auto builderMenuCast = static_cast<T*>(builderMenu.get());
    connect(builderMenuCast, &T::closeWindow, this, &MainWindow::on_windowClosed);

    // move the menu to a opened window list
    openWindowsList.push_back(buttonWindowPair(button, std::move(builderMenu)));
    button->setEnabled(false);
}

#endif // MAINWINDOW_H
