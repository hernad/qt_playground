# http://doc.qt.nokia.com/stable/qmake-tutorial.html

# http://doc.qt.nokia.com/stable/sql-driver.html#how-to-build-the-qpsql-plugin-on-unix-and-mac-os-x
macx {
  message( "vrtim se na mac-u")
  QMAKESPEC = macx-g++
  message(spec switch setovan na: $$QMAKESPEC)
}

!exists( list_sql_drivers.cpp ) {
   error( "no main list_sql_drivers.cpp found" )
}
 
CONFIG += qt debug
TEMPLATE=app
INCLUDEPATH+=.
INCLUDEPATH+=/Library/PostgreSQL/9.1/include
LIBS+=/Library/PostgreSQL/9.1/lib/libpq.a
SOURCES=list_sql_drivers.cpp

QT+=sql

