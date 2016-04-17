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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordingDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *recordingDialog)
    {
        if (recordingDialog->objectName().isEmpty())
            recordingDialog->setObjectName(QStringLiteral("recordingDialog"));
        recordingDialog->resize(660, 580);
        verticalLayoutWidget = new QWidget(recordingDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 642, 565));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 480));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(recordingDialog);

        QMetaObject::connectSlotsByName(recordingDialog);
    } // setupUi

    void retranslateUi(QWidget *recordingDialog)
    {
        recordingDialog->setWindowTitle(QApplication::translate("recordingDialog", "recordingDialog", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recordingDialog: public Ui_recordingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINGDIALOG_H
