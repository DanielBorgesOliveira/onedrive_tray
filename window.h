#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtCore/QtCore>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QDialog>

#include "window_1.h"

QT_BEGIN_NAMESPACE
class QAction;
class QCheckBox;class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QSpinBox;
class QTextEdit;
QT_END_NAMESPACE

//! [0]
class Window : public QDialog
{
    Q_OBJECT

  public:
    Window(QString onedrive_path, QString onedrive_arguments);
    QString *arguments;
    QString *path;

  protected:
    void closeEvent(QCloseEvent *event) override;

  private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void showMessage(QString &text);
    void readStdOutput();
    void readStdError();
    void OpenConfigurationWindow();

  private:
    void createIconGroupBox();
    void createMessageGroupBox();
    void createActions();
    void createTrayIcon();
    void execute(QString onedrive_path, QString onedrive_arguments);
    void openFolder();
    void restart();
    void resync();
    void terminate();
    void createConfigurationGroupBox();

    bool auto_hide;

    QGroupBox *iconGroupBox;
    QLabel *iconLabel;
    QComboBox *iconComboBox;
    QCheckBox *showIconCheckBox;
    QProcess *process;

    QGroupBox *messageGroupBox;
    QLabel *typeLabel;
    QLabel *durationLabel;
    QLabel *durationWarningLabel;
    QLabel *titleLabel;
    QPlainTextEdit *terminal;
    QLabel *bodyLabel;
    QComboBox *typeComboBox;
    QSpinBox *durationSpinBox;
    QLineEdit *titleEdit;
    QTextEdit *bodyEdit;
    QPushButton *showMessageButton;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QAction *consoleAction;
    QAction *configurationAction;
    QAction *openfolderAction;
    QAction *restartAction;
    QAction *resyncAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    Window_1 *ConfigurationWindow;
};
//! [0]

#endif // QT_NO_SYSTEMTRAYICON

#endif
