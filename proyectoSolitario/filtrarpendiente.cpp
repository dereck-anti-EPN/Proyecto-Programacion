#include "filtrarpendiente.h"
#include "ui_filtrarpendiente.h"

//mis includes================
#include<QMessageBox>

filtrarPendiente::filtrarPendiente(const std::vector<pendientesStruct> &pendientes
                                   ,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::filtrarPendiente),
    pendientesVector(pendientes)
{
    ui->setupUi(this);
    //HEADERS
    ui->tablaFiltrar->setColumnCount(3);
    QStringList headers;
    headers << "ID" << "Responsable" << "Descripcion";
    ui->tablaFiltrar->setHorizontalHeaderLabels(headers);

    //auto redimencion segun que tan grandes o pequeñas son los datos de la tabla
    ui->tablaFiltrar->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

filtrarPendiente::~filtrarPendiente()
{
    delete ui;
}

void filtrarPendiente::on_botonBuscar_clicked()
{
    QString estadoBusc = ui->estadoFiltrar->currentText();
    bool encontrado = false;

    //para que la tabla se limpie cada que se busca de nuevo
    ui->tablaFiltrar->setRowCount(0);

    for(const pendientesStruct &i: pendientesVector){
        if(i.estado == estadoBusc){
            //cuenta las filas actuales por iteracion
            int fila = ui->tablaFiltrar->rowCount();
            //pone una nueva fila vacia a la tabla
            ui->tablaFiltrar->insertRow(fila);

            //columna 0, 1 y 2 respectivamente
            ui->tablaFiltrar->setItem(fila, 0, new QTableWidgetItem(QString::number(i.id)));
            ui->tablaFiltrar->setItem(fila, 1, new QTableWidgetItem(i.responsable));
            ui->tablaFiltrar->setItem(fila, 2, new QTableWidgetItem(i.descripcion));

            encontrado = true;
        }
    }

    if(encontrado == false){
        QMessageBox::warning(this, "ERROR", "No existen pendientes con ese estado");
    }
}
