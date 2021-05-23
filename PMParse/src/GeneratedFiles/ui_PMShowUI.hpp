/********************************************************************************
** Form generated from reading UI file 'PMShowUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PMSHOWUI_H
#define UI_PMSHOWUI_H

#include <QtCharts/qchartview.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "ComboBox/Combobox.h"

QT_BEGIN_NAMESPACE

class Ui_PMShowUI
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pathLabel;
    DSGUI::DSComboBox *unitComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *pathLabel_2;
    DSGUI::DSComboBox *counterComboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *statisticsBtn;
    QSpacerItem *horizontalSpacer_6;
    QLabel *pathLabel_3;
    DSGUI::DSComboBox *counterComboBoxB;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *statisticsBtnB;
    QSpacerItem *horizontalSpacer_4;
    QtCharts::QChartView *counterView;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *dataBtn;

    void setupUi(QDialog *PMShowUI)
    {
        if (PMShowUI->objectName().isEmpty())
            PMShowUI->setObjectName(QStringLiteral("PMShowUI"));
        PMShowUI->resize(925, 536);
        verticalLayout = new QVBoxLayout(PMShowUI);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pathLabel = new QLabel(PMShowUI);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        horizontalLayout->addWidget(pathLabel);

        unitComboBox = new DSGUI::DSComboBox(PMShowUI);
        unitComboBox->setObjectName(QStringLiteral("unitComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(unitComboBox->sizePolicy().hasHeightForWidth());
        unitComboBox->setSizePolicy(sizePolicy);
        unitComboBox->setMinimumSize(QSize(150, 40));
        unitComboBox->setEditable(true);

        horizontalLayout->addWidget(unitComboBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pathLabel_2 = new QLabel(PMShowUI);
        pathLabel_2->setObjectName(QStringLiteral("pathLabel_2"));

        horizontalLayout->addWidget(pathLabel_2);

        counterComboBox = new DSGUI::DSComboBox(PMShowUI);
        counterComboBox->setObjectName(QStringLiteral("counterComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(counterComboBox->sizePolicy().hasHeightForWidth());
        counterComboBox->setSizePolicy(sizePolicy1);
        counterComboBox->setMinimumSize(QSize(150, 40));
        counterComboBox->setEditable(true);

        horizontalLayout->addWidget(counterComboBox);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        statisticsBtn = new QPushButton(PMShowUI);
        statisticsBtn->setObjectName(QStringLiteral("statisticsBtn"));
        statisticsBtn->setMinimumSize(QSize(100, 40));
        statisticsBtn->setMaximumSize(QSize(16777215, 16777215));
        statisticsBtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(statisticsBtn);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pathLabel_3 = new QLabel(PMShowUI);
        pathLabel_3->setObjectName(QStringLiteral("pathLabel_3"));

        horizontalLayout->addWidget(pathLabel_3);

        counterComboBoxB = new DSGUI::DSComboBox(PMShowUI);
        counterComboBoxB->setObjectName(QStringLiteral("counterComboBoxB"));
        sizePolicy1.setHeightForWidth(counterComboBoxB->sizePolicy().hasHeightForWidth());
        counterComboBoxB->setSizePolicy(sizePolicy1);
        counterComboBoxB->setMinimumSize(QSize(150, 40));
        counterComboBoxB->setEditable(true);

        horizontalLayout->addWidget(counterComboBoxB);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        statisticsBtnB = new QPushButton(PMShowUI);
        statisticsBtnB->setObjectName(QStringLiteral("statisticsBtnB"));
        statisticsBtnB->setMinimumSize(QSize(100, 40));
        statisticsBtnB->setMaximumSize(QSize(16777215, 16777215));
        statisticsBtnB->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(statisticsBtnB);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        counterView = new QtCharts::QChartView(PMShowUI);
        counterView->setObjectName(QStringLiteral("counterView"));

        verticalLayout->addWidget(counterView);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(2);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        dataBtn = new QPushButton(PMShowUI);
        dataBtn->setObjectName(QStringLiteral("dataBtn"));
        dataBtn->setMinimumSize(QSize(100, 40));
        dataBtn->setMaximumSize(QSize(16777215, 16777215));
        dataBtn->setFocusPolicy(Qt::NoFocus);

        hboxLayout->addWidget(dataBtn);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(PMShowUI);

        QMetaObject::connectSlotsByName(PMShowUI);
    } // setupUi

    void retranslateUi(QDialog *PMShowUI)
    {
        PMShowUI->setWindowTitle(QApplication::translate("PMShowUI", "Dialog", nullptr));
        pathLabel->setText(QApplication::translate("PMShowUI", "Unit:", nullptr));
        pathLabel_2->setText(QApplication::translate("PMShowUI", "Counter:", nullptr));
        statisticsBtn->setText(QApplication::translate("PMShowUI", "Statistics", nullptr));
        pathLabel_3->setText(QApplication::translate("PMShowUI", "Counter:", nullptr));
        statisticsBtnB->setText(QApplication::translate("PMShowUI", "Statistics", nullptr));
        dataBtn->setText(QApplication::translate("PMShowUI", "Datas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PMShowUI: public Ui_PMShowUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMSHOWUI_H
