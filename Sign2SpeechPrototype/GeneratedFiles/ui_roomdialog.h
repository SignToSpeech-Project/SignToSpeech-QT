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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *pushButtonLeave;
    QLabel *labelRoom;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *roomDialog)
    {
        if (roomDialog->objectName().isEmpty())
            roomDialog->setObjectName(QStringLiteral("roomDialog"));
        roomDialog->resize(658, 733);
        verticalLayoutWidget = new QWidget(roomDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 642, 718));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 480));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonLeave = new QPushButton(verticalLayoutWidget);
        pushButtonLeave->setObjectName(QStringLiteral("pushButtonLeave"));

        gridLayout->addWidget(pushButtonLeave, 2, 0, 1, 1);

        labelRoom = new QLabel(verticalLayoutWidget);
        labelRoom->setObjectName(QStringLiteral("labelRoom"));

        gridLayout->addWidget(labelRoom, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(roomDialog);

        QMetaObject::connectSlotsByName(roomDialog);
    } // setupUi

    void retranslateUi(QWidget *roomDialog)
    {
        roomDialog->setWindowTitle(QApplication::translate("roomDialog", "Chat Room", 0));
        label->setText(QString());
        pushButtonLeave->setText(QApplication::translate("roomDialog", "Leave", 0));
        labelRoom->setText(QApplication::translate("roomDialog", "TextLabel", 0));
        textBrowser->setHtml(QApplication::translate("roomDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here are words that will be sent</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class roomDialog: public Ui_roomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
