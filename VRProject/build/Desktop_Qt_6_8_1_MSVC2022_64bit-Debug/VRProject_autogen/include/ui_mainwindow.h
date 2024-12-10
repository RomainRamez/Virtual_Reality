/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "vrwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    VRWidget *widgetVR;
    QVBoxLayout *verticalLayout;
    QPushButton *animationButton;
    QDial *Animation;
    QSlider *opacitySlider;
    QPushButton *requinboutton;
    QPushButton *cubebutton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(755, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        widgetVR = new VRWidget(centralwidget);
        widgetVR->setObjectName("widgetVR");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetVR->sizePolicy().hasHeightForWidth());
        widgetVR->setSizePolicy(sizePolicy);
        widgetVR->setMinimumSize(QSize(400, 300));

        horizontalLayout->addWidget(widgetVR);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        animationButton = new QPushButton(centralwidget);
        animationButton->setObjectName("animationButton");

        verticalLayout->addWidget(animationButton);

        Animation = new QDial(centralwidget);
        Animation->setObjectName("Animation");
        Animation->setMinimum(10);
        Animation->setMaximum(120);
        Animation->setValue(45);
        Animation->setNotchesVisible(true);

        verticalLayout->addWidget(Animation);

        opacitySlider = new QSlider(centralwidget);
        opacitySlider->setObjectName("opacitySlider");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opacitySlider->sizePolicy().hasHeightForWidth());
        opacitySlider->setSizePolicy(sizePolicy1);
        opacitySlider->setMaximum(100);
        opacitySlider->setValue(100);
        opacitySlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(opacitySlider);

        requinboutton = new QPushButton(centralwidget);
        requinboutton->setObjectName("requinboutton");

        verticalLayout->addWidget(requinboutton);

        cubebutton = new QPushButton(centralwidget);
        cubebutton->setObjectName("cubebutton");

        verticalLayout->addWidget(cubebutton);

        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 755, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(animationButton, &QPushButton::clicked, widgetVR, qOverload<>(&VRWidget::startAnimation));
        QObject::connect(Animation, SIGNAL(valueChanged(int)), widgetVR, SLOT(changeFov(int)));
        QObject::connect(opacitySlider, SIGNAL(valueChanged(int)), widgetVR, SLOT(changeOpacity(int)));
        QObject::connect(requinboutton, &QPushButton::clicked, widgetVR, qOverload<>(&VRWidget::selectRequin));
        QObject::connect(cubebutton, &QPushButton::clicked, widgetVR, qOverload<>(&VRWidget::selectCube));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        animationButton->setText(QCoreApplication::translate("MainWindow", "Animation", nullptr));
        requinboutton->setText(QCoreApplication::translate("MainWindow", "Requin", nullptr));
        cubebutton->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
