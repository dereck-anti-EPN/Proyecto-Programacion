#include "eliminarpendiente.h"
#include "ui_eliminarpendiente.h"

eliminarPendiente::eliminarPendiente(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::eliminarPendiente)
{
    ui->setupUi(this);
}

eliminarPendiente::~eliminarPendiente()
{
    delete ui;
}
