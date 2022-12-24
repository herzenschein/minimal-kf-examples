#include <QFileDialog>
#include <QMenuBar>
#include <QApplication>
#include <QAction>

#include <KXmlGui/KToolBar>
#include <KConfigWidgets/KStandardAction>

#include "window.hpp"

Window::Window(QWidget* parent)
{
    editor = new KTextEdit;
    this->setCentralWidget(editor);
    this->setupActions();
    setupGUI(Default);
}

void Window::setupActions()
{
    newAction = KStandardAction::openNew(this, &Window::onNew, actionCollection());
    openAction = KStandardAction::open(this, &Window::onOpen, actionCollection());
    toggleMenuBarAction = KStandardAction::showMenubar(menuBar(), &QMenuBar::setVisible, actionCollection());
    quitAction = KStandardAction::quit(qApp, &QApplication::quit, actionCollection());
}

void Window::onNew()
{
    editor->clear();
}

void Window::onOpen()
{
    const QUrl fileNameFromDialog = QFileDialog::getOpenFileUrl(this, "Open File");
    QFile fileToOpen(fileNameFromDialog.toLocalFile());
    QByteArray newFileContent;
    fileToOpen.open(QIODevice::ReadOnly);
    newFileContent = fileToOpen.readAll();
    editor->setPlainText(newFileContent.data());
}
