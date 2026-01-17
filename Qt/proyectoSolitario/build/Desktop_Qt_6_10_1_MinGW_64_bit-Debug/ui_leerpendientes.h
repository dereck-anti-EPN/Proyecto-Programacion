/********************************************************************************
** Form generated from reading UI file 'leerpendientes.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEERPENDIENTES_H
#define UI_LEERPENDIENTES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_leerPendientes
{
public:
    QLabel *label;
    QSpinBox *idLeer;
    QPushButton *botonBuscar;
    QLabel *label_2;
    QTextEdit *descLeer;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *respLeer;
    QLabel *label_4;
    QLineEdit *estadoLeer;

    void setupUi(QDialog *leerPendientes)
    {
        if (leerPendientes->objectName().isEmpty())
            leerPendientes->setObjectName("leerPendientes");
        leerPendientes->resize(400, 373);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        leerPendientes->setWindowIcon(icon);
        label = new QLabel(leerPendientes);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 211, 33));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(20);
        label->setFont(font);
        idLeer = new QSpinBox(leerPendientes);
        idLeer->setObjectName("idLeer");
        idLeer->setGeometry(QRect(170, 80, 42, 22));
        idLeer->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        idLeer->setMinimum(1);
        idLeer->setMaximum(999);
        botonBuscar = new QPushButton(leerPendientes);
        botonBuscar->setObjectName("botonBuscar");
        botonBuscar->setGeometry(QRect(310, 331, 81, 20));
        QFont font1;
        font1.setPointSize(11);
        botonBuscar->setFont(font1);
        botonBuscar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_2 = new QLabel(leerPendientes);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 50, 31, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(17);
        label_2->setFont(font2);
        descLeer = new QTextEdit(leerPendientes);
        descLeer->setObjectName("descLeer");
        descLeer->setGeometry(QRect(80, 140, 239, 64));
        descLeer->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ForbiddenCursor)));
        descLeer->setReadOnly(true);
        label_3 = new QLabel(leerPendientes);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 100, 121, 31));
        label_3->setFont(font2);
        label_5 = new QLabel(leerPendientes);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 270, 191, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        label_5->setFont(font3);
        respLeer = new QLineEdit(leerPendientes);
        respLeer->setObjectName("respLeer");
        respLeer->setGeometry(QRect(80, 240, 239, 20));
        respLeer->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        respLeer->setReadOnly(true);
        label_4 = new QLabel(leerPendientes);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 210, 221, 21));
        label_4->setFont(font3);
        estadoLeer = new QLineEdit(leerPendientes);
        estadoLeer->setObjectName("estadoLeer");
        estadoLeer->setGeometry(QRect(150, 300, 101, 20));
        estadoLeer->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        estadoLeer->setReadOnly(true);

        retranslateUi(leerPendientes);

        QMetaObject::connectSlotsByName(leerPendientes);
    } // setupUi

    void retranslateUi(QDialog *leerPendientes)
    {
        leerPendientes->setWindowTitle(QCoreApplication::translate("leerPendientes", "Leer", nullptr));
        label->setText(QCoreApplication::translate("leerPendientes", "Leer pendientes", nullptr));
        botonBuscar->setText(QCoreApplication::translate("leerPendientes", "Buscar", nullptr));
        label_2->setText(QCoreApplication::translate("leerPendientes", "ID", nullptr));
        label_3->setText(QCoreApplication::translate("leerPendientes", "Descripcion", nullptr));
        label_5->setText(QCoreApplication::translate("leerPendientes", "Estado", nullptr));
        label_4->setText(QCoreApplication::translate("leerPendientes", "Responsable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class leerPendientes: public Ui_leerPendientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEERPENDIENTES_H
