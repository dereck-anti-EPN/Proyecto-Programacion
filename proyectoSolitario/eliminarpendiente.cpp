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

    if(ui->idEliminar->text().isEmpty()){ //"isEmpty()" mira si es que esta vacio o no
        QMessageBox::warning(this, "Error", "La ID esta vacia, llenela e intente nuevamente");
        return;
    }

    for(size_t i = 0;i<pendientesVector.size();i++){ //no se puede hacer con un for moderno
        if(idBuscado == pendientesVector[i].id){
            pendientesVector.erase(pendientesVector.begin()+i); //para acomodarlos
            encontrado= true;
            break;
        }
    }
    if(encontrado == true){
        emit signalEliminar(pendientesVector);
        QMessageBox::information(this,"Exito","EL pendiente se elimino");
        this->accept();
    }else{
        QMessageBox::warning(this, "Error", "No se encontro esa ID");
    }
}

void eliminarPendiente::on_botonSalir_clicked()
{
    close();
}
