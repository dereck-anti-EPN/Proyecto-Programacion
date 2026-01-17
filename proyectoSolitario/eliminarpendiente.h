#ifndef ELIMINARPENDIENTE_H
#define ELIMINARPENDIENTE_H

#include <QDialog>

namespace Ui {
class eliminarPendiente;
}

class eliminarPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit eliminarPendiente(QWidget *parent = nullptr);
    ~eliminarPendiente();

private:
    Ui::eliminarPendiente *ui;
};

#endif // ELIMINARPENDIENTE_H
