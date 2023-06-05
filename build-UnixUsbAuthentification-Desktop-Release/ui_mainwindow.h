/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *bind_button;
    QPushButton *unbind_button;
    QTableWidget *list_of_usb;
    QPushButton *update_button;
    QPushButton *bin_all_button;
    QPushButton *unbind_all_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(730, 570);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bind_button = new QPushButton(centralwidget);
        bind_button->setObjectName(QString::fromUtf8("bind_button"));
        bind_button->setGeometry(QRect(620, 430, 100, 25));
        unbind_button = new QPushButton(centralwidget);
        unbind_button->setObjectName(QString::fromUtf8("unbind_button"));
        unbind_button->setGeometry(QRect(620, 465, 100, 25));
        list_of_usb = new QTableWidget(centralwidget);
        list_of_usb->setObjectName(QString::fromUtf8("list_of_usb"));
        list_of_usb->setGeometry(QRect(10, 10, 600, 550));
        update_button = new QPushButton(centralwidget);
        update_button->setObjectName(QString::fromUtf8("update_button"));
        update_button->setGeometry(QRect(620, 395, 100, 25));
        bin_all_button = new QPushButton(centralwidget);
        bin_all_button->setObjectName(QString::fromUtf8("bin_all_button"));
        bin_all_button->setGeometry(QRect(620, 500, 100, 25));
        unbind_all_button = new QPushButton(centralwidget);
        unbind_all_button->setObjectName(QString::fromUtf8("unbind_all_button"));
        unbind_all_button->setGeometry(QRect(620, 535, 100, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UNIX USB Authentification", nullptr));
        bind_button->setText(QApplication::translate("MainWindow", "Bind", nullptr));
        unbind_button->setText(QApplication::translate("MainWindow", "Unbind", nullptr));
        update_button->setText(QApplication::translate("MainWindow", "Update", nullptr));
        bin_all_button->setText(QApplication::translate("MainWindow", "Bind All", nullptr));
        unbind_all_button->setText(QApplication::translate("MainWindow", "Unbind All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
