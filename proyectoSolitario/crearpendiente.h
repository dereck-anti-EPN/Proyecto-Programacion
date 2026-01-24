#ifndef CREARPENDIENTE_H
#define CREARPENDIENTE_H

#include <QDialog>

//MIS INCLUDES=============================
#include <QString>

//declaracion del struct en este .h, por eso siempre se lo incluye en el resto de .h
struct pendientesStruct{
    QString responsable;
    int id;
    QString descripcion;
    QString estado;
};

namespace Ui {
class crearPendiente; //clase===========================================================================
}

class crearPendiente : public QDialog
{
    Q_OBJECT

public: //esto se usa fuera de la clase
    explicit crearPendiente(const std::vector<pendientesStruct> &pendientes //constructor pero con =nullptr
                            ,QWidget *parent = nullptr);
    ~crearPendiente();

signals:            //cada que hace emit mande un nuevo pendiente
    void signalPendientes(pendientesStruct vainaVolatilPendiente);

private slots: //solo pa slots
    void on_botonGuardar_clicked();

    void on_botonSalir_clicked();

private: //solo esta clase la usa
    Ui::crearPendiente *ui;
    std::vector<pendientesStruct> pendientesVector;
};

#endif // CREARPENDIENTE_H
