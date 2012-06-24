#include <QApplication>
#include "mainwindow.h"
#include "karticaartikla.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KarticaArtikla w;
    //MainWindow w;
    w.show();
    
    return a.exec();
}
