/********************************************************************************
** Form generated from reading UI file 'lpanelaffinetransforms.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LPANELAFFINETRANSFORMS_H
#define UI_LPANELAFFINETRANSFORMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LPanelAffineTransforms
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mLayoutVertical;
    QLabel *mLabelTitle;
    QLabel *mLabelRotation;
    QSlider *mSliderRotation;
    QLabel *mLabelTranslation;
    QSlider *mSliderTranslationX;
    QSlider *mSliderTranslationY;
    QLabel *mLabelScale;
    QSlider *mSliderScale;

    void setupUi(QDialog *LPanelAffineTransforms)
    {
        if (LPanelAffineTransforms->objectName().isEmpty())
            LPanelAffineTransforms->setObjectName(QStringLiteral("LPanelAffineTransforms"));
        LPanelAffineTransforms->resize(199, 264);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LPanelAffineTransforms->sizePolicy().hasHeightForWidth());
        LPanelAffineTransforms->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(LPanelAffineTransforms);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 176, 232));
        mLayoutVertical = new QVBoxLayout(verticalLayoutWidget);
        mLayoutVertical->setObjectName(QStringLiteral("mLayoutVertical"));
        mLayoutVertical->setSizeConstraint(QLayout::SetDefaultConstraint);
        mLayoutVertical->setContentsMargins(0, 0, 0, 0);
        mLabelTitle = new QLabel(verticalLayoutWidget);
        mLabelTitle->setObjectName(QStringLiteral("mLabelTitle"));
        mLabelTitle->setTextFormat(Qt::RichText);

        mLayoutVertical->addWidget(mLabelTitle);

        mLabelRotation = new QLabel(verticalLayoutWidget);
        mLabelRotation->setObjectName(QStringLiteral("mLabelRotation"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mLabelRotation->sizePolicy().hasHeightForWidth());
        mLabelRotation->setSizePolicy(sizePolicy1);

        mLayoutVertical->addWidget(mLabelRotation);

        mSliderRotation = new QSlider(verticalLayoutWidget);
        mSliderRotation->setObjectName(QStringLiteral("mSliderRotation"));
        mSliderRotation->setOrientation(Qt::Horizontal);
        mSliderRotation->setTickPosition(QSlider::TicksBothSides);

        mLayoutVertical->addWidget(mSliderRotation);

        mLabelTranslation = new QLabel(verticalLayoutWidget);
        mLabelTranslation->setObjectName(QStringLiteral("mLabelTranslation"));

        mLayoutVertical->addWidget(mLabelTranslation);

        mSliderTranslationX = new QSlider(verticalLayoutWidget);
        mSliderTranslationX->setObjectName(QStringLiteral("mSliderTranslationX"));
        mSliderTranslationX->setOrientation(Qt::Horizontal);
        mSliderTranslationX->setTickPosition(QSlider::TicksBothSides);

        mLayoutVertical->addWidget(mSliderTranslationX);

        mSliderTranslationY = new QSlider(verticalLayoutWidget);
        mSliderTranslationY->setObjectName(QStringLiteral("mSliderTranslationY"));
        mSliderTranslationY->setOrientation(Qt::Horizontal);
        mSliderTranslationY->setTickPosition(QSlider::TicksBothSides);

        mLayoutVertical->addWidget(mSliderTranslationY);

        mLabelScale = new QLabel(verticalLayoutWidget);
        mLabelScale->setObjectName(QStringLiteral("mLabelScale"));

        mLayoutVertical->addWidget(mLabelScale);

        mSliderScale = new QSlider(verticalLayoutWidget);
        mSliderScale->setObjectName(QStringLiteral("mSliderScale"));
        mSliderScale->setOrientation(Qt::Horizontal);
        mSliderScale->setTickPosition(QSlider::TicksBothSides);

        mLayoutVertical->addWidget(mSliderScale);


        retranslateUi(LPanelAffineTransforms);

        QMetaObject::connectSlotsByName(LPanelAffineTransforms);
    } // setupUi

    void retranslateUi(QDialog *LPanelAffineTransforms)
    {
        LPanelAffineTransforms->setWindowTitle(QApplication::translate("LPanelAffineTransforms", "Affine transformations", nullptr));
        mLabelTitle->setText(QApplication::translate("LPanelAffineTransforms", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Affine transforms</span></p></body></html>", nullptr));
        mLabelRotation->setText(QApplication::translate("LPanelAffineTransforms", "Rotation", nullptr));
        mLabelTranslation->setText(QApplication::translate("LPanelAffineTransforms", "Translation", nullptr));
        mLabelScale->setText(QApplication::translate("LPanelAffineTransforms", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LPanelAffineTransforms: public Ui_LPanelAffineTransforms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LPANELAFFINETRANSFORMS_H
