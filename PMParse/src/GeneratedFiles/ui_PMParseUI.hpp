/********************************************************************************
** Form generated from reading UI file 'PMParseUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PMPARSEUI_H
#define UI_PMPARSEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ComboBox/Combobox.h"

QT_BEGIN_NAMESPACE

class Ui_PMParseUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *ParserBg;
    QVBoxLayout *verticalLayout;
    QWidget *msgWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *msgLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *pathLabel;
    DSGUI::DSComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *readBtn;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *clearBtn;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *statisticsBtn;
    QSpacerItem *horizontalSpacer_9;
    QWidget *wgtMask;

    void setupUi(QWidget *PMParseUI)
    {
        if (PMParseUI->objectName().isEmpty())
            PMParseUI->setObjectName(QStringLiteral("PMParseUI"));
        PMParseUI->resize(1076, 572);
        verticalLayout_2 = new QVBoxLayout(PMParseUI);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        ParserBg = new QWidget(PMParseUI);
        ParserBg->setObjectName(QStringLiteral("ParserBg"));
        verticalLayout = new QVBoxLayout(ParserBg);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        msgWidget = new QWidget(ParserBg);
        msgWidget->setObjectName(QStringLiteral("msgWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msgWidget->sizePolicy().hasHeightForWidth());
        msgWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(msgWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        msgLabel = new QLabel(msgWidget);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));
        msgLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(msgLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(msgWidget);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pathLabel = new QLabel(ParserBg);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        horizontalLayout_2->addWidget(pathLabel);

        comboBox = new DSGUI::DSComboBox(ParserBg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(600, 40));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        selectBtn = new QPushButton(ParserBg);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));
        sizePolicy.setHeightForWidth(selectBtn->sizePolicy().hasHeightForWidth());
        selectBtn->setSizePolicy(sizePolicy);
        selectBtn->setMinimumSize(QSize(20, 20));
        selectBtn->setMaximumSize(QSize(20, 20));
        selectBtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(selectBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        readBtn = new QPushButton(ParserBg);
        readBtn->setObjectName(QStringLiteral("readBtn"));
        readBtn->setMinimumSize(QSize(100, 40));
        readBtn->setMaximumSize(QSize(16777215, 16777215));
        readBtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(readBtn);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        clearBtn = new QPushButton(ParserBg);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setMinimumSize(QSize(100, 40));
        clearBtn->setMaximumSize(QSize(16777215, 16777215));
        clearBtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(clearBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        statisticsBtn = new QPushButton(ParserBg);
        statisticsBtn->setObjectName(QStringLiteral("statisticsBtn"));
        statisticsBtn->setMinimumSize(QSize(100, 40));
        statisticsBtn->setMaximumSize(QSize(16777215, 16777215));
        statisticsBtn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(statisticsBtn);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_3);

        wgtMask = new QWidget(ParserBg);
        wgtMask->setObjectName(QStringLiteral("wgtMask"));
        wgtMask->setEnabled(true);
        wgtMask->setMinimumSize(QSize(0, 240));

        verticalLayout->addWidget(wgtMask);


        verticalLayout_2->addWidget(ParserBg);


        retranslateUi(PMParseUI);

        QMetaObject::connectSlotsByName(PMParseUI);
    } // setupUi

    void retranslateUi(QWidget *PMParseUI)
    {
        PMParseUI->setWindowTitle(QApplication::translate("PMParseUI", "Widget", nullptr));
        msgLabel->setText(QString());
        pathLabel->setText(QApplication::translate("PMParseUI", "PM Data Path:", nullptr));
        selectBtn->setText(QApplication::translate("PMParseUI", "...", nullptr));
        readBtn->setText(QApplication::translate("PMParseUI", "Read Data", nullptr));
        clearBtn->setText(QApplication::translate("PMParseUI", "Clear Dir", nullptr));
        statisticsBtn->setText(QApplication::translate("PMParseUI", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PMParseUI: public Ui_PMParseUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMPARSEUI_H
