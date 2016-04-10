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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelWord;
    QLabel *label;
    QLineEdit *lineEditWord;
    QSpinBox *spinBoxGestures;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonValidation;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *learningDialog)
    {
        if (learningDialog->objectName().isEmpty())
            learningDialog->setObjectName(QStringLiteral("learningDialog"));
        learningDialog->resize(400, 300);
        gridLayoutWidget = new QWidget(learningDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelWord = new QLabel(gridLayoutWidget);
        labelWord->setObjectName(QStringLiteral("labelWord"));

        gridLayout->addWidget(labelWord, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEditWord = new QLineEdit(gridLayoutWidget);
        lineEditWord->setObjectName(QStringLiteral("lineEditWord"));

        gridLayout->addWidget(lineEditWord, 0, 0, 1, 1);

        spinBoxGestures = new QSpinBox(gridLayoutWidget);
        spinBoxGestures->setObjectName(QStringLiteral("spinBoxGestures"));
        spinBoxGestures->setMinimum(1);
        spinBoxGestures->setValue(1);

        gridLayout->addWidget(spinBoxGestures, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(learningDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 220, 371, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonValidation = new QPushButton(horizontalLayoutWidget);
        pushButtonValidation->setObjectName(QStringLiteral("pushButtonValidation"));

        horizontalLayout->addWidget(pushButtonValidation);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonQuit = new QPushButton(horizontalLayoutWidget);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        horizontalLayout->addWidget(pushButtonQuit);


        retranslateUi(learningDialog);

        QMetaObject::connectSlotsByName(learningDialog);
    } // setupUi

    void retranslateUi(QWidget *learningDialog)
    {
        learningDialog->setWindowTitle(QApplication::translate("learningDialog", "learningDialog", 0));
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
