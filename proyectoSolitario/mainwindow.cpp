#include "mainwindow.h"
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
    crear = new crearPendiente(this);
    connect(crear, &crearPendiente::signalPendientes,
            this, &MainWindow::slotPendientes);
    crear->show();
}

void MainWindow::guardarArchivo()
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

void MainWindow::slotPendientes(pendientesStruct vainaVolatilPendiente) //AL FINAL DE TODO
{
    pendientesVector.push_back(vainaVolatilPendiente); //GUARDADITO EN EL VECTOR e.e
    guardarArchivo();   //SE LLAMA A LA FUNCION DE ARRIBITA
}
