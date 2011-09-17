#include "todo.h"
#include <iostream>
#include <string>

ToDo::ToDo(QObject *parent = 0) :
    QObject(parent)
{
}

using namespace std;
void ToDo::run()
{
    // Do processing here


    qDebug("ovdje nesto radim ...");
    qDebug("ovdje nesto radim jos ...");

    string name;
    cout << "Enter name: ";
    cin >> name;
    cout << "Your name is " << name << endl;

    emit finished();
}
