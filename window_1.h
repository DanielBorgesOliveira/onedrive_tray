#ifndef Window_1_H
#define Window_1_H

#include <QSystemTrayIcon>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtCore/QtCore>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QDialog>

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
class Window_1 : public QDialog
{
    Q_OBJECT

  public:
    Window_1();

  protected:
    void closeEvent(QCloseEvent *event) override;

  private slots:

  private:
    void createIconGroupBox();
    void createMessageGroupBox();
    void createActions();
    void createTrayIcon();
    void execute();
    void restart();
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
    QLabel *syncdirLabel;
    QPlainTextEdit *terminal;
    QLabel *bodyLabel;
    QComboBox *typeComboBox;
    QSpinBox *durationSpinBox;
    QLineEdit *titleEdit;
    QLineEdit *syncdirEdit;
    QTextEdit *bodyEdit;
    QPushButton *showMessageButton;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QAction *consoleAction;
    QAction *configurationAction;
    QAction *restartAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
};
//! [0]

#endif // QT_NO_SYSTEMTRAYICON

#endif
