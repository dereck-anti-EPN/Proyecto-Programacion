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

    //HEADERS para la tabla
    ui->tablaFiltrar->setColumnCount(3); //columnas (no empieza desde 0)
    QStringList headers; //guardar el titulo de las columnas en la tabla
    headers << "ID" << "Responsable" << "Descripcion";//titulos
    ui->tablaFiltrar->setHorizontalHeaderLabels(headers);//utilizar los titulos que le pusimos
    /*
     * auto redimencion segun que tan grandes o pequeñas son los datos de la tabla
     * solo en horizontal
     * resize
    */
    ui->tablaFiltrar->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

filtrarPendiente::~filtrarPendiente()
{
    delete ui;
}

void filtrarPendiente::on_botonBuscar_clicked()
{
    QString estadoBusc = ui->estadoFiltrar->currentText(); //currentText() por que es un spinbox
    bool encontrado = false;

    if(ui->estadoFiltrar->currentText().isEmpty()){
        QMessageBox::warning(this, "Error", "El estado esta vacio, llenelo e intente nuevamente");
        return;
    }

    //para que la tabla se limpie cada que se busca de nuevo
    ui->tablaFiltrar->setRowCount(0);

    for(const pendientesStruct &i: pendientesVector){
        if(i.estado == estadoBusc){
            //cuenta las filas actuales por iteracion con rowCount()
            int fila = ui->tablaFiltrar->rowCount();
            //pone una nueva fila vacia a la tabla con insertRow()
            ui->tablaFiltrar->insertRow(fila);

            //columna 0, 1 y 2 respectivamente
            ui->tablaFiltrar->setItem(fila, 0, new QTableWidgetItem(QString::number(i.id)));//::number
            ui->tablaFiltrar->setItem(fila, 1, new QTableWidgetItem(i.responsable));
            ui->tablaFiltrar->setItem(fila, 2, new QTableWidgetItem(i.descripcion));

            encontrado = true;
        }
    }

    if(encontrado == false){
        QMessageBox::warning(this, "ERROR", "No existen pendientes con ese estado");
    }
}

void filtrarPendiente::on_botonBuscar_2_clicked()
{
    close();
}

