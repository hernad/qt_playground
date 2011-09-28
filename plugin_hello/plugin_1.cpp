#include "plugin_1.h"

#include <QObject>
#include <QtCore>
#include <QApplication>
#include <QtGui>

//MainWindow *glpMainWindow;

void Plugin1Imp::start( QApplication* a )
{
	    //glpMainWindow = new MainWindow( a );
		//glpMainWindow->show();
		

	    qDebug() << "hello";
	    return;
}
 

Q_EXPORT_PLUGIN2( plugin_1, Plugin1Imp )
