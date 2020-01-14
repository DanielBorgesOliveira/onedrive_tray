TEMPLATE = app
TARGET = systray
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += window.h window_1.h
SOURCES += main.cpp window.cpp window_1.cpp
RESOURCES += systray.qrc

QT += widgets
