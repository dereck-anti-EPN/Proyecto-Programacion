#ifndef CAMBIARPENDIENTE_H
#define CAMBIARPENDIENTE_H

#include <QDialog>
//mis includes=============================
#include<vector>
#include"crearpendiente.h" //aca esta el struct OJITO al PIOJITO

using namespace std;

namespace Ui {
class cambiarPendiente;
}

class cambiarPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarPendiente(vector<pendientesStruct> &pendientes,
                              QWidget *parent = nullptr);
    ~cambiarPendiente();

signals:
    void signalActualizar(std::vector<pendientesStruct> pendientesActualizados);

private slots:
    void on_botonCambiar_clicked();

    void on_botonBuscar_clicked();

private:
    Ui::cambiarPendiente *ui;
    std::vector<pendientesStruct> &pendientesVector;
};

#endif // CAMBIARPENDIENTE_H
