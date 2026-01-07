/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *tituloMain;
    QPushButton *botonCrear;
    QPushButton *botonLeer;
    QPushButton *botonCambiar;
    QPushButton *botonEliminar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(599, 176);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tituloMain = new QLabel(centralwidget);
        tituloMain->setObjectName("tituloMain");
        tituloMain->setGeometry(QRect(10, 0, 521, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(36);
        tituloMain->setFont(font);
        botonCrear = new QPushButton(centralwidget);
        botonCrear->setObjectName("botonCrear");
        botonCrear->setGeometry(QRect(10, 50, 151, 27));
        QFont font1;
        font1.setBold(true);
        botonCrear->setFont(font1);
        botonCrear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        botonLeer = new QPushButton(centralwidget);
        botonLeer->setObjectName("botonLeer");
        botonLeer->setGeometry(QRect(10, 80, 151, 27));
        botonLeer->setFont(font1);
        botonLeer->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        botonCambiar = new QPushButton(centralwidget);
        botonCambiar->setObjectName("botonCambiar");
        botonCambiar->setGeometry(QRect(10, 110, 151, 27));
        botonCambiar->setFont(font1);
        botonCambiar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        botonEliminar = new QPushButton(centralwidget);
        botonEliminar->setObjectName("botonEliminar");
        botonEliminar->setGeometry(QRect(10, 140, 151, 27));
        botonEliminar->setFont(font1);
        botonEliminar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        tituloMain->setText(QCoreApplication::translate("MainWindow", "Organizador de pendientes", nullptr));
        botonCrear->setText(QCoreApplication::translate("MainWindow", "Crear pendiente", nullptr));
        botonLeer->setText(QCoreApplication::translate("MainWindow", "Leer pendientes", nullptr));
        botonCambiar->setText(QCoreApplication::translate("MainWindow", "Cambiar estado", nullptr));
        botonEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar pendiente", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
