#include "crearpendiente.h"
#include "ui_crearpendiente.h"

//MIS DECLARACIONES
#include"qmessagebox.h"

crearPendiente::crearPendiente(const std::vector<pendientesStruct> &pendientes
                               ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::crearPendiente),
    pendientesVector(pendientes)
{
    ui->setupUi(this);
}

crearPendiente::~crearPendiente()
{
    delete ui;
}

void crearPendiente::on_botonGuardar_clicked()
{
    if(ui->idLinea->text().isEmpty()){ //"isEmpty()" mira si es que esta vacio o no
        QMessageBox::warning(this, "Error", "La ID esta vacia, llenela e intente nuevamente");
        return;
    }

    if(ui->descLinea->toPlainText().isEmpty()){ //para un textEdit se usa el "toPlainText()"
        QMessageBox::warning(this, "Error", "La descripcion esta vacia, llenela e intente nuevamente");
        return;
    }

    if(ui->respLinea->text().isEmpty()){
        QMessageBox::warning(this, "Error", "El resposable esta vacio, llenelo e intente nuevamente");
        return;
    }

    for(const pendientesStruct &i : pendientesVector){
        if(ui->idLinea->value() == i.id){
            QMessageBox::warning(this, "Error", "Esta ID ya esta en uso");
            return;
        }
    }

    //NO PONER vainaVolatilPendiente.QString por que eso no existe... SIN EL QString SIRVE
    //con los "vainaVolatilPendiente.EJEMPLITO" guardas los datos en el vector/struct, nose
    pendientesStruct vainaVolatilPendiente;
    vainaVolatilPendiente.responsable = ui->respLinea->text();
    vainaVolatilPendiente.id = ui->idLinea->value();
    vainaVolatilPendiente.descripcion = ui->descLinea->toPlainText();
    vainaVolatilPendiente.estado = ui->estadoLinea->currentText();

    emit signalPendientes(vainaVolatilPendiente); //EMITE LA SEÑAL

    QMessageBox::information(this, "Exito", "Guardado exitosamente");
    this->accept(); //cierra la pestaña crear solita
}
