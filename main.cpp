#include "mainwindow.h"
#include "startingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qputenv("TTEHOME", QCoreApplication::applicationDirPath().toUtf8());

    // Show the Starting Window for Settings
    StartingWindow startingWindow;
    MainWindow* mainWindow = nullptr;
    if (startingWindow.exec() != QDialog::Accepted) {
        return 0;
    }
    else {
        mainWindow = new MainWindow();
        mainWindow->setWindowTitle("My Application");
        mainWindow->showMaximized();
    }

    int result = app.exec();

    delete mainWindow;

    return result;
}