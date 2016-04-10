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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordingDialog
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *recordingDialog)
    {
        if (recordingDialog->objectName().isEmpty())
            recordingDialog->setObjectName(QStringLiteral("recordingDialog"));
        recordingDialog->resize(400, 300);
        textBrowser = new QTextBrowser(recordingDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(recordingDialog);

        QMetaObject::connectSlotsByName(recordingDialog);
    } // setupUi

    void retranslateUi(QWidget *recordingDialog)
    {
        recordingDialog->setWindowTitle(QApplication::translate("recordingDialog", "recordingDialog", 0));
        textBrowser->setHtml(QApplication::translate("recordingDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class recordingDialog: public Ui_recordingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINGDIALOG_H
