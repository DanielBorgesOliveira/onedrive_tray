# Introduction

This is a simple program to create a system tray icon and display program status for onedrive client developed by abraunegg.

Click with the left mouse button and the program shows the synchronization progress.
Click with the right mouse button and a menu with the available options is shown.
Click with the mid mouse button and the program shows the PID of the onedrive client.

The program was written using lib QT 5.13.0.

To use the program you must first compile and install the onedrive client available at https://github.com/abraunegg/onedrive.

# How to compile

The steps bellow should be suffice to compile the program:

```
git clone https://github.com/DanielBorgesOliveira/onedrive_tray.git

cd onedrive_tray

mkdir build

cd build

qmake ../systray.pro

make
```

This will create systray binary.

Tested with QT 5.12.6 and 5.13.0.

# How to execute

First move the binary to your path:

```
sudo cp systray /usr/local/bin/onedrive_tray
```

The execute the program:

```
onedrive_tray --onedrive-path [path to onedrive client] --onedrive-args [onedrive client arguments].
```

If you want the program to execute every time you log in you can put it in the auto start scripts.


# Pre-compiled Binaries

If you do not have the necessary knowledge to compile a Linux program or simply you have no patience to compile another package you can download a pre-compiled binary developed by the community. Bellow, there are some packages available.

- This is an AUR package compile by [jugendhacker](https://github.com/jugendhacker) for ArchLinux. You can get it in [https://aur.archlinux.org/packages/onedrive_tray-git/](https://aur.archlinux.org/packages/onedrive_tray-git/).


