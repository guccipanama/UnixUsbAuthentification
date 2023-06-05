#include "authwindow.h"
#include "ui_authwindow.h"
#include "mod_info.h"

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
    struct passwd *p = mod_info();
    if (unlock_access(p, ui->password_text_box->text().toStdString()))
        accept();
    else
        QMessageBox::warning(this, "Error", "Wrong password!!");
}

