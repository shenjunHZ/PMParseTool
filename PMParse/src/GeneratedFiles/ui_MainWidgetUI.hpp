/********************************************************************************
** Form generated from reading UI file 'MainWidgetUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGETUI_H
#define UI_MAINWIDGETUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ui/PMParseUI.hpp>
#include <ui/PMShowUI.hpp>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *mainBg;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btnQuit;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    ui::PMParseUI *parsePage;
    ui::PMShowUI *showPage;

    void setupUi(QWidget *MainWidgetUI)
    {
        if (MainWidgetUI->objectName().isEmpty())
            MainWidgetUI->setObjectName(QStringLiteral("MainWidgetUI"));
        MainWidgetUI->resize(1294, 879);
        verticalLayout_2 = new QVBoxLayout(MainWidgetUI);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        mainBg = new QWidget(MainWidgetUI);
        mainBg->setObjectName(QStringLiteral("mainBg"));
        verticalLayout = new QVBoxLayout(mainBg);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_10 = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        btnQuit = new QPushButton(mainBg);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setMinimumSize(QSize(12, 12));
        btnQuit->setMaximumSize(QSize(12, 12));
        btnQuit->setFocusPolicy(Qt::NoFocus);
        btnQuit->setFlat(true);

        horizontalLayout_5->addWidget(btnQuit);

        horizontalSpacer_11 = new QSpacerItem(40, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget = new QStackedWidget(mainBg);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        parsePage = new ui::PMParseUI();
        parsePage->setObjectName(QStringLiteral("parsePage"));
        stackedWidget->addWidget(parsePage);
        showPage = new ui::PMShowUI();
        showPage->setObjectName(QStringLiteral("showPage"));
        stackedWidget->addWidget(showPage);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addWidget(mainBg);


        retranslateUi(MainWidgetUI);

        QMetaObject::connectSlotsByName(MainWidgetUI);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetUI)
    {
        MainWidgetUI->setWindowTitle(QApplication::translate("MainWidgetUI", "Widget", nullptr));
        btnQuit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidgetUI: public Ui_MainWidgetUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGETUI_H
