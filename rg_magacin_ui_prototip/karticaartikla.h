#ifndef KARTICAARTIKLA_H
#define KARTICAARTIKLA_H

#include <QMainWindow>

namespace Ui {
class KarticaArtikla;
}

class KarticaArtikla : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KarticaArtikla(QWidget *parent = 0);
    ~KarticaArtikla();
    
private:
    Ui::KarticaArtikla *ui;
};

#endif // KARTICAARTIKLA_H
