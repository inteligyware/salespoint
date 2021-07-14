# salespoint
C++/Qt based point of sale application
----------------------------------------------------------------
salespoint is a point of sale (POS) system designed and developed 
by Inteligy Software Enterprise (InteligyWare). It was inspired 
by Sage (Developped by Sage) and nTPV (An open source POS developped 
by Napsis Corp). salespoint is developped to provide an open source 
alternative to sage.

It was initially designed to manage restaurants, bars, cafes, 
and similar businesses, but now, it's evolving into a general purpose POS. 
It uses DCOP and nkxmlrpcd for distributed comunications among POS, 
and uses PostgreSQL as its database backend. It features a fast and 
easy-to-use interface. Its high modularity and scalability makes it easy to
enhance and mantain.

InteligyWare provides other plugins that add more features to the POS systems like:
	[ DCOPFX2000 ] Biometric fingerprint autentication of waiters and users.
	[ DCOPRECEIPT ] Easy use of orders, tables, and invoice saving... no more ordering notebooks are needed
	[ DCOPREPORTS ] Reports generated with this plugin allows to obtain information to increase benefits.
	[ DCOPSTICK ] Manage your backups and store your reports with USB storage drives.

Currently all these modules except DCOPFX2000 have been released with this source package.
If you are interested on the Biometric fingerprint autentication, please send a mail to <benes@inteligyware.com>

libraries needed to compile salespoint
--------------------------------

	- libgdchart (http://www.fred.net/brv/chart/)
	- qt5 (www.qt.io))
	- qt5 postgres plugin
	- Qt Creator (www.qt.io)
	- libxml2 (http://xmlsoft.org/)
	


Installing salespoint  (Quick method.)
----------------------------------

salespoint now uses QMake package generation thanks to Trolltech. 
It's very simple and quick to compile and install salespoint. 

QMake must be installed.


As user, type:

	tar xjvf salespoint.tar.xz
	
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
