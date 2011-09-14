= QT library playground

== Mac build, run

build:

```
qmake -spec macx-g++ list_sql_drivers.pro ## pravi makefile a ne xcode projekat
make
```

run mac app:

```
list_sql_drivers.app/Contents/MacOS/list_sql_drivers 

   => QSqlDatabase::drivers() output: QSQLITE; QODBC3; QODBC
```

== PostgreSQL podrška Mac OS X

pokrenuti iz source qt direktorija:
```
find . -name "psql.pro" -exec ./add_postgres_support.sh \{\} \;
```
add_postgres_support.sh
```
echo ""  >> $1
echo "INCLUDEPATH     += /Library/PostgreSQL/9.1/include" >> $1
echo "LIBS            += -L/Library/PostgreSQL/9.1/lib" >>   $1
```

rezultat bi trebao biti:

cat ./src/sql/drivers/psql/qsql_psql.pri
```
HEADERS += $$PWD/qsql_psql.h
SOURCES += $$PWD/qsql_psql.cpp

unix|win32-g++* {
    LIBS *= $$QT_LFLAGS_PSQL
    !contains(LIBS, .*pq.*):LIBS += -lpq
    QMAKE_CXXFLAGS *= $$QT_CFLAGS_PSQL
} else {
    !contains(LIBS, .*pq.*):LIBS += -llibpq -lws2_32 -ladvapi32
}

INCLUDEPATH     += /Library/PostgreSQL/9.1/include
LIBS            += -L/Library/PostgreSQL/9.1/lib
```

nakon toga configure sa psql podrškom:

```
./configure -v -qt-sql-psql
```
