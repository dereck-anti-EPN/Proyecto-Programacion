/********************************************************************************
** Form generated from reading UI file 'eliminarpendiente.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINARPENDIENTE_H
#define UI_ELIMINARPENDIENTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_eliminarPendiente
{
public:

    void setupUi(QDialog *eliminarPendiente)
    {
        if (eliminarPendiente->objectName().isEmpty())
            eliminarPendiente->setObjectName("eliminarPendiente");
        eliminarPendiente->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        eliminarPendiente->setWindowIcon(icon);

        retranslateUi(eliminarPendiente);

        QMetaObject::connectSlotsByName(eliminarPendiente);
    } // setupUi

    void retranslateUi(QDialog *eliminarPendiente)
    {
        eliminarPendiente->setWindowTitle(QCoreApplication::translate("eliminarPendiente", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eliminarPendiente: public Ui_eliminarPendiente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINARPENDIENTE_H
