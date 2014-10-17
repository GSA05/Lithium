/********************************************************************************
** Form generated from reading UI file 'lithium.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITHIUM_H
#define UI_LITHIUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LithiumClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LithiumClass)
    {
        if (LithiumClass->objectName().isEmpty())
            LithiumClass->setObjectName(QStringLiteral("LithiumClass"));
        LithiumClass->resize(600, 400);
        menuBar = new QMenuBar(LithiumClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        LithiumClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LithiumClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LithiumClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LithiumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LithiumClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LithiumClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LithiumClass->setStatusBar(statusBar);

        retranslateUi(LithiumClass);

        QMetaObject::connectSlotsByName(LithiumClass);
    } // setupUi

    void retranslateUi(QMainWindow *LithiumClass)
    {
        LithiumClass->setWindowTitle(QApplication::translate("LithiumClass", "Lithium", 0));
    } // retranslateUi

};

namespace Ui {
    class LithiumClass: public Ui_LithiumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITHIUM_H
