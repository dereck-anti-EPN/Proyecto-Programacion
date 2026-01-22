#ifndef LEERPENDIENTES_H
#define LEERPENDIENTES_H

#include <QDialog>
//mis includes====================
#include "crearpendiente.h"
#include <vector>

namespace Ui {
class leerPendientes;
}

class leerPendientes : public QDialog
{
    Q_OBJECT

public:
    explicit leerPendientes(const std::vector<pendientesStruct> &pendientes, //const pa no modificar nada
                            QWidget *parent = nullptr);
    ~leerPendientes();

private slots:
    void on_botonBuscar_clicked();

    void on_pushButton_clicked();

private:
    Ui::leerPendientes *ui;
    std::vector<pendientesStruct> pendientesVector;
};

#endif // LEERPENDIENTES_H
