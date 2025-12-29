#include "mainwindow.h"
#include "ui_mainwindow.h"
//MIS INCLUDES==================================
#include<qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botonCrear_clicked(){
    crear = new crearPendiente(this);
    crear->show();
}
