#include "mainwindow.h"
#include "filtrarpendiente.h"
#include "ui_mainwindow.h"

//MIS INCLUDES==================================
#include<qmessagebox.h> //pa las ventanas emergentes
#include<QTextStream> //escribe y lee txt
#include<QFile> //pa los archivos

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cargarArchivo(); //LLAMA A LA FUNCION
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botonCrear_clicked(){
    crear = new crearPendiente(pendientesVector, this);
    connect(crear, &crearPendiente::signalPendientes,
            this, &MainWindow::slotPendientes);
    crear->show();
}

void MainWindow::guardarArchivo() //funcion para guardar el archivo
{
    QFile archivito("pendientes.txt");
    if (!archivito.open(QIODevice::WriteOnly | QIODevice::Text)) {//POR SI NO LLEGA A SER POSIBLE ABRIRLO
        QMessageBox::warning(this, "Error", "No fue posible abrir el archivo");
        return;
    }

    QTextStream out(&archivito);

    for (const pendientesStruct &p : pendientesVector) {
        out << p.id << "|"
            << p.responsable << "|"
            << p.descripcion << "|"
            << p.estado << "\n";
    }
    archivito.close();
}

void MainWindow::cargarArchivo()
{
    QFile archivito("pendientes.txt");

    if (!archivito.open(QIODevice::ReadOnly | QIODevice::Text)) { //SI NO SE PUEDE ABRIR
        return;
    }

    QTextStream in(&archivito); //LEE EL ARCHIVO LINEA POR LINEA

    while (!in.atEnd()) { //HASTA LLEGAR AL FINAL
        QString linea = in.readLine(); //LEE TODA UNA LINEA
        QStringList partes = linea.split("|"); //DIVIDE TODOS LOS DATOS

        if (partes.size() == 4) {
            pendientesStruct p;
            p.id = partes[0].toInt();
            p.responsable = partes[1];
            p.descripcion = partes[2];
            p.estado = partes[3];

            pendientesVector.push_back(p); //SI LA LINEA TIENE 4 DATOS EMPUJA TODO AL VECTOR
        }
    }

    archivito.close();
}

void MainWindow::on_botonLeer_clicked()
{
    leer = new leerPendientes(pendientesVector, this); // this = ventana padre
    leer->show();
}

void MainWindow::on_botonCambiar_clicked()
{
    //variable local que luego se desecha
    cambiarPendiente *cambiar = new cambiarPendiente(pendientesVector, this);

    connect(cambiar, &cambiarPendiente::signalActualizar,
            this, &MainWindow::slotActualizar);
    cambiar->show();
}

void MainWindow::on_botonEliminar_clicked()
{
    eliminar = new eliminarPendiente(pendientesVector ,this);
    connect(eliminar, &eliminarPendiente::signalEliminar,
            this, &MainWindow::slotEliminar);

    eliminar->show();
}

//AL FINAL DE TODO===================================================

void MainWindow::slotPendientes(pendientesStruct vainaVolatilPendiente)
{
    pendientesVector.push_back(vainaVolatilPendiente); //GUARDADITO EN EL VECTOR e.e
    guardarArchivo();   //SE LLAMA A LA FUNCION DE ARRIBITA
}

void MainWindow::slotActualizar(vector<pendientesStruct> pendientesActualizados)
{
    pendientesVector = pendientesActualizados;
    guardarArchivo();
}

void MainWindow::slotEliminar(vector<pendientesStruct> nuevoVector)
{
    pendientesVector = nuevoVector;
    guardarArchivo();
}

void MainWindow::on_botonFiltrar_clicked()
{
    filtrar = new filtrarPendiente(pendientesVector, this);
    filtrar->show();
}
