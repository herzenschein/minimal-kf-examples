cmake_minimum_required(VERSION 3.20)

project(kf5-kxmlguiwindow)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

find_package(KF5XmlGui REQUIRED)

find_package(KF5TextEditor REQUIRED)

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    window.cpp
    window.hpp
    kf5-kxmlguiwindowui.rc
)

target_precompile_headers(${CMAKE_PROJECT_NAME}
    PRIVATE
        <QtWidgets/QApplication>
        <KXmlGui/KXmlGuiWindow>
        <KXmlGui/KToolBar>
        <KXmlGui/KActionCollection>
        <KTextWidgets/KTextEdit>
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        Qt5::Widgets
        KF5::XmlGui
        KF5::TextWidgets
        KF5::ConfigWidgets
)

install(TARGETS ${CMAKE_PROJECT_NAME} ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES ${CMAKE_PROJECT_NAME}ui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/${CMAKE_PROJECT_NAME})
