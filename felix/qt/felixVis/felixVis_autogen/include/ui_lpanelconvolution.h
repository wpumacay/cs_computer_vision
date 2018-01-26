/********************************************************************************
** Form generated from reading UI file 'lpanelconvolution.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPANELCONVOLUTION_H
#define UI_LPANELCONVOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LPanelConvolution
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *mLayoutVertical;
    QLabel *mLabelTitle;
    QVBoxLayout *mLayoutContainer;

    void setupUi(QDialog *LPanelConvolution)
    {
        if (LPanelConvolution->objectName().isEmpty())
            LPanelConvolution->setObjectName(QStringLiteral("LPanelConvolution"));
        LPanelConvolution->resize(370, 376);
        LPanelConvolution->setAutoFillBackground(false);
        gridLayout = new QGridLayout(LPanelConvolution);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mLayoutVertical = new QVBoxLayout();
        mLayoutVertical->setObjectName(QStringLiteral("mLayoutVertical"));
        mLabelTitle = new QLabel(LPanelConvolution);
        mLabelTitle->setObjectName(QStringLiteral("mLabelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLabelTitle->sizePolicy().hasHeightForWidth());
        mLabelTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        mLabelTitle->setFont(font);
        mLabelTitle->setTextFormat(Qt::RichText);
        mLabelTitle->setAlignment(Qt::AlignCenter);

        mLayoutVertical->addWidget(mLabelTitle);

        mLayoutContainer = new QVBoxLayout();
        mLayoutContainer->setObjectName(QStringLiteral("mLayoutContainer"));

        mLayoutVertical->addLayout(mLayoutContainer);


        gridLayout->addLayout(mLayoutVertical, 0, 0, 1, 1);


        retranslateUi(LPanelConvolution);

        QMetaObject::connectSlotsByName(LPanelConvolution);
    } // setupUi

    void retranslateUi(QDialog *LPanelConvolution)
    {
        LPanelConvolution->setWindowTitle(QApplication::translate("LPanelConvolution", "Dialog", 0));
        mLabelTitle->setText(QApplication::translate("LPanelConvolution", "Convolutions", 0));
    } // retranslateUi

};

namespace Ui {
    class LPanelConvolution: public Ui_LPanelConvolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPANELCONVOLUTION_H
