#ifndef CAMBIARPENDIENTE_H
#define CAMBIARPENDIENTE_H

#include <QDialog>

namespace Ui {
class cambiarPendiente;
}

class cambiarPendiente : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarPendiente(QWidget *parent = nullptr);
    ~cambiarPendiente();

private:
    Ui::cambiarPendiente *ui;
};

#endif // CAMBIARPENDIENTE_H
