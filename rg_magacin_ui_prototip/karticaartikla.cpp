#include "karticaartikla.h"
#include "ui_karticaartikla.h"

KarticaArtikla::KarticaArtikla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KarticaArtikla)
{
    ui->setupUi(this);
}

KarticaArtikla::~KarticaArtikla()
{
    delete ui;
}
