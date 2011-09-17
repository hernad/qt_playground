#include <QtCore>

#include "todo.h"


int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);

    // Task parented to the application so that it
    // will be deleted by the application.
    ToDo *todo = new ToDo(&a);

    // This will cause the application to exit when
    // the task signals finished.
    QObject::connect(todo, SIGNAL(finished()), &a, SLOT(quit()));

    // This will run the task from the application event loop.
    QTimer::singleShot(0, todo, SLOT(run()));


    // http://stackoverflow.com/questions/4180394/how-do-i-create-a-simple-qt-console-application-in-c


    return a.exec();
}

/*
int main(int argc, char *argv[])
{
    printf ("Howdy\n");

    tcPlayApp a(argc, argv);
    ConsoleInput cn (&a);
    return a.exec();
}
*/

