/********************************************************************************
** Form generated from reading UI file 'lpanelfouriertransform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPANELFOURIERTRANSFORM_H
#define UI_LPANELFOURIERTRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LPanelFourierTransform
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *mVerticalLayout;
    QLabel *mLabelTittle;
    QVBoxLayout *mLayoutContainer;
    QLabel *mLabelFourierTransform;
    QPushButton *mButtonRefresh;

    void setupUi(QDialog *LPanelFourierTransform)
    {
        if (LPanelFourierTransform->objectName().isEmpty())
            LPanelFourierTransform->setObjectName(QStringLiteral("LPanelFourierTransform"));
        LPanelFourierTransform->resize(289, 296);
        gridLayout = new QGridLayout(LPanelFourierTransform);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mVerticalLayout = new QVBoxLayout();
        mVerticalLayout->setObjectName(QStringLiteral("mVerticalLayout"));
        mLabelTittle = new QLabel(LPanelFourierTransform);
        mLabelTittle->setObjectName(QStringLiteral("mLabelTittle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLabelTittle->sizePolicy().hasHeightForWidth());
        mLabelTittle->setSizePolicy(sizePolicy);

        mVerticalLayout->addWidget(mLabelTittle);

        mLayoutContainer = new QVBoxLayout();
        mLayoutContainer->setObjectName(QStringLiteral("mLayoutContainer"));
        mLabelFourierTransform = new QLabel(LPanelFourierTransform);
        mLabelFourierTransform->setObjectName(QStringLiteral("mLabelFourierTransform"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mLabelFourierTransform->sizePolicy().hasHeightForWidth());
        mLabelFourierTransform->setSizePolicy(sizePolicy1);
        mLabelFourierTransform->setAlignment(Qt::AlignCenter);

        mLayoutContainer->addWidget(mLabelFourierTransform);


        mVerticalLayout->addLayout(mLayoutContainer);


        gridLayout->addLayout(mVerticalLayout, 0, 0, 1, 1);

        mButtonRefresh = new QPushButton(LPanelFourierTransform);
        mButtonRefresh->setObjectName(QStringLiteral("mButtonRefresh"));

        gridLayout->addWidget(mButtonRefresh, 1, 0, 1, 1);


        retranslateUi(LPanelFourierTransform);

        QMetaObject::connectSlotsByName(LPanelFourierTransform);
    } // setupUi

    void retranslateUi(QDialog *LPanelFourierTransform)
    {
        LPanelFourierTransform->setWindowTitle(QApplication::translate("LPanelFourierTransform", "Dialog", nullptr));
        mLabelTittle->setText(QApplication::translate("LPanelFourierTransform", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Fourier Transform</span></p></body></html>", nullptr));
        mLabelFourierTransform->setText(QString());
        mButtonRefresh->setText(QApplication::translate("LPanelFourierTransform", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPanelFourierTransform: public Ui_LPanelFourierTransform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPANELFOURIERTRANSFORM_H
