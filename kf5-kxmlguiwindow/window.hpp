#pragma once

#include <QAction>

#include <KXmlGuiWindow>
#include <KTextEdit>

class Window : public KXmlGuiWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget* parent = nullptr);

    KTextEdit* editor;
    QAction* newAction;
    QAction* openAction;
    QAction* toggleMenuBarAction;
    QAction* quitAction;

public slots:
    void setupActions();
    void onNew();
    void onOpen();
};
