#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//INCLUDES DE LOS .h=============
#include "crearpendiente.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_botonCrear_clicked();

private:
    Ui::MainWindow *ui;
    crearPendiente *crear;
};
#endif // MAINWINDOW_H
