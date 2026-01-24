#include "cambiarpendiente.h"
#include "ui_cambiarpendiente.h"

//mis includes========================
#include<QMessageBox>
#include<QString>

cambiarPendiente::cambiarPendiente(std::vector<pendientesStruct> &pendientes ,QWidget *parent)//constructor
    : QDialog(parent)
    , ui(new Ui::cambiarPendiente),
    pendientesVector(pendientes) //vector(OJO)
{
    ui->setupUi(this);
}

cambiarPendiente::~cambiarPendiente()
{
    delete ui;
}

void cambiarPendiente::on_botonCambiar_clicked()
{
    int idBuscado = ui->idCambiar->value();
    QString nuevoEstado = ui->estadoCambiar->currentText();
    bool encontrado = false;

    if(ui->idCambiar->text().isEmpty()){ //"isEmpty()" mira si es que esta vacio o no
        QMessageBox::warning(this, "Error", "La ID esta vacia, llenela e intente nuevamente");
        return;
    }

    for(pendientesStruct &i : pendientesVector){
        if(i.id == idBuscado){
            if(i.estado == nuevoEstado){
                QMessageBox::warning(this, "Error", "El estado actual es igual al nuevo");
                return;
            }
            i.estado = nuevoEstado;
            encontrado = true;
            break;
        }
    }
    if(encontrado == true){
        emit signalActualizar(pendientesVector);//hace un emit para que el slot agregue el cambio del vector
        QMessageBox::information(this, "Exito", "El estado se actualizo");
        this->accept(); //cierra la pestaña solita
    }else{
        QMessageBox::warning(this, "Error", "No se encontro esa ID");
    }
}

void cambiarPendiente::on_botonBuscar_clicked()
{
    int idBuscado = ui->idCambiar->value();
    bool encontrado = false;

    for(const pendientesStruct &i : pendientesVector){
        if(i.id == idBuscado){
            ui->estadoViejo->setText(i.estado); //para que en el campo se escriba el estado
            encontrado = true;
            break;
        }
    }
    if(encontrado == false){
        QMessageBox::warning(this, "Error", "No se encontro la ID");
    }
}

void cambiarPendiente::on_botonSalir_clicked()
{
    close();
}
