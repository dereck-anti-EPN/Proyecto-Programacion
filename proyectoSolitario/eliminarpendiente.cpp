#include "eliminarpendiente.h"
#include "ui_eliminarpendiente.h"

//mis includes==============
#include<QMessageBox>

eliminarPendiente::eliminarPendiente(std::vector<pendientesStruct> &pendientes,
                                    QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::eliminarPendiente),
    pendientesVector(pendientes)
{
    ui->setupUi(this);
}

eliminarPendiente::~eliminarPendiente()
{
    delete ui;
}

void eliminarPendiente::on_botonEliminar_clicked()
{
    int idBuscado = ui->idEliminar->value();
    bool encontrado=false;

    for(size_t i = 0;i<pendientesVector.size();i++){
        if(idBuscado == pendientesVector[i].id){
            pendientesVector.erase(pendientesVector.begin()+i);
            encontrado= true;
            break;
        }
    }
    if(encontrado == true){
        emit signalEliminar(pendientesVector);
        QMessageBox::information(this,"Exito","EL pendiente se elimino");
    }else{
        QMessageBox::warning(this, "Error", "No se encontro esa ID");
    }
}
