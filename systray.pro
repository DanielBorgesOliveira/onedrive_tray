TEMPLATE = app
TARGET = onedrive_tray
DEPENDPATH += .
INCLUDEPATH += .

# Install info
target.path += /usr/local/bin/
unitfile.path += /usr/lib/systemd/user/
unitfile.files = onedrive_tray.service
INSTALLS += target
INSTALLS += unitfile

# Input
HEADERS += window.h window_1.h
SOURCES += main.cpp window.cpp window_1.cpp
RESOURCES += systray.qrc

QT += widgets
