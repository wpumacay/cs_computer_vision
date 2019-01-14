/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *qActionOpen;
    QAction *qActionSave;
    QAction *qActionQuit;
    QAction *qActionAffine;
    QAction *qActionConvolution;
    QAction *qActionHistEqualization;
    QAction *qActionMedianFilter;
    QAction *qActionFourier;
    QAction *qActionStyleTransfer;
    QAction *qActionPerspective;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Transforms;
    QMenu *menu_ImgProc;
    QMenu *menu_ML;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        qActionOpen = new QAction(MainWindow);
        qActionOpen->setObjectName(QStringLiteral("qActionOpen"));
        qActionSave = new QAction(MainWindow);
        qActionSave->setObjectName(QStringLiteral("qActionSave"));
        qActionQuit = new QAction(MainWindow);
        qActionQuit->setObjectName(QStringLiteral("qActionQuit"));
        qActionAffine = new QAction(MainWindow);
        qActionAffine->setObjectName(QStringLiteral("qActionAffine"));
        qActionConvolution = new QAction(MainWindow);
        qActionConvolution->setObjectName(QStringLiteral("qActionConvolution"));
        qActionHistEqualization = new QAction(MainWindow);
        qActionHistEqualization->setObjectName(QStringLiteral("qActionHistEqualization"));
        qActionMedianFilter = new QAction(MainWindow);
        qActionMedianFilter->setObjectName(QStringLiteral("qActionMedianFilter"));
        qActionFourier = new QAction(MainWindow);
        qActionFourier->setObjectName(QStringLiteral("qActionFourier"));
        qActionStyleTransfer = new QAction(MainWindow);
        qActionStyleTransfer->setObjectName(QStringLiteral("qActionStyleTransfer"));
        qActionPerspective = new QAction(MainWindow);
        qActionPerspective->setObjectName(QStringLiteral("qActionPerspective"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Transforms = new QMenu(menuBar);
        menu_Transforms->setObjectName(QStringLiteral("menu_Transforms"));
        menu_ImgProc = new QMenu(menuBar);
        menu_ImgProc->setObjectName(QStringLiteral("menu_ImgProc"));
        menu_ML = new QMenu(menuBar);
        menu_ML->setObjectName(QStringLiteral("menu_ML"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Transforms->menuAction());
        menuBar->addAction(menu_ImgProc->menuAction());
        menuBar->addAction(menu_ML->menuAction());
        menu_File->addAction(qActionOpen);
        menu_File->addAction(qActionSave);
        menu_File->addSeparator();
        menu_File->addAction(qActionQuit);
        menu_Transforms->addSeparator();
        menu_Transforms->addAction(qActionAffine);
        menu_Transforms->addAction(qActionPerspective);
        menu_ImgProc->addAction(qActionConvolution);
        menu_ImgProc->addAction(qActionHistEqualization);
        menu_ImgProc->addAction(qActionMedianFilter);
        menu_ImgProc->addSeparator();
        menu_ImgProc->addAction(qActionFourier);
        menu_ML->addAction(qActionStyleTransfer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        qActionOpen->setText(QApplication::translate("MainWindow", "&Open Image", nullptr));
        qActionSave->setText(QApplication::translate("MainWindow", "&Save Image", nullptr));
        qActionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
        qActionAffine->setText(QApplication::translate("MainWindow", "&Affine", nullptr));
        qActionConvolution->setText(QApplication::translate("MainWindow", "&Convolution", nullptr));
        qActionHistEqualization->setText(QApplication::translate("MainWindow", "&Hist equalization", nullptr));
        qActionMedianFilter->setText(QApplication::translate("MainWindow", "&MedFilter", nullptr));
        qActionFourier->setText(QApplication::translate("MainWindow", "&Fourier", nullptr));
        qActionStyleTransfer->setText(QApplication::translate("MainWindow", "&StyleTransfer", nullptr));
        qActionPerspective->setText(QApplication::translate("MainWindow", "&Perspective", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_Transforms->setTitle(QApplication::translate("MainWindow", "&Transforms", nullptr));
        menu_ImgProc->setTitle(QApplication::translate("MainWindow", "&ImgProc", nullptr));
        menu_ML->setTitle(QApplication::translate("MainWindow", "&ML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
