/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QPushButton *ok_button;
    QLineEdit *password_text_box;
    QLabel *text_enter_password;

    void setupUi(QDialog *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName(QString::fromUtf8("AuthWindow"));
        AuthWindow->resize(340, 70);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthWindow->sizePolicy().hasHeightForWidth());
        AuthWindow->setSizePolicy(sizePolicy);
        AuthWindow->setMinimumSize(QSize(340, 70));
        AuthWindow->setMaximumSize(QSize(340, 70));
        ok_button = new QPushButton(AuthWindow);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(230, 40, 100, 25));
        password_text_box = new QLineEdit(AuthWindow);
        password_text_box->setObjectName(QString::fromUtf8("password_text_box"));
        password_text_box->setGeometry(QRect(130, 10, 200, 25));
        text_enter_password = new QLabel(AuthWindow);
        text_enter_password->setObjectName(QString::fromUtf8("text_enter_password"));
        text_enter_password->setGeometry(QRect(10, 10, 110, 25));

        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QDialog *AuthWindow)
    {
        AuthWindow->setWindowTitle(QApplication::translate("AuthWindow", "Authorization", nullptr));
        ok_button->setText(QApplication::translate("AuthWindow", "OK", nullptr));
        text_enter_password->setText(QApplication::translate("AuthWindow", "Enter password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
