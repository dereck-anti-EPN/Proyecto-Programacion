#include "crearpendiente.h"
#include "ui_crearpendiente.h"

//MIS DECLARACIONES
#include"qmessagebox.h"

crearPendiente::crearPendiente(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::crearPendiente)
{
    ui->setupUi(this);
}

crearPendiente::~crearPendiente()
{
    delete ui;
}

void crearPendiente::on_botonGuardar_clicked()
{
    //NO PONER vainaVolatilPendiente.QString por que eso no existe... SIN EL QString SIRVE
    //con los "vainaVolatilPendiente.EJEMPLITO" guardas los datos en el vector/struct, nose
    pendientesStruct vainaVolatilPendiente;
    vainaVolatilPendiente.responsable = ui->respLinea->text();
    vainaVolatilPendiente.id = ui->idLinea->value();
    vainaVolatilPendiente.descripcion = ui->descLinea->toPlainText();
    vainaVolatilPendiente.estado = ui->estadoLinea->currentText();

    emit signalPendientes(vainaVolatilPendiente); //EMITE LA SEÑAL

    QMessageBox::information(this, "Ventana emergente", "Guardado exitosamente");
}
