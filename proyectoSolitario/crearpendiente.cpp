#include "crearpendiente.h"
#include "ui_crearpendiente.h"

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
