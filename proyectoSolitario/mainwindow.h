#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>
//INCLUDES DE LOS .h=============
#include "crearpendiente.h"
#include "leerpendientes.h"
#include "cambiarpendiente.h"
#include "eliminarpendiente.h"
#include "filtrarpendiente.h"

using namespace std; //IMPORTANTISIMO======================================

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots://ACA PONER LO QUE ACCIONE A LOS SIGNALS PONER SOLO CON NOMBRE DE "SLOT"
    //void on_NOMBRE DEL BOTON_clicked(); asi sabe el programa que boton habre x ventana
    void on_botonCrear_clicked();
    void slotPendientes(pendientesStruct vainaVolatilPendiente); //ESTE SLOT ACCIONA LO DEL SIGNAL============

    void on_botonLeer_clicked();

    void on_botonCambiar_clicked();

    void slotActualizar(std::vector<pendientesStruct> pendientesActualizados);

    void on_botonEliminar_clicked();
    void slotEliminar(std::vector<pendientesStruct> nuevoVector);

    void on_botonFiltrar_clicked();

private:
    Ui::MainWindow *ui;
    //declaracion de punteros, osea de todo lo que se hace pssss
    //*ejemplito = esto le pones a los cositos esos que estan en el mainwindow.cpp
    crearPendiente *crear;
    leerPendientes *leer;
    cambiarPendiente *cambiar;
    eliminarPendiente *eliminar;
    filtrarPendiente *filtrar;

    vector<pendientesStruct> pendientesVector;//vector declarado

    void guardarArchivo();
    void cargarArchivo();
    bool noPendiente();
};
#endif // MAINWINDOW_H
