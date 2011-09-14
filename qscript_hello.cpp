#include <Qt>
#include <QtScript>
#include <QApplication>
#include <QtGui>

static QScriptValue evaluateFile(QScriptEngine &engine, const QString &fileName)
{
    // http://stackoverflow.com/questions/5630114/how-to-read-utf-8-text-from-file-using-qt

	/*
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    return engine.evaluate(file.readAll(), fileName);
	*/

	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		throw;
	};

	QTextStream in(&file);
	in.setCodec("UTF-8");

	QString line = "";
	while (!in.atEnd()) {
		line += in.readLine();
	}

	qDebug() << line;
	return engine.evaluate(line);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget widget;
    QGridLayout *layout = new QGridLayout( &widget );

	QPushButton *button = new QPushButton( "1");
	QPushButton *button2 = new QPushButton( "2");

	layout->addWidget( button, 1, 0);
	layout->addWidget( button2, 1, 1);

	widget.show();

   	QScriptEngine engine;
	QScriptValue scriptButton = engine.newQObject(button);
	QScriptValue scriptButton2 = engine.newQObject(button2);


	  
	engine.globalObject().setProperty("button", scriptButton);
    engine.globalObject().setProperty("button2", scriptButton2);

		evaluateFile(engine, "hello.js");

	/*
	 
    QString s = QString::fromUtf8("button.text = 'Hello World from QScript Ernad Husremović'");
	engine.evaluate(s);
	
	engine.evaluate("button.styleSheet = 'font-style: italic'");
	engine.evaluate("button.show()");
    */

	return app.exec();
}
