# qt_kiosk
An application written in Qt based on the Qt WebEngine module.
The application runs in full-screen mode on a touch-enabled device and features a minimal graphical interface: a "back" button icon and a "home" button that navigates back to the main page. It can automatically return to the home page upon detecting inactivity. Running the application requires Qt to be installed on the system.

<p align="center">
 <img src="kiosk.png">
</p>

## Compilation
Compiling may require the installation of Qt WebEngine. For example in Debian:

````bash
apt install qtwebengine5-dev
````

## Config file
In file /etc/kiosk/config.ini

````bash
[page]
home = http://google.com
[config]
ticks = 1 
navigator = 1

````
 
- home - main page
- tick - 1 tick mean after 10s auto load home page, tick 0 turn off this function 
- navigator - 1 or 0, this function is not used now
