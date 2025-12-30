#ifndef CREARPENDIENTE_H
#define CREARPENDIENTE_H

#include <QDialog>

namespace Ui {
class crearPendiente;
}

class crearPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit crearPendiente(QWidget *parent = nullptr);
    ~crearPendiente();

private slots:
    void on_botonGuardar_clicked();

private:
    Ui::crearPendiente *ui;
    //PONER MAS REFERENTE A LO QUE FALTA DE "AGREGAR"
    QString responsable;
    int id;
    QString descripcion;
    QString estado;
};

#endif // CREARPENDIENTE_H
