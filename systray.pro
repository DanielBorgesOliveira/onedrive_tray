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
HEADERS += window.h window_1.h iconinfo.h morecolors.h
SOURCES += main.cpp window.cpp window_1.cpp iconinfo.cpp morecolors.cpp
RESOURCES += systray.qrc

QT += widgets

TRANSLATIONS += onedrive_tray_en.ts onedrive_tray_fr.ts onedrive_tray_es.ts onedrive_tray_nl.ts onedrive_tray_it.ts
