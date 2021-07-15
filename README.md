# salespoint
C++/Qt based POS (point of sale application) for Linux and Embedded Linux
-------------------------------------------------------------------------
salespoint is a point of sale (POS) system designed and developed 
by Inteligy Software Enterprise (InteligyWare). It was inspired 
by Sage (Developped by Sage) and nTPV (An open source POS developped 
by Napsis Corp). salespoint is developped to provide an open source 
alternative to sage.

It was initially designed to manage restaurants, bars, cafes, and similar 
businesses, but now, it's evolving into a general purpose POS. It uses DCOP
and nkxmlrpcd for distributed comunications among POS, and uses PostgreSQL 
as its database backend. It features a fast and easy-to-use interface. 
Its high modularity and scalability makes it easy to enhance and mantain. 
It's developped with a plugin approach.

### InteligyWare provides other plugins that add more features to the POS systems like:
	
	-[ DCOPAuth ] Biometric fingerprint autentication of waiters and users.
	-[ DCOPRECEIPT ] Easy use of orders, tables, and invoice saving... no more ordering notebooks are needed
	-[ DCOPREPORTS ] Reports generated with this plugin allows to obtain information to increase benefits.
	-[ DCOPSTICK ] Manage your backups and store your reports with USB storage drives.

libraries needed to compile salespoint
--------------------------------------
	-qt5 postgres plugin
	-Qt Creator (www.qt.io)
	-libc6 (2 2.14) 
	-libodb-2.4 (2 2.4) 
	-libodb-qt-2.4 (2 2.4) 
	-libodb-pgsql-2.4 (2 2.4) 
	-libqt5gui5 (2 5.5.1) 
	-libqt5sql5-psql (2 5.3.0)
	
Installing salespoint from binaries (Quick method.)
--------------------------------------------------
salespoint both a .deb file is provided to install salespoint. 
A live CD is also provide as an ISO file to test the app without 
installing. Burn the file to a usb stick and try the app. 

Installing salespoint from sources
----------------------------------
It's very simple and quick to compile and install salespoint from source.
#### Requirements:

	.QMake and qt5 
	.odb c++ orm compiler .gcc 8.0 .the above mentioned libraries
clone this repository:

	git clone https://github.com/inteligyware/salespoint.git
	
It will create a salespoint directory. Enter at the directory and run

	qmake
	make
	
To install salespoint you need to be root.

As root, type:
	make install

And that's all.

Cleaning all sources.
----------------------

As user type:

	make clean


Uninstalling salespoint.
------------------

As root, type:

	make uninstall
