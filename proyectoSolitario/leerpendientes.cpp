#include "leerpendientes.h"
#include "ui_leerpendientes.h"

//mis includes===================
#include<QMessageBox>

using namespace std;

leerPendientes::leerPendientes(const vector<pendientesStruct> &pendientes,
                               QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::leerPendientes),
    pendientesVector(pendientes) //se crea una copia ya que solo es pa leerse, no modificarse===================
{
    ui->setupUi(this);
}

leerPendientes::~leerPendientes()
{
    delete ui;
}

void leerPendientes::on_botonBuscar_clicked()
{
    int idBuscado = ui->idLeer->value();
    bool encontrado = false;

    for(const pendientesStruct &i : pendientesVector){
        if(i.id == idBuscado){
            //esto imprimira los datos en cada campo, por eso tiene los nombres de los campos de texto OJO
            ui->respLeer->setText(i.responsable);
            ui->descLeer->setText(i.descripcion);
            ui->estadoLeer->setText(i.estado);

            encontrado = true;
            break;
        }
    }
    if(encontrado == false){
        QMessageBox::warning(this, "ERROR", "No existe esa ID");
    }
}
