#include "mainwindow.h"
#include "ui_mainwindow.h"
//mis includes
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

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"saludaso","hola chucha");
}

