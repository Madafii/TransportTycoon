#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <type_traits>

class TTETileLoader;
class TTETileMap;
class TTEBuilderMenuBase;

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

private:
    Ui::MainWindow *ui;
    TTETileLoader *tileLoader;
    TTETileMap *tileMap;

    typedef std::pair<QPushButton*, std::unique_ptr<QWidget>> buttonWindowPair;
    std::vector<buttonWindowPair> openWindowsList;

    void initMainView();

    template <typename T>
    inline bool isOpenWindow();
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

    std::unique_ptr<QWidget> railBuilderMenu = std::make_unique<T>(this);
    connect(dynamic_cast<T*>(railBuilderMenu.get()), &T::closeWindow, this, &MainWindow::on_windowClosed);
    railBuilderMenu->show();
    openWindowsList.push_back(buttonWindowPair(button, std::move(railBuilderMenu)));

    button->setEnabled(false);
}

#endif // MAINWINDOW_H
