/********************************************************************************
** Form generated from reading UI file 'cambiarpendiente.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIARPENDIENTE_H
#define UI_CAMBIARPENDIENTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_cambiarPendiente
{
public:

    void setupUi(QDialog *cambiarPendiente)
    {
        if (cambiarPendiente->objectName().isEmpty())
            cambiarPendiente->setObjectName("cambiarPendiente");
        cambiarPendiente->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        cambiarPendiente->setWindowIcon(icon);

        retranslateUi(cambiarPendiente);

        QMetaObject::connectSlotsByName(cambiarPendiente);
    } // setupUi

    void retranslateUi(QDialog *cambiarPendiente)
    {
        cambiarPendiente->setWindowTitle(QCoreApplication::translate("cambiarPendiente", "Cambiar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cambiarPendiente: public Ui_cambiarPendiente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIARPENDIENTE_H
