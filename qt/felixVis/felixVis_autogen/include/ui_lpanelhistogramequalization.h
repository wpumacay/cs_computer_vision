/********************************************************************************
** Form generated from reading UI file 'lpanelhistogramequalization.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPANELHISTOGRAMEQUALIZATION_H
#define UI_LPANELHISTOGRAMEQUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_LPanelHistogramEqualization
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *mLabelTittle;
    QwtPlot *mPlotHistogram;
    QPushButton *mButtonEqualize;

    void setupUi(QDialog *LPanelHistogramEqualization)
    {
        if (LPanelHistogramEqualization->objectName().isEmpty())
            LPanelHistogramEqualization->setObjectName(QStringLiteral("LPanelHistogramEqualization"));
        LPanelHistogramEqualization->resize(446, 366);
        verticalLayout_2 = new QVBoxLayout(LPanelHistogramEqualization);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mLabelTittle = new QLabel(LPanelHistogramEqualization);
        mLabelTittle->setObjectName(QStringLiteral("mLabelTittle"));
        mLabelTittle->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(mLabelTittle);

        mPlotHistogram = new QwtPlot(LPanelHistogramEqualization);
        mPlotHistogram->setObjectName(QStringLiteral("mPlotHistogram"));

        verticalLayout->addWidget(mPlotHistogram);

        mButtonEqualize = new QPushButton(LPanelHistogramEqualization);
        mButtonEqualize->setObjectName(QStringLiteral("mButtonEqualize"));

        verticalLayout->addWidget(mButtonEqualize);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LPanelHistogramEqualization);

        QMetaObject::connectSlotsByName(LPanelHistogramEqualization);
    } // setupUi

    void retranslateUi(QDialog *LPanelHistogramEqualization)
    {
        LPanelHistogramEqualization->setWindowTitle(QApplication::translate("LPanelHistogramEqualization", "Dialog", nullptr));
        mLabelTittle->setText(QApplication::translate("LPanelHistogramEqualization", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Histogram Equalization</span></p></body></html>", nullptr));
        mButtonEqualize->setText(QApplication::translate("LPanelHistogramEqualization", "Apply equalization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPanelHistogramEqualization: public Ui_LPanelHistogramEqualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPANELHISTOGRAMEQUALIZATION_H
