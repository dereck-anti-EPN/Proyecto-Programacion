#ifndef ELIMINARPENDIENTE_H
#define ELIMINARPENDIENTE_H

#include <QDialog>
//mis includes==========================0
#include<vector>
#include"crearpendiente.h"

namespace Ui {
class eliminarPendiente;
}

class eliminarPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit eliminarPendiente(std::vector<pendientesStruct> &pendientes,
                               QWidget *parent = nullptr);
    ~eliminarPendiente();

signals:
    void signalEliminar(std::vector<pendientesStruct> vectorActualizado);

private slots:
    void on_botonEliminar_clicked();

private:
    Ui::eliminarPendiente *ui;
    std::vector<pendientesStruct> &pendientesVector;
};

#endif // ELIMINARPENDIENTE_H
