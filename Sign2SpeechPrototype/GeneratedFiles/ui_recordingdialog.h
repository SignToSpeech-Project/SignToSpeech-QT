/********************************************************************************
** Form generated from reading UI file 'recordingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDINGDIALOG_H
#define UI_RECORDINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordingDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonLeave;

    void setupUi(QWidget *recordingDialog)
    {
        if (recordingDialog->objectName().isEmpty())
            recordingDialog->setObjectName(QStringLiteral("recordingDialog"));
        recordingDialog->resize(660, 580);
        gridLayout = new QGridLayout(recordingDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(recordingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 480));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        textBrowser = new QTextBrowser(recordingDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        pushButtonLeave = new QPushButton(recordingDialog);
        pushButtonLeave->setObjectName(QStringLiteral("pushButtonLeave"));

        gridLayout->addWidget(pushButtonLeave, 1, 0, 1, 1);


        retranslateUi(recordingDialog);

        QMetaObject::connectSlotsByName(recordingDialog);
    } // setupUi

    void retranslateUi(QWidget *recordingDialog)
    {
        recordingDialog->setWindowTitle(QApplication::translate("recordingDialog", "Gestures Windows", 0));
        label->setText(QString());
        pushButtonLeave->setText(QApplication::translate("recordingDialog", "Leave", 0));
    } // retranslateUi

};

namespace Ui {
    class recordingDialog: public Ui_recordingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINGDIALOG_H
