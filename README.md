A simple program to create a system tray icon and display program status

Adds a system tray to the onedrive file synchronization program https://github.com/abraunegg/onedrive.
Displays program status

Click with the left mouse button and the program shows the synchronization progress.
Click with the right mouse button and a menu with the available options is shown.

The program was written using lib QT 5.13.0.

To use the program you must first compile and install the onedrive client available at https://github.com/abraunegg/onedrive.
Then you must adjust the settings in the window.cpp file on line 47.

/******************* How to compile *******************/

The steps bellow should be suffice to compile the program:

$ git clone https://github.com/DanielBorgesOliveira/onedrive_tray.git
$ cd onedrive_tray
$ mkdir build
$ cd build
$ qmake ../systray.pro
$ make

This will create systray binary.

Tested with QT 5.12.6 and 5.13.0.
