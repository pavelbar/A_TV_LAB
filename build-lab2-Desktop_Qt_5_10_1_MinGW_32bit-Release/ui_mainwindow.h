/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QTableWidget *tableWidget;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableWidget_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QTableWidget *tableWidget_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_14;
    QTableWidget *tableWidget_4;
    QLabel *label_15;
    QLabel *label_16;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1357, 804);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 120, 75, 23));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 100, 241, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 130, 241, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 9, 441, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 220, 771, 151));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 160, 1341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 200, 47, 13));
        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 421, 1001, 51));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 401, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(800, 230, 111, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(920, 230, 47, 13));
        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 70, 241, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(800, 260, 121, 16));
        tableWidget_3 = new QTableWidget(centralWidget);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(800, 290, 211, 91));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(930, 260, 47, 13));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 706, 331, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 720, 331, 20));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 380, 1011, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(1013, 180, 20, 581));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1030, 180, 47, 13));
        tableWidget_4 = new QTableWidget(centralWidget);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(350, 480, 661, 221));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 710, 141, 16));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(420, 710, 111, 16));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 480, 331, 221));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1357, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271 N = ", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \320\270\321\201\320\272\320\260\320\266\320\265\320\275\320\270\321\217 P = ", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0.3", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260: \320\277\320\265\321\200\320\265\320\264\320\260\321\221\321\202\321\201\321\217 N \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271 \320\277\320\276 \320\272\320\260\320\275\320\260\320\273\321\203 \321\201\320\262\321\217\320\267\320\270. \320\232\320\260\320\266\320\264\320\276\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \321\201 \320\262\320\265\321\200\320\276\321\217\321\202-\n"
"\320\275\320\276\321\201\321\202\321\214\321\216 P \320\275\320\265\320\267\320\260\320\262\320\270\321\201\320\270\320\274\320\276 \320\276\321\202 \320\264\321\200\321\203\320\263\320\270\321\205 \320\270\321\201\320\272\320\260\320\266\320\260\320\265\321\202\321\201\321\217. \320\241.\320\262. \316\267 \342\200\224 \321\207\320\270\321\201\320\273\320\276 \320\270\321\201\320\272\320\260\320\266\321\221\320\275\320\275\321\213\321\205\n"
"\321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\321\214 1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\321\214 2", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\342\210\221 \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\265\320\271 Th =", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "nan", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\272\321\201\320\277\320\270\321\200\320\270\320\274\320\265\320\275\321\202\320\276\320\262 M = ", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\342\210\221 \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\265\320\271 \321\215\320\272\321\201\320\277 =", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "nan", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200\320\276\321\207\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217: \320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\276\321\200\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217: \320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\321\214 3", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "max(Cj) = ", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "nan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
