#include "window.h"
#include "window_1.h"

#ifndef QT_NO_SYSTEMTRAYICON

#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFrame>

Window::Window()
{
    ConfigurationWindow = new Window_1;

    // Used to show the window in odd clicks and hide in even.
    auto_hide = true;

    createMessageGroupBox();
    createActions();
    createTrayIcon();

    connect(trayIcon, &QSystemTrayIcon::activated, this, &Window::iconActivated);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(messageGroupBox);
    setLayout(mainLayout);

    execute();

    setWindowTitle(tr("Systray"));
    resize(400, 300);
}

// ********** Block to execute external program ********** //
void Window::execute()
{
    process = new QProcess();
    //QStringList arguments{"--monitor", "--verbose", "--confdir", "/home/daniel/.config/onedrive"};
    QStringList arguments{"--monitor", "--local-first", "--skip-symlinks", "--confdir", "/home/daniel/.config/onedrive"};

    QString program("/usr/local/bin/onedrive");

    process->setProgram(program);
    process->setArguments(arguments);

    process->start();

    QObject::connect(process, SIGNAL(readyReadStandardOutput()),this, SLOT(readStdOutput()) );
    QObject::connect(process, SIGNAL(readyReadStandardError()),this, SLOT(readStdError()) );
}

void Window::restart()
{
    terminal->appendPlainText("Reiniciando o OneDrive.");

    process->terminate(); // Kill process.
    process->waitForFinished(); // Wait for process finish
    process->start(); // Start the process.

    terminal->appendPlainText("OneDrive reiniciado com sucesso.");
}

void Window::readStdOutput()
{
    /*
     * Função slot usada para ler as informações da saída padrão
     *
    */

    QByteArray strdata = process->readAllStandardOutput();

    QString text(strdata);

    terminal->appendPlainText(text);
}

void Window::readStdError()
{
    /*
     * Função slot usada para ler as informações da saída de erro.
     *
    */

    QByteArray strdata = process->readAllStandardError();

    QString text(strdata);

    terminal->appendPlainText(text);
}
// ********** ***** ** ******* ******** ******* ********** //
//
void Window::closeEvent(QCloseEvent *event)
{
  #ifdef Q_OS_OSX
  if (!event->spontaneous() || !isVisible()) {
      return;
  },
  #endif
  if (trayIcon->isVisible()) {
      QMessageBox::information(this, tr("Systray"),
                               tr("The program will keep running in the "
                                  "system tray. To terminate the program, "
                                  "choose <b>Quit</b> in the context menu "
                                  "of the system tray entry."));
      hide();
      event->ignore();
  }
}

void Window::terminate()
{
    /*
     * Function responsible to terminate the app and the childrens.
     */
    process->terminate(); // Kill process.
    qApp->quit(); // Kill application.
}

void Window::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
            // Put here what should call when click with left button
            if (auto_hide)
            {
                this->showNormal(); // Show the information window.
                auto_hide = false;
            }
            else
            {
                this->hide(); // Show the information window.
                auto_hide = true;
            }
            break;
        case QSystemTrayIcon::MiddleClick: // Put here what should call when click with mid button
            // Get process identifier (PID).
            qint64 pid = process->processId();

            // Create the string to store the informations.
            QString text;

            // If pid is greater than 0 the process is running
            // and when show a info about this.
            if (pid > 0)
            {
                text.append("OneDrive is running with the PID ");
                text.append(QString::number(pid));
                text.append(".\n");
            }
            // If not the process is stopped and when notify the user.
            else
            {
                text.append("OneDrive is not running by some reason. Please restart the program.");
            }

            showMessage(text); // Show the Message baloon.
            break;
    }
}

void Window::showMessage(QString &text)
{
  /*
   * Function used to print messagem in the notification baloon.
   */
  QSystemTrayIcon::MessageIcon msgIcon = QSystemTrayIcon::MessageIcon(0);
  trayIcon->showMessage(titleEdit->text(), text, msgIcon, 5000);
}

void Window::createMessageGroupBox()
{
  /*
   * Create the LOG message message box.
  */
  // Title of notification ballon and tray menu.
  titleEdit = new QLineEdit(tr("OneDrive Tray icon"));

  // ********** Log Console Output Area ********** //
  terminal = new QPlainTextEdit;
  terminal->setReadOnly(true);

  QGridLayout *messageLayout = new QGridLayout;
  messageLayout->addWidget(terminal, 2, 1, 1, 4);
  messageLayout->setColumnStretch(3, 1);
  messageLayout->setRowStretch(4, 1);

  messageGroupBox = new QGroupBox(tr("Log Console"));
  messageGroupBox->setLayout(messageLayout);

  // ********** Create the baloon warning in the tray ********** //
  showIconCheckBox = new QCheckBox(tr("Show icon"));
  showIconCheckBox->setChecked(true);
}

void Window::createActions()
{
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, this, &Window::terminate);

    consoleAction = new QAction(tr("&Log Console"), this);
    connect(consoleAction, &QAction::triggered, this, &QWidget::showNormal);

    configurationAction = new QAction(tr("&Configuration"), this);
    connect(configurationAction, SIGNAL(triggered()), this, SLOT(OpenConfigurationWindow()));

    restartAction = new QAction(tr("&restart"), this);
    connect(restartAction, &QAction::triggered, this, &Window::restart);
}

void Window::OpenConfigurationWindow()
{
  ConfigurationWindow->show();
}

void Window::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(consoleAction);
    trayIconMenu->addAction(configurationAction);
    trayIconMenu->addAction(restartAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(QIcon(":/images/onedrive.png"), this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

#endif
