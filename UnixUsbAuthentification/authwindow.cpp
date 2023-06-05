#include "authwindow.h"
#include "ui_authwindow.h"




AuthWindow::AuthWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_ok_button_clicked()
{
    if (ui->password_text_box->text() == "1")
        accept();
    else
        QMessageBox::warning(this, "Error", "Wrong password!!");
}

