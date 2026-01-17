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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_crearPendiente
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *respLinea;
    QPushButton *botonGuardar;
    QSpinBox *idLinea;
    QTextEdit *descLinea;
    QComboBox *estadoLinea;

    void setupUi(QDialog *crearPendiente)
    {
        if (crearPendiente->objectName().isEmpty())
            crearPendiente->setObjectName("crearPendiente");
        crearPendiente->resize(393, 373);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        crearPendiente->setWindowIcon(icon);
        label = new QLabel(crearPendiente);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 0, 251, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        label_2 = new QLabel(crearPendiente);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 40, 91, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        label_3 = new QLabel(crearPendiente);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 100, 221, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(crearPendiente);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 200, 221, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(crearPendiente);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 250, 191, 21));
        label_5->setFont(font1);
        respLinea = new QLineEdit(crearPendiente);
        respLinea->setObjectName("respLinea");
        respLinea->setGeometry(QRect(80, 220, 239, 20));
        botonGuardar = new QPushButton(crearPendiente);
        botonGuardar->setObjectName("botonGuardar");
        botonGuardar->setGeometry(QRect(300, 330, 80, 18));
        botonGuardar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        idLinea = new QSpinBox(crearPendiente);
        idLinea->setObjectName("idLinea");
        idLinea->setGeometry(QRect(170, 70, 53, 22));
        idLinea->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        idLinea->setMinimum(1);
        idLinea->setMaximum(999);
        descLinea = new QTextEdit(crearPendiente);
        descLinea->setObjectName("descLinea");
        descLinea->setGeometry(QRect(80, 120, 239, 64));
        descLinea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));
        estadoLinea = new QComboBox(crearPendiente);
        estadoLinea->addItem(QString());
        estadoLinea->addItem(QString());
        estadoLinea->addItem(QString());
        estadoLinea->setObjectName("estadoLinea");
        estadoLinea->setGeometry(QRect(150, 280, 100, 22));
        estadoLinea->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        retranslateUi(crearPendiente);

        QMetaObject::connectSlotsByName(crearPendiente);
    } // setupUi

    void retranslateUi(QDialog *crearPendiente)
    {
        crearPendiente->setWindowTitle(QCoreApplication::translate("crearPendiente", "Crear", nullptr));
        label->setText(QCoreApplication::translate("crearPendiente", "Crear pendiente", nullptr));
        label_2->setText(QCoreApplication::translate("crearPendiente", "ID [1-999]", nullptr));
        label_3->setText(QCoreApplication::translate("crearPendiente", "Descripcion", nullptr));
        label_4->setText(QCoreApplication::translate("crearPendiente", "Responsable", nullptr));
        label_5->setText(QCoreApplication::translate("crearPendiente", "Estado", nullptr));
        botonGuardar->setText(QCoreApplication::translate("crearPendiente", "Guardar", nullptr));
        estadoLinea->setItemText(0, QCoreApplication::translate("crearPendiente", "Pendiente", nullptr));
        estadoLinea->setItemText(1, QCoreApplication::translate("crearPendiente", "Completado", nullptr));
        estadoLinea->setItemText(2, QCoreApplication::translate("crearPendiente", "Abandonado", nullptr));

    } // retranslateUi

};

namespace Ui {
    class crearPendiente: public Ui_crearPendiente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARPENDIENTE_H
