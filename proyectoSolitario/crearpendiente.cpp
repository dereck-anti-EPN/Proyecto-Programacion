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
    QString responsable = ui->respLinea->text();
    id = ui->idLinea->value();
    QString descripcion = ui->descLinea->toPlainText();
    QString estado = ui->estadoLinea->currentText();
    QMessageBox::information(this, "Ventana emergente", "Guardado exitosamente");
}

