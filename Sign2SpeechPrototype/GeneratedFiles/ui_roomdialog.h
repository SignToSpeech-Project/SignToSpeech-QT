/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

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

class Ui_roomDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonLeave;
    QLabel *labelRoom;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *roomDialog)
    {
        if (roomDialog->objectName().isEmpty())
            roomDialog->setObjectName(QStringLiteral("roomDialog"));
        roomDialog->resize(658, 733);
        gridLayout_2 = new QGridLayout(roomDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(roomDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 480));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser = new QTextBrowser(roomDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 1);

        pushButtonLeave = new QPushButton(roomDialog);
        pushButtonLeave->setObjectName(QStringLiteral("pushButtonLeave"));

        gridLayout->addWidget(pushButtonLeave, 3, 0, 1, 1);

        labelRoom = new QLabel(roomDialog);
        labelRoom->setObjectName(QStringLiteral("labelRoom"));

        gridLayout->addWidget(labelRoom, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(roomDialog);

        QMetaObject::connectSlotsByName(roomDialog);
    } // setupUi

    void retranslateUi(QWidget *roomDialog)
    {
        roomDialog->setWindowTitle(QApplication::translate("roomDialog", "Chat Room", 0));
        label->setText(QString());
        textBrowser->setHtml(QApplication::translate("roomDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here are words that will be sent</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pushButtonLeave->setText(QApplication::translate("roomDialog", "Leave", 0));
        labelRoom->setText(QApplication::translate("roomDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class roomDialog: public Ui_roomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
