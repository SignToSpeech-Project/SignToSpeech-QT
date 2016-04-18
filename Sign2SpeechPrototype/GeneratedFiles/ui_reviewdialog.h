/********************************************************************************
** Form generated from reading UI file 'reviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEWDIALOG_H
#define UI_REVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reviewDialog
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonContinue;
    QLabel *label3;
    QLabel *label2;
    QPushButton *pushButtonDoAgain;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QLabel *label1;
    QLabel *label_4;

    void setupUi(QWidget *reviewDialog)
    {
        if (reviewDialog->objectName().isEmpty())
            reviewDialog->setObjectName(QStringLiteral("reviewDialog"));
        reviewDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(reviewDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButtonContinue = new QPushButton(reviewDialog);
        pushButtonContinue->setObjectName(QStringLiteral("pushButtonContinue"));

        gridLayout_2->addWidget(pushButtonContinue, 3, 0, 1, 1);

        label3 = new QLabel(reviewDialog);
        label3->setObjectName(QStringLiteral("label3"));

        gridLayout_2->addWidget(label3, 2, 2, 1, 1);

        label2 = new QLabel(reviewDialog);
        label2->setObjectName(QStringLiteral("label2"));

        gridLayout_2->addWidget(label2, 2, 1, 1, 1);

        pushButtonDoAgain = new QPushButton(reviewDialog);
        pushButtonDoAgain->setObjectName(QStringLiteral("pushButtonDoAgain"));

        gridLayout_2->addWidget(pushButtonDoAgain, 3, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));

        gridLayout_2->addLayout(gridLayout_3, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));

        gridLayout_2->addLayout(gridLayout_4, 1, 2, 1, 1);

        label1 = new QLabel(reviewDialog);
        label1->setObjectName(QStringLiteral("label1"));

        gridLayout_2->addWidget(label1, 2, 0, 1, 1);

        label_4 = new QLabel(reviewDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);


        retranslateUi(reviewDialog);

        QMetaObject::connectSlotsByName(reviewDialog);
    } // setupUi

    void retranslateUi(QWidget *reviewDialog)
    {
        reviewDialog->setWindowTitle(QApplication::translate("reviewDialog", "reviewDialog", 0));
        pushButtonContinue->setText(QApplication::translate("reviewDialog", "Continue", 0));
        label3->setText(QApplication::translate("reviewDialog", "Image 3", 0));
        label2->setText(QApplication::translate("reviewDialog", "Image 2", 0));
        pushButtonDoAgain->setText(QApplication::translate("reviewDialog", "Do again", 0));
        label1->setText(QApplication::translate("reviewDialog", "Image 1", 0));
        label_4->setText(QApplication::translate("reviewDialog", "Do you wish to do again your gesture ?", 0));
    } // retranslateUi

};

namespace Ui {
    class reviewDialog: public Ui_reviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEWDIALOG_H
