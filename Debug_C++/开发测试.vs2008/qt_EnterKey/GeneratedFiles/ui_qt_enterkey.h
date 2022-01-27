/********************************************************************************
** Form generated from reading UI file 'qt_enterkey.ui'
**
** Created: Thu Nov 4 17:27:38 2021
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_ENTERKEY_H
#define UI_QT_ENTERKEY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_EnterKeyClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_EnterKeyClass)
    {
        if (qt_EnterKeyClass->objectName().isEmpty())
            qt_EnterKeyClass->setObjectName(QString::fromUtf8("qt_EnterKeyClass"));
        qt_EnterKeyClass->resize(600, 400);
        centralWidget = new QWidget(qt_EnterKeyClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        qt_EnterKeyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_EnterKeyClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        qt_EnterKeyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_EnterKeyClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qt_EnterKeyClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_EnterKeyClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qt_EnterKeyClass->setStatusBar(statusBar);

        retranslateUi(qt_EnterKeyClass);

        QMetaObject::connectSlotsByName(qt_EnterKeyClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_EnterKeyClass)
    {
        qt_EnterKeyClass->setWindowTitle(QApplication::translate("qt_EnterKeyClass", "qt_EnterKey", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("qt_EnterKeyClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("qt_EnterKeyClass", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qt_EnterKeyClass: public Ui_qt_EnterKeyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_ENTERKEY_H
