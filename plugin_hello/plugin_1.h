#include <QObject>
#include <QApplication>
#include <QDebug>

#include "interface.h"

class QApplication;
 
class Plugin1Imp : public QObject, public Plugin1 {
	    
	Q_OBJECT
	Q_INTERFACES( Plugin1 )
				 
	public:
		 //virtual ~plugin_1() {};
		 virtual void start( QApplication * );
};
