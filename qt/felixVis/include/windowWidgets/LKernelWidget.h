
#pragma once


#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

#include <vector>

// felix stuff
#include <imgproc/localproc/LConvolution.h>

#define MIN_KERNEL_SIZE 1
#define MAX_KERNEL_SIZE 20

namespace felix {
namespace qt {

    /* 
    * @brief: Widget representation of a square kernel matrix of size 2 * kSize + 1
    */
    class LKernelWidget : public QGroupBox
    {


        private :

        QLabel* m_lblKernelSize;
        QSpinBox* m_sbKernelSize;
        //QPushButton* m_btnCalculate;

        QDoubleSpinBox* m_inDenominator;

        int m_kernelSize;

        QTableWidget* m_twMatrix;

        // layout elements
        QVBoxLayout* m_vLayout;
        QHBoxLayout* m_hLayout;
        QVBoxLayout* m_vFractionLayout;

        float _getKernelValue( int row, int col, int type );
        std::vector<float> _getPascalRow( int n );

        private slots :

        void onDimensionsChanged( int newKernelSize );
        void onElementChanged( int row, int col );

        protected :

        //void closeEvent( QCloseEvent* pEvent ) override;

        public :

        LKernelWidget( QWidget* parent = NULL );
        ~LKernelWidget();

        void _init();

        LConvKernel getKernel();
        void makeKernelByType( int type );

    };



}}