TEMPLATE = app
TARGET = systray
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += window.h
SOURCES += main.cpp window.cpp
RESOURCES += systray.qrc

QT += widgets
