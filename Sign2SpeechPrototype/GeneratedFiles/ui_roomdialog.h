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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelRoom;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonLeave;

    void setupUi(QWidget *roomDialog)
    {
        if (roomDialog->objectName().isEmpty())
            roomDialog->setObjectName(QStringLiteral("roomDialog"));
        roomDialog->resize(400, 300);
        gridLayoutWidget = new QWidget(roomDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelRoom = new QLabel(gridLayoutWidget);
        labelRoom->setObjectName(QStringLiteral("labelRoom"));

        gridLayout->addWidget(labelRoom, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 0, 1, 1);

        pushButtonLeave = new QPushButton(gridLayoutWidget);
        pushButtonLeave->setObjectName(QStringLiteral("pushButtonLeave"));

        gridLayout->addWidget(pushButtonLeave, 3, 0, 1, 1);


        retranslateUi(roomDialog);

        QMetaObject::connectSlotsByName(roomDialog);
    } // setupUi

    void retranslateUi(QWidget *roomDialog)
    {
        roomDialog->setWindowTitle(QApplication::translate("roomDialog", "roomDialog", 0));
        labelRoom->setText(QApplication::translate("roomDialog", "TextLabel", 0));
        textBrowser->setHtml(QApplication::translate("roomDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here are words that will be sent</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pushButtonLeave->setText(QApplication::translate("roomDialog", "Leave", 0));
    } // retranslateUi

};

namespace Ui {
    class roomDialog: public Ui_roomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
