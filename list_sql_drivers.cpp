#include <iostream>
#include <Qt>
#include <QApplication>
#include <QtSql>

using namespace std;

int main(int argc , char* argv[])
{
	QApplication app(argc,argv); // load plugins
	//output of all loaded sql plugins
	cout << "QSqlDatabase::drivers() output: " << QSqlDatabase::drivers().join(QString("; ")).toLatin1().data() << "\n"; 

    return 0;
}

