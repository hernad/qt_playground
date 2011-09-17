#ifndef TODO_H
#define TODO_H

#include <QObject>




class ToDo : public QObject
{
    Q_OBJECT
public:

    ToDo(QObject *parent);


public slots:

    void run();

signals:
    void finished();
};

#endif // TODO_H
