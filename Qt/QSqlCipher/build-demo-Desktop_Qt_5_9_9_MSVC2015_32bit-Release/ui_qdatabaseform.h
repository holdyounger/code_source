/********************************************************************************
** Form generated from reading UI file 'qdatabaseform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDATABASEFORM_H
#define UI_QDATABASEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDataBaseForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *QDataBaseForm)
    {
        if (QDataBaseForm->objectName().isEmpty())
            QDataBaseForm->setObjectName(QStringLiteral("QDataBaseForm"));
        QDataBaseForm->resize(539, 475);
        gridLayout = new QGridLayout(QDataBaseForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(QDataBaseForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(QDataBaseForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(QDataBaseForm);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(QDataBaseForm);

        QMetaObject::connectSlotsByName(QDataBaseForm);
    } // setupUi

    void retranslateUi(QWidget *QDataBaseForm)
    {
        QDataBaseForm->setWindowTitle(QApplication::translate("QDataBaseForm", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QDataBaseForm", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDataBaseForm: public Ui_QDataBaseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDATABASEFORM_H
