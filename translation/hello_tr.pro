# http://doc.qt.nokia.com/stable/qmake-tutorial.html

# http://redmine.bring.out.ba/issues/24591

TEMPLATE=app
INCLUDEPATH+=.
#INCLUDEPATH+=/Library/PostgreSQL/9.1/include
#LIBS+=/Library/PostgreSQL/9.1/lib/libpq.a
SOURCES=main.cpp

# HEADERS += hello.h

CONFIG += qt debug

# QT+=sql


TRANSLATIONS = hello_tr_bs_BA.ts \
               hello_tr_de_DE.ts
