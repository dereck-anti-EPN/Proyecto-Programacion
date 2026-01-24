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
//========================================FUNCIONES========================================

void MainWindow::on_botonCrear_clicked(){ //crear=puntero
    crear = new crearPendiente(pendientesVector, this); //creando la ventan con el puntero
/*
aqui conectas el signal con su slot:
ej: connect(punteroNombre, &construtctorNombre::signalNombre,
                this, &MainWindow::slotNombre);
    punteroNombre->show();
y va con "&" por que siempre cambio las cosas con un puntero
*/
    connect(crear, &crearPendiente::signalPendientes,
            this, &MainWindow::slotPendientes);
    crear->show();
}

bool MainWindow::noPendiente() //funcion para cuando no existen pendientes
{
    if(pendientesVector.empty()){
        QMessageBox::warning(this, "Error", "No existen pendientes registrados, primero cree uno");
        return false;
    }
    return true;
}

void MainWindow::guardarArchivo() //funcion para guardar el archivo
{
    QFile archivito("pendientes.txt"); //nombre del archivo
/*
    "archivito.open(QIODevice::WriteOnly | QIODevice::Text"
WriteOnly: escribe desde el inicio y borra todo si es que ya hay algo
Text: texto plano
*/
    if (!archivito.open(QIODevice::WriteOnly | QIODevice::Text)) {//POR SI NO LLEGA A SER POSIBLE ABRIRLO
        QMessageBox::warning(this, "Error", "No fue posible abrir el archivo");
        return;
    }

    QTextStream out(&archivito); //escribir en el archivo

    for (const pendientesStruct &i : pendientesVector) {
        //out<< i.ejemplo << "|" solo escribe
        out << i.id << "|"
            << i.responsable << "|"
            << i.descripcion << "|"
            << i.estado << "\n";
    }
    archivito.close();
}

void MainWindow::cargarArchivo()
{
    QFile archivito("pendientes.txt");

    //solo pa leer
    if (!archivito.open(QIODevice::ReadOnly | QIODevice::Text)) { //SI NO SE PUEDE ABRIR
        return;
    }

    QTextStream in(&archivito); //LEE EL ARCHIVO LINEA POR LINEA

    //si no esta enElFinal
    while (!in.atEnd()) { //mientras no llegue al final
        QString linea = in.readLine(); //LEE TODA UNA LINEA
        QStringList partes = linea.split("|"); //busca el separador de datos "|" para leer los datos hasta el

        if (partes.size() == 4) {
            pendientesStruct p;
            //p.ejemplo = partes[indice];
            p.id = partes[0].toInt(); //lo convierte a int ".toInt()"
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
    if(noPendiente() == false){
        return;
    }
    leer = new leerPendientes(pendientesVector, this); // this = ventana padre
    leer->show();
}

void MainWindow::on_botonCambiar_clicked()
{
    if(noPendiente() == false){
        return;
    }
    //variable local que luego se desecha
    cambiarPendiente *cambiar = new cambiarPendiente(pendientesVector, this);

    connect(cambiar, &cambiarPendiente::signalActualizar, //conectar signal con slot==========
            this, &MainWindow::slotActualizar);
    cambiar->show();
}

void MainWindow::on_botonEliminar_clicked()
{
    if(noPendiente() == false){
        return;
    }
    eliminar = new eliminarPendiente(pendientesVector ,this);
    connect(eliminar, &eliminarPendiente::signalEliminar,//conectar signal con slot==========
            this, &MainWindow::slotEliminar);

    eliminar->show();
}

void MainWindow::on_botonFiltrar_clicked()
{
    if(noPendiente() == false){
        return;
    }
    filtrar = new filtrarPendiente(pendientesVector, this);
    filtrar->show();
}

//========================================AL FINAL DE TODO============================================

void MainWindow::slotPendientes(pendientesStruct vainaVolatilPendiente)//aqui se hace el push.back
{
    pendientesVector.push_back(vainaVolatilPendiente); //GUARDADITO EN EL VECTOR los datos de antes e.e
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
