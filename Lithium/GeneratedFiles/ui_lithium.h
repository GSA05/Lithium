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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LithiumClass
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonRemove;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LithiumClass)
    {
        if (LithiumClass->objectName().isEmpty())
            LithiumClass->setObjectName(QStringLiteral("LithiumClass"));
        LithiumClass->resize(304, 351);
        action = new QAction(LithiumClass);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(LithiumClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(LithiumClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout_2->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOpen = new QPushButton(centralWidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        horizontalLayout->addWidget(pushButtonOpen);

        pushButtonAdd = new QPushButton(centralWidget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonRemove = new QPushButton(centralWidget);
        pushButtonRemove->setObjectName(QStringLiteral("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);


        verticalLayout_2->addLayout(horizontalLayout);

        LithiumClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LithiumClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 304, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        LithiumClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(LithiumClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LithiumClass->setStatusBar(statusBar);
        QWidget::setTabOrder(listView, pushButtonOpen);
        QWidget::setTabOrder(pushButtonOpen, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonRemove);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(LithiumClass);

        QMetaObject::connectSlotsByName(LithiumClass);
    } // setupUi

    void retranslateUi(QMainWindow *LithiumClass)
    {
        LithiumClass->setWindowTitle(QApplication::translate("LithiumClass", "Lithium", 0));
        action->setText(QApplication::translate("LithiumClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", 0));
        action_2->setText(QApplication::translate("LithiumClass", "\320\222\321\213\321\205\320\276\320\264", 0));
        pushButtonOpen->setText(QApplication::translate("LithiumClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", 0));
        pushButtonAdd->setText(QApplication::translate("LithiumClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButtonRemove->setText(QApplication::translate("LithiumClass", "\320\243\320\261\321\200\320\260\321\202\321\214", 0));
        menu->setTitle(QApplication::translate("LithiumClass", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class LithiumClass: public Ui_LithiumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITHIUM_H
