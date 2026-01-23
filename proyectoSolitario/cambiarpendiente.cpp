#include "cambiarpendiente.h"
#include "ui_cambiarpendiente.h"

//mis includes========================
#include<QMessageBox>
#include<QString>

cambiarPendiente::cambiarPendiente(vector<pendientesStruct> &pendientes ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cambiarPendiente),
    pendientesVector(pendientes)
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

    for(pendientesStruct &i : pendientesVector){
        if(i.id == idBuscado){
            i.estado = nuevoEstado;
            encontrado = true;
            break;
        }
    }
    if(encontrado == true){
        emit signalActualizar(pendientesVector);
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
            ui->estadoViejo->setText(i.estado);
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

