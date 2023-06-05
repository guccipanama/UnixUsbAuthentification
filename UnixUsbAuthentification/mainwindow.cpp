#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authwindow.h"

#include <QTimer>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AuthWindow auth;
    auth.setModal(true);
    int result = auth.exec();
    if(result == 0)
    {
        QTimer::singleShot(0, this, SLOT(close()));
    }
    else if(result == 1)
        update_list();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_list()
{
    ui->list_of_usb->clear();
    list_usb.update();

    ui->list_of_usb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->list_of_usb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->list_of_usb->setColumnCount(6);
    ui->list_of_usb->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "ID Path" << "Device" << "Bus" << "Power");

    ui->list_of_usb->setRowCount(list_usb.size);
    for(size_t i = 0; i < list_usb.size; i++)
    {
        ui->list_of_usb->setItem(i, 0, new QTableWidgetItem(QString(list_usb.VectorUsb[i].Id)));
        ui->list_of_usb->setItem(i, 1, new QTableWidgetItem(QString(list_usb.VectorUsb[i].Name)));
        ui->list_of_usb->setItem(i, 2, new QTableWidgetItem(QString(list_usb.VectorUsb[i].IdPath)));
        ui->list_of_usb->setItem(i, 3, new QTableWidgetItem(QString(list_usb.VectorUsb[i].Device)));
        ui->list_of_usb->setItem(i, 4, new QTableWidgetItem(QString(list_usb.VectorUsb[i].Bus)));
        ui->list_of_usb->setItem(i, 5, new QTableWidgetItem(QString(list_usb.VectorUsb[i].Power)));
    }
}


void MainWindow::on_update_button_clicked()
{
    update_list();
}


void MainWindow::on_bind_button_clicked()
{
    int temp = ui->list_of_usb->currentRow();
    AuthWindow auth;
    auth.setModal(true);
    int result = auth.exec();
    if(result == 1)
    {
        list_usb.unlock(list_usb.VectorUsb[temp].Name);
    }
}


void MainWindow::on_unbind_button_clicked()
{
    int temp = ui->list_of_usb->currentRow();
    AuthWindow auth;
    auth.setModal(true);
    int result = auth.exec();
    if(result == 1)
    {
        list_usb.lock(list_usb.VectorUsb[temp].Name);
    }
}

