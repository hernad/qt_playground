= QT library playground

== Mac build, run

build:

``
qmake -spec macx-g++ list_sql_drivers.pro ## pravi makefile a ne xcode projekat
make
``

run mac app:

``
list_sql_drivers.app/Contents/MacOS/list_sql_drivers 

   => QSqlDatabase::drivers() output: QSQLITE; QODBC3; QODBC
``
