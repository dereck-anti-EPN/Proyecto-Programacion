#include "cambiarpendiente.h"
#include "ui_cambiarpendiente.h"

cambiarPendiente::cambiarPendiente(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cambiarPendiente)
{
    ui->setupUi(this);
}

cambiarPendiente::~cambiarPendiente()
{
    delete ui;
}
