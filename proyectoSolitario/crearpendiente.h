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

private:
    Ui::crearPendiente *ui;
};

#endif // CREARPENDIENTE_H
