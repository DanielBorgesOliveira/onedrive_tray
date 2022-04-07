#include <QApplication>
#include <QDebug>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include <libgen.h>
#include <window.h>
#include <iconinfo.h>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);

    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);
    app.setOrganizationName("onedrive_tray");
    app.setApplicationName("onedrive_tray");
    app.setApplicationDisplayName("System tray for OneDrive");
    app.setApplicationVersion("2.0");
    app.setWindowIcon(QIcon(IconInfo::onedriveIconPathName()));

    // Define the command line parameters
    QCommandLineParser parser;
    parser.setApplicationDescription("Run and control OneDrive from the system tray");
    parser.addHelpOption();
    QCommandLineOption onedrivePathOption(QStringList() << "p" << "onedrive-path", "Path to the OneDrive program", "path");
    parser.addOption(onedrivePathOption);
    QCommandLineOption onedriveArgsOption(QStringList() << "a" << "onedrive-args", "Arguments passed to OneDrive", "args");
    parser.addOption(onedriveArgsOption);
    QCommandLineOption silentFailOption(QStringList() << "s" << "silent-fail", "No error message displayed when no system tray is detected");
    parser.addOption(silentFailOption);
    parser.process(app);

    QString onedrivePath = parser.value(onedrivePathOption);
    QString onedriveArgs = parser.value(onedriveArgsOption);
    bool silent = parser.isSet(silentFailOption);

    // Translator of predefined Qt objects (QColorDialog for example)
    QTranslator qtTranslator;
    if (qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(&qtTranslator);

    // Translator of the application
    QTranslator appTranslator;
    // Loads path + filename + prefix + ui language name + suffix (".qm" if the suffix is not specified)
    if (appTranslator.load(QLocale(), app.applicationName(), "_", app.applicationDirPath()))
        app.installTranslator(&appTranslator);
    else
        qDebug().noquote() << "Translation not found for" << QLocale().languageToString(QLocale().language()) << "language" << QLocale().uiLanguages() << ".";

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        if (!silent) {
            QMessageBox::critical(0, QObject::tr("OneDrive"), QObject::tr("I couldn't detect any system tray on this system."));
        }
        return 1;
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Window window(onedrivePath, onedriveArgs);
    return app.exec();
}

#else

#include <QLabel>

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
