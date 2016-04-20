/********************************************************************************
** Form generated from reading UI file 'learningdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNINGDIALOG_H
#define UI_LEARNINGDIALOG_H

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

class Ui_learningDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxGestures;
    QLabel *labelWord;
    QLineEdit *lineEditWord;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonValidation;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *learningDialog)
    {
        if (learningDialog->objectName().isEmpty())
            learningDialog->setObjectName(QStringLiteral("learningDialog"));
        learningDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(learningDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxGestures = new QSpinBox(learningDialog);
        spinBoxGestures->setObjectName(QStringLiteral("spinBoxGestures"));
        spinBoxGestures->setMinimum(1);
        spinBoxGestures->setValue(1);

        gridLayout->addWidget(spinBoxGestures, 1, 0, 1, 1);

        labelWord = new QLabel(learningDialog);
        labelWord->setObjectName(QStringLiteral("labelWord"));

        gridLayout->addWidget(labelWord, 0, 1, 1, 1);

        lineEditWord = new QLineEdit(learningDialog);
        lineEditWord->setObjectName(QStringLiteral("lineEditWord"));

        gridLayout->addWidget(lineEditWord, 0, 0, 1, 1);

        label = new QLabel(learningDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonValidation = new QPushButton(learningDialog);
        pushButtonValidation->setObjectName(QStringLiteral("pushButtonValidation"));

        horizontalLayout->addWidget(pushButtonValidation);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonQuit = new QPushButton(learningDialog);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        horizontalLayout->addWidget(pushButtonQuit);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(learningDialog);

        QMetaObject::connectSlotsByName(learningDialog);
    } // setupUi

    void retranslateUi(QWidget *learningDialog)
    {
        learningDialog->setWindowTitle(QApplication::translate("learningDialog", "Learning Mode", 0));
        labelWord->setText(QApplication::translate("learningDialog", "Meaning of your word", 0));
        label->setText(QApplication::translate("learningDialog", "Number of gestures", 0));
        pushButtonValidation->setText(QApplication::translate("learningDialog", "Validation", 0));
        pushButtonQuit->setText(QApplication::translate("learningDialog", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class learningDialog: public Ui_learningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNINGDIALOG_H
