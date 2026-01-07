#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//INCLUDES DE LOS .h=============
#include "crearpendiente.h"
#include <vector>
#include "crearpendiente.h"

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
    void on_botonCrear_clicked();
    void slotPendientes(pendientesStruct vainaVolatilPendiente); //ESTE SLOT ACCIONA LO DEL SIGNAL============

private:
    Ui::MainWindow *ui;
    crearPendiente *crear;
    vector<pendientesStruct> pendientesVector;

    void guardarArchivo();
    void cargarArchivo();
};
#endif // MAINWINDOW_H
