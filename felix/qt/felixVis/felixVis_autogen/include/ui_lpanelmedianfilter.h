/********************************************************************************
** Form generated from reading UI file 'lpanelmedianfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPANELMEDIANFILTER_H
#define UI_LPANELMEDIANFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LPanelMedianFilter
{
public:
    QGridLayout *gridLayout;
    QPushButton *mButtonFilter;
    QVBoxLayout *mVerticalLayout;
    QLabel *mLabelTittle;
    QHBoxLayout *mHorizontalLayout;
    QLabel *mLabelMaskSize;
    QSpinBox *mSpinboxMaskSize;
    QPushButton *mButtonNoise;

    void setupUi(QDialog *LPanelMedianFilter)
    {
        if (LPanelMedianFilter->objectName().isEmpty())
            LPanelMedianFilter->setObjectName(QStringLiteral("LPanelMedianFilter"));
        LPanelMedianFilter->resize(233, 171);
        gridLayout = new QGridLayout(LPanelMedianFilter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mButtonFilter = new QPushButton(LPanelMedianFilter);
        mButtonFilter->setObjectName(QStringLiteral("mButtonFilter"));

        gridLayout->addWidget(mButtonFilter, 2, 0, 1, 1);

        mVerticalLayout = new QVBoxLayout();
        mVerticalLayout->setObjectName(QStringLiteral("mVerticalLayout"));
        mLabelTittle = new QLabel(LPanelMedianFilter);
        mLabelTittle->setObjectName(QStringLiteral("mLabelTittle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLabelTittle->sizePolicy().hasHeightForWidth());
        mLabelTittle->setSizePolicy(sizePolicy);
        mLabelTittle->setTextFormat(Qt::RichText);
        mLabelTittle->setAlignment(Qt::AlignCenter);

        mVerticalLayout->addWidget(mLabelTittle);

        mHorizontalLayout = new QHBoxLayout();
        mHorizontalLayout->setObjectName(QStringLiteral("mHorizontalLayout"));
        mLabelMaskSize = new QLabel(LPanelMedianFilter);
        mLabelMaskSize->setObjectName(QStringLiteral("mLabelMaskSize"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mLabelMaskSize->sizePolicy().hasHeightForWidth());
        mLabelMaskSize->setSizePolicy(sizePolicy1);

        mHorizontalLayout->addWidget(mLabelMaskSize);

        mSpinboxMaskSize = new QSpinBox(LPanelMedianFilter);
        mSpinboxMaskSize->setObjectName(QStringLiteral("mSpinboxMaskSize"));

        mHorizontalLayout->addWidget(mSpinboxMaskSize);


        mVerticalLayout->addLayout(mHorizontalLayout);


        gridLayout->addLayout(mVerticalLayout, 0, 0, 1, 1);

        mButtonNoise = new QPushButton(LPanelMedianFilter);
        mButtonNoise->setObjectName(QStringLiteral("mButtonNoise"));

        gridLayout->addWidget(mButtonNoise, 1, 0, 1, 1);


        retranslateUi(LPanelMedianFilter);

        QMetaObject::connectSlotsByName(LPanelMedianFilter);
    } // setupUi

    void retranslateUi(QDialog *LPanelMedianFilter)
    {
        LPanelMedianFilter->setWindowTitle(QApplication::translate("LPanelMedianFilter", "Dialog", nullptr));
        mButtonFilter->setText(QApplication::translate("LPanelMedianFilter", "Apply filter", nullptr));
        mLabelTittle->setText(QApplication::translate("LPanelMedianFilter", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Median filtering</span></p></body></html>", nullptr));
        mLabelMaskSize->setText(QApplication::translate("LPanelMedianFilter", "Mask Size", nullptr));
        mButtonNoise->setText(QApplication::translate("LPanelMedianFilter", "Apply noise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPanelMedianFilter: public Ui_LPanelMedianFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPANELMEDIANFILTER_H
