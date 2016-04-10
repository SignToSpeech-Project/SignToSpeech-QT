/********************************************************************************
** Form generated from reading UI file 'normaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALDIALOG_H
#define UI_NORMALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normalDialog
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonEnter;
    QPushButton *pushButtonQuit;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *lineEditRoom;
    QLineEdit *lineEditUser;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *normalDialog)
    {
        if (normalDialog->objectName().isEmpty())
            normalDialog->setObjectName(QStringLiteral("normalDialog"));
        normalDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(normalDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButtonEnter = new QPushButton(normalDialog);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));

        gridLayout_2->addWidget(pushButtonEnter, 3, 0, 1, 1);

        pushButtonQuit = new QPushButton(normalDialog);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        gridLayout_2->addWidget(pushButtonQuit, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEditRoom = new QLineEdit(normalDialog);
        lineEditRoom->setObjectName(QStringLiteral("lineEditRoom"));

        gridLayout->addWidget(lineEditRoom, 1, 0, 1, 1);

        lineEditUser = new QLineEdit(normalDialog);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));

        gridLayout->addWidget(lineEditUser, 0, 0, 1, 1);

        label = new QLabel(normalDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(normalDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox_1 = new QSpinBox(normalDialog);
        spinBox_1->setObjectName(QStringLiteral("spinBox_1"));
        spinBox_1->setMaximum(500);
        spinBox_1->setValue(192);

        horizontalLayout->addWidget(spinBox_1);

        spinBox_2 = new QSpinBox(normalDialog);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(500);
        spinBox_2->setValue(168);

        horizontalLayout->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(normalDialog);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setValue(1);

        horizontalLayout->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(normalDialog);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setValue(1);

        horizontalLayout->addWidget(spinBox_4);

        label_3 = new QLabel(normalDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(normalDialog);

        QMetaObject::connectSlotsByName(normalDialog);
    } // setupUi

    void retranslateUi(QWidget *normalDialog)
    {
        normalDialog->setWindowTitle(QApplication::translate("normalDialog", "normalDialog", 0));
        pushButtonEnter->setText(QApplication::translate("normalDialog", "Enter", 0));
        pushButtonQuit->setText(QApplication::translate("normalDialog", "Quit", 0));
        lineEditRoom->setText(QApplication::translate("normalDialog", "Test", 0));
        lineEditUser->setText(QApplication::translate("normalDialog", "Intel", 0));
        label->setText(QApplication::translate("normalDialog", "Room Name", 0));
        label_2->setText(QApplication::translate("normalDialog", "User Name", 0));
        label_3->setText(QApplication::translate("normalDialog", "Adress ", 0));
    } // retranslateUi

};

namespace Ui {
    class normalDialog: public Ui_normalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALDIALOG_H
