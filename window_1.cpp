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
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFrame>

#include "window_1.h"

Window_1::Window_1()
{
  createMessageGroupBox();

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(messageGroupBox);
  setLayout(mainLayout);

  setWindowTitle(tr("OneDrive Configuration"));
  resize(400, 300);
}

// ********** Block to execute external program ********** //
void Window_1::closeEvent(QCloseEvent *event)
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

void Window_1::createMessageGroupBox()
{
	messageGroupBox = new QGroupBox(tr("OneDrive Configuration"));

	/*
	typeLabel = new QLabel(tr("Type:"));
	typeComboBox = new QComboBox;
	typeComboBox->addItem(
		tr("None"),
		QSystemTrayIcon::NoIcon
	);
	typeComboBox->addItem(
		style()->standardIcon(QStyle::SP_MessageBoxInformation),
		tr("Information"),
		QSystemTrayIcon::Information
	);
	typeComboBox->addItem(style()->standardIcon(
		QStyle::SP_MessageBoxWarning),
		tr("Warning"),
		QSystemTrayIcon::Warning
	);
	typeComboBox->addItem(style()->standardIcon(
		QStyle::SP_MessageBoxCritical),
		tr("Critical"),
		QSystemTrayIcon::Critical
	);
	typeComboBox->addItem(
		QIcon(),
		tr("Custom icon"),
		QSystemTrayIcon::NoIcon
	);
	typeComboBox->setCurrentIndex(1);
	*/

	durationLabel = new QLabel(tr("Monitor Interval"));

	durationSpinBox = new QSpinBox;
	durationSpinBox->setRange(5, 3600);
	durationSpinBox->setSuffix(" s");
	durationSpinBox->setValue(40);

	titleLabel = new QLabel(tr("Files/Directories to skip:"));
	titleEdit = new QLineEdit(tr("~*|.~*|*.db|Thumbs.db|*encryptable*|~$*|*.pyc|log.*|*.swp|*.swo"));

	syncdirLabel = new QLabel(tr("Syncronization Folder:"));
	syncdirEdit = new QLineEdit(tr("~/OneDrive"));

	bodyLabel = new QLabel(tr("Additional Configuration:"));
	bodyEdit = new QTextEdit;
	bodyEdit->setPlainText(tr(""));

	showMessageButton = new QPushButton(tr("Save"));
	showMessageButton->setDefault(true);

	QGridLayout *messageLayout = new QGridLayout;

	messageLayout->addWidget(typeLabel, 0, 0);
	//messageLayout->addWidget(typeComboBox, 0, 1, 1, 2);
	messageLayout->addWidget(durationLabel, 1, 0);
	messageLayout->addWidget(durationSpinBox, 1, 1);
	messageLayout->addWidget(syncdirLabel, 2, 0);
	messageLayout->addWidget(syncdirEdit, 2, 1, 1, 4);
	messageLayout->addWidget(titleLabel, 3, 0);
	messageLayout->addWidget(titleEdit, 3, 1, 1, 4);
	messageLayout->addWidget(bodyLabel, 4, 0);
	messageLayout->addWidget(bodyEdit, 4, 1, 2, 4);
	messageLayout->addWidget(showMessageButton, 6, 4);

	messageLayout->setColumnStretch(3, 1);
	messageLayout->setRowStretch(4, 1);
	messageGroupBox->setLayout(messageLayout);
}

