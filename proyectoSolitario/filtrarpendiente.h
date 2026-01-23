#ifndef FILTRARPENDIENTE_H
#define FILTRARPENDIENTE_H

#include <QDialog>
//mis includes====================
#include "crearpendiente.h"
#include <vector>

namespace Ui {
class filtrarPendiente;
}

class filtrarPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit filtrarPendiente(const std::vector<pendientesStruct> &pendientes,
                              QWidget *parent = nullptr);
    ~filtrarPendiente();

private slots:
    void on_botonBuscar_clicked();

    void on_botonBuscar_2_clicked();

private:
    Ui::filtrarPendiente *ui;
    std::vector<pendientesStruct> pendientesVector;
};

#endif // FILTRARPENDIENTE_H
