#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("onedrive-systray");

    QCommandLineParser parser;
    parser.setApplicationDescription("Run and control OneDrive from the system tray");
    parser.addHelpOption();
    QCommandLineOption onedrivePathOption(QStringList() << "p" << "onedrive-path",
		    "Path to the OneDrive program", "path");
    parser.addOption(onedrivePathOption);
    QCommandLineOption onedriveArgsOption(QStringList() << "a" << "onedrive-args",
		    "Arguments passed to OneDrive", "args");
    parser.addOption(onedriveArgsOption);

    parser.process(app);

    QString onedrivePath = parser.value(onedrivePathOption);
    QString onedriveArgs = parser.value(onedriveArgsOption);


    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"), QObject::tr("I couldn't detect any system tray on this system."));
        return 1;
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Window window(onedrivePath, onedriveArgs);
    //window.show();
    return app.exec();
}

#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
