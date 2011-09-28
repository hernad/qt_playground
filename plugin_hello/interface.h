#include <QtPlugin>

class QApplication;
 
class Plugin1
{
	public:
	    virtual ~Plugin1() {}
		virtual void start( QApplication* ) = 0;
};
 
Q_DECLARE_INTERFACE( Plugin1, "ba.out.bring.qt.Plugin1/1.0")

