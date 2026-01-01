#ifndef CREARPENDIENTE_H
#define CREARPENDIENTE_H

#include <QDialog>

//MIS INCLUDES=============================
#include <QString>

struct pendientesStruct{
    QString responsable;
    int id;
    QString descripcion;
    QString estado;
};

namespace Ui {
class crearPendiente;
}

class crearPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit crearPendiente(QWidget *parent = nullptr);
    ~crearPendiente();

signals:            //FUNCION DE EMITIR UNA SEÑAL Y QUE EL SLOT LO ACCIONE
    void signalPendientes(pendientesStruct vainaVolatilPendiente);

private slots:
    void on_botonGuardar_clicked();

private:
    Ui::crearPendiente *ui;
    QString responsable;
    int id;
    QString descripcion;
    QString estado;
};

#endif // CREARPENDIENTE_H
