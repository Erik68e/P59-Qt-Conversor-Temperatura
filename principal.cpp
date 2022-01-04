#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    // Conectar el dial de Centigrados con el slot de ESTA clase
    connect(ui->intCent,SIGNAL(valueChanged(int)), this, SLOT(cent2fahr(int)));
    // Conectar el dial de Farenheit con el slot de ESTA clase
    connect(ui->intFahr,SIGNAL(valueChanged(int)), this, SLOT(fahr2cent(int)));
    // Conectar el dial de Kelvin con el slot de ESTA clase
    connect(ui->intKel,SIGNAL(valueChanged(int)), this, SLOT(cent2kel(int)));
}

Principal::~Principal()
{
    delete ui;
}

//El dato puesto en centigrados lo pasa a farenheit y kelvin
void Principal::cent2fahr(int cent)
{
    if(ui->intCent->hasFocus()){
        //Farenheit
        int fahr = (cent * 9.0/5) + 32;
        ui -> intFahr -> setValue(fahr);
        //Kelvin
        int kel = cent + 273.15;
        ui -> intKel -> setValue(kel);
    }
}

//El dato puesto en kelvin lo pasa a centigrados y farenheit
void Principal::cent2kel(int kel)
{
    if(ui->intKel->hasFocus()){
        //Centigrados
        int cent = kel - 273.15;
        ui -> intCent -> setValue(cent);
        //Farenheit
        int fahr = ((kel - 273.15) * 9.0/5) + 32;
        ui -> intFahr -> setValue(fahr);
    }
}

//El dato puesto en farenheit lo pasa a centigrados y kelvin
void Principal::fahr2cent(int fahr)
{
    if(ui->intFahr->hasFocus()){
        //Centigrados
        int cent = (fahr - 32) * 5.0/9;
        ui -> intCent -> setValue(cent);
        //Kelvin
        float kel = ((fahr - 32) * 5.0/9) + 273.15;
        ui -> intKel -> setValue(kel);
    }
}

