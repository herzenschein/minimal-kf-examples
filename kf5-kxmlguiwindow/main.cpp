#include <QtWidgets/QApplication>
#include "window.hpp"

int main(int argCount, char* argVector[])
{
    QApplication app(argCount, argVector);

    Window mainWindow;
    mainWindow.show();

    app.exec();
}
