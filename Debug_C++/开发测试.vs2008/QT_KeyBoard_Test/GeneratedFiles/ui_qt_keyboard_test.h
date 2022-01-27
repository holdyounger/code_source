/********************************************************************************
** Form generated from reading UI file 'qt_keyboard_test.ui'
**
** Created: Thu Nov 18 17:12:43 2021
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_KEYBOARD_TEST_H
#define UI_QT_KEYBOARD_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_KeyBoard_TestClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_KeyBoard_TestClass)
    {
        if (QT_KeyBoard_TestClass->objectName().isEmpty())
            QT_KeyBoard_TestClass->setObjectName(QString::fromUtf8("QT_KeyBoard_TestClass"));
        QT_KeyBoard_TestClass->resize(600, 400);
        centralWidget = new QWidget(QT_KeyBoard_TestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEdit_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        QT_KeyBoard_TestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_KeyBoard_TestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        QT_KeyBoard_TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QT_KeyBoard_TestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QT_KeyBoard_TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QT_KeyBoard_TestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QT_KeyBoard_TestClass->setStatusBar(statusBar);

        retranslateUi(QT_KeyBoard_TestClass);

        QMetaObject::connectSlotsByName(QT_KeyBoard_TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_KeyBoard_TestClass)
    {
        QT_KeyBoard_TestClass->setWindowTitle(QApplication::translate("QT_KeyBoard_TestClass", "QT_KeyBoard_Test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QT_KeyBoard_TestClass: public Ui_QT_KeyBoard_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_KEYBOARD_TEST_H
