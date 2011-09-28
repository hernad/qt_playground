#include <Qt>
#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QDebug>
#include <QDate>
#include <iostream>

using namespace::std;

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     QTranslator translator;
     
     
	 QLocale::setDefault(QLocale::German);

	 QLocale german;

	 //QString locale("ba");
	 //QLocale bosnian("ba");

	 //QLocale::setDefault(bosnian);

	 
	 //QLocale::setDefault(QLocale::Bosnian);



	 QString locale = QLocale::system().name();
	 //QString locale = german.name();
	 QString str_tran("hello_tr_" + locale);

	 QString broj_sa_tackom("1234.56");
	 QString broj_sa_zarez("1234,56");

	 QString nas_datum("16.01.2004");

	 bool ok;

	 qDebug() << broj_sa_tackom << broj_sa_tackom.toDouble(&ok) << ok;
	 qDebug() << broj_sa_zarez << broj_sa_zarez.toDouble(&ok) << ok;
	 qDebug() << "ucitavam " << str_tran;

	 QDate danas(QDate::currentDate());
	 
	 QDate d = QDate::fromString("2004-01-16", Qt::ISODate);
	 qDebug() << "2004-01-16" << d;

	 qDebug() << danas;
	 qDebug() << german.toString(danas, QLocale::LongFormat);
	 qDebug() << german.toString(danas, QLocale::ShortFormat);
	
	 qDebug() << german.dateFormat(QLocale::ShortFormat);
	 qDebug() << german.dateFormat(QLocale::LongFormat);
	 
	 //qDebug() << "lokalno datum" << nas_datum << QDate::fromString(nas_datum, Qt::LocalDate);
	 //qDebug() << "lokalno datum" << nas_datum << QDate::fromString(nas_datum, Qt::DefaultLocaleLongDate);

	 QLocale::setDefault(QLocale::Bosnian);
     QLocale bosnian;

	 if (bosnian.name() == "bs_BA") 
	 {
		 qDebug() << "bosna bosna ...";

		 qDebug() << bosnian.dateFormat(QLocale::ShortFormat);
		 qDebug() << bosnian.dateFormat(QLocale::LongFormat);
	 
	 }
	 else
		 qDebug() << "truba truba ...";

	 qDebug() << bosnian.toString(danas, QLocale::LongFormat);
	 qDebug() << bosnian.toString(danas, QLocale::ShortFormat);
	

	 QLocale::setDefault(QLocale::Croatian);
     QLocale croat;
	 qDebug() << "locale name" << croat.name();

	 qDebug() << croat.toString(danas, QLocale::LongFormat);
	 qDebug() << croat.toString(danas, QLocale::ShortFormat);
	


     translator.load(str_tran);	 
	 //For a translation-aware application a translator object is created, a translation is loaded and the translator object installed into the application.
     app.installTranslator(&translator);

     // For non-Latin1 strings in the sources you will also need for example:
     QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

	 qDebug() << translator.translate("ctx_1","hello_string");

	 cout << "--end of program--" << endl;

	 return 0;

}
