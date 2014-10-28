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
    QAction *openAction;
    QAction *quitAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *openButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LithiumClass)
    {
        if (LithiumClass->objectName().isEmpty())
            LithiumClass->setObjectName(QStringLiteral("LithiumClass"));
        LithiumClass->resize(304, 351);
        openAction = new QAction(LithiumClass);
        openAction->setObjectName(QStringLiteral("openAction"));
        quitAction = new QAction(LithiumClass);
        quitAction->setObjectName(QStringLiteral("quitAction"));
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
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        horizontalLayout->addWidget(openButton);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);


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
        QWidget::setTabOrder(listView, removeButton);

        menuBar->addAction(menu->menuAction());
        menu->addAction(openAction);
        menu->addAction(quitAction);

        retranslateUi(LithiumClass);
        QObject::connect(openButton, SIGNAL(clicked()), openAction, SLOT(trigger()));

        QMetaObject::connectSlotsByName(LithiumClass);
    } // setupUi

    void retranslateUi(QMainWindow *LithiumClass)
    {
        LithiumClass->setWindowTitle(QApplication::translate("LithiumClass", "Lithium", 0));
        openAction->setText(QApplication::translate("LithiumClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", 0));
        quitAction->setText(QApplication::translate("LithiumClass", "\320\222\321\213\321\205\320\276\320\264", 0));
        openButton->setText(QApplication::translate("LithiumClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", 0));
        addButton->setText(QApplication::translate("LithiumClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        removeButton->setText(QApplication::translate("LithiumClass", "\320\243\320\261\321\200\320\260\321\202\321\214", 0));
        menu->setTitle(QApplication::translate("LithiumClass", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class LithiumClass: public Ui_LithiumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITHIUM_H
