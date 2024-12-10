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
sudo cp onedrive_tray /usr/local/bin/onedrive_tray
```

If exists, move to your path the translation file corresponding to your country. For example for french users :

```
sudo cp onedrive_tray_fr.qm /usr/local/bin/onedrive_tray_fr.qm
```

Then execute the program:

```
onedrive_tray --onedrive-path [path to onedrive client] --onedrive-args [onedrive client arguments].
```

If you want the program to execute every time you log in you can put it in the auto start scripts.

You can alternatively install with make:

```
sudo make install
```

This will include a systemd service that can be enabled to auto start the application:

```
systemctl enable --user onedrive_tray.service
```

## Create a translation file

- Modify the file systray.pro : on the line TRANSLATIONS, add the name of a new translation file (onedrive_tray_xx.ts where xx corresponds to your country).

- In a terminal, go to the path where is your source code files and execute the command

```
lupdate systray.pro
```

If "lupdate" responds with the error “could not exec /usr/lib/x86_64-linux-gnu/qt5/bin/lupdate: No such file or directory” execute:
```
sudo apt-get install qttools5-dev-tools
```

This command initiates the onedrive_tray_xx.ts file.

- Now execute the command

```
linguist
```

This command launches the application "linguist" to write the translations. First open your onedrive_tray_xx.ts file and write the translations. When your translations are done, save the file and release the file (menu File). The release action create the onedrive_tray_xx.qm file.

For more informations about the translation in Qt, you can visit the [Qt documentation](https://doc.qt.io/qt-5/qtlinguist-index.html).

## Configure proxy settings

- If you execute the program directly from the command line, you can **set environment variables: "HTTP_PROXY" and "HTTPS_PROXY"** to let onedrive subprocess inherit these settings because of QT features.

- If you use the systemd service, you can achieve this by editing the "/usr/lib/systemd/user/onedrive_tray.service" file and add (please properly replace "ip.address:port" with your proxy settings)

  ```
  Environment="HTTP_PROXY=http://ip.address:port"
  Environment="HTTPS_PROXY=http://ip.address:port"
  ```

  to the "[Service]" section of the service unit file.
  
- Reference: Official onedrive_abraunegg document ([Link](https://github.com/abraunegg/onedrive/blob/master/docs/USAGE.md#access-onedrive-service-through-a-proxy)).

# Pre-compiled Binaries

If you do not have the necessary knowledge to compile a Linux program or simply you have no patience to compile another package you can download a pre-compiled binary developed by the community. Bellow, there are some packages available.

- This is an AUR package compile by [jugendhacker](https://github.com/jugendhacker) for ArchLinux. You can get it in [https://aur.archlinux.org/packages/onedrive_tray-git/](https://aur.archlinux.org/packages/onedrive_tray-git/).
