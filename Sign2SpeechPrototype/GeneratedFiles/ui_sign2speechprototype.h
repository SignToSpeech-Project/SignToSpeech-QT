/********************************************************************************
** Form generated from reading UI file 'sign2speechprototype.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN2SPEECHPROTOTYPE_H
#define UI_SIGN2SPEECHPROTOTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign2SpeechPrototypeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButtonRecognition;
    QPushButton *pushButtonLearning;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sign2SpeechPrototypeClass)
    {
        if (Sign2SpeechPrototypeClass->objectName().isEmpty())
            Sign2SpeechPrototypeClass->setObjectName(QStringLiteral("Sign2SpeechPrototypeClass"));
        Sign2SpeechPrototypeClass->resize(600, 400);
        centralWidget = new QWidget(Sign2SpeechPrototypeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        pushButtonRecognition = new QPushButton(centralWidget);
        pushButtonRecognition->setObjectName(QStringLiteral("pushButtonRecognition"));

        gridLayout->addWidget(pushButtonRecognition, 4, 0, 1, 1);

        pushButtonLearning = new QPushButton(centralWidget);
        pushButtonLearning->setObjectName(QStringLiteral("pushButtonLearning"));

        gridLayout->addWidget(pushButtonLearning, 4, 2, 1, 1);

        Sign2SpeechPrototypeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sign2SpeechPrototypeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Sign2SpeechPrototypeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Sign2SpeechPrototypeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Sign2SpeechPrototypeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Sign2SpeechPrototypeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Sign2SpeechPrototypeClass->setStatusBar(statusBar);

        retranslateUi(Sign2SpeechPrototypeClass);

        QMetaObject::connectSlotsByName(Sign2SpeechPrototypeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Sign2SpeechPrototypeClass)
    {
        Sign2SpeechPrototypeClass->setWindowTitle(QApplication::translate("Sign2SpeechPrototypeClass", "Sign2SpeechPrototype", 0));
        label->setText(QApplication::translate("Sign2SpeechPrototypeClass", "       Sign2Speech", 0));
        label_2->setText(QApplication::translate("Sign2SpeechPrototypeClass", "Welcome, select a mode", 0));
        pushButtonRecognition->setText(QApplication::translate("Sign2SpeechPrototypeClass", "Recognition Mode", 0));
        pushButtonLearning->setText(QApplication::translate("Sign2SpeechPrototypeClass", "Learning Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class Sign2SpeechPrototypeClass: public Ui_Sign2SpeechPrototypeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN2SPEECHPROTOTYPE_H
