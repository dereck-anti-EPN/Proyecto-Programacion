/********************************************************************************
** Form generated from reading UI file 'crearpendiente.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREARPENDIENTE_H
#define UI_CREARPENDIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_crearPendiente
{
public:
    QLabel *label;

    void setupUi(QDialog *crearPendiente)
    {
        if (crearPendiente->objectName().isEmpty())
            crearPendiente->setObjectName("crearPendiente");
        crearPendiente->resize(400, 300);
        label = new QLabel(crearPendiente);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 100, 51, 51));

        retranslateUi(crearPendiente);

        QMetaObject::connectSlotsByName(crearPendiente);
    } // setupUi

    void retranslateUi(QDialog *crearPendiente)
    {
        crearPendiente->setWindowTitle(QCoreApplication::translate("crearPendiente", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("crearPendiente", "holaaaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class crearPendiente: public Ui_crearPendiente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARPENDIENTE_H
