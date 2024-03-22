#include "mainwindow.h"
#include "startingwindow.h"

#include <QApplication>
#include <QFileInfo>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qputenv("TTEUSER", (QFileInfo(__FILE__).absoluteDir().path() + "/user/").toUtf8());

    MainWindow* mainWindow = nullptr;

    // Show the Starting Window for Settings
    // StartingWindow startingWindow;
    // if (startingWindow.exec() != QDialog::Accepted) {
    //     return 0;
    // }
    // else {
    //     mainWindow = new MainWindow();
    //     mainWindow->setWindowTitle("My Application");
    //     mainWindow->showMaximized();
    // }

    mainWindow = new MainWindow();
    mainWindow->setWindowTitle("My Application");
    mainWindow->show();
    //mainWindow->showMaximized();

    int result = app.exec();

    delete mainWindow;

    return result;
}
