#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "List_usb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_update_button_clicked();
    void update_list();

    void on_bind_button_clicked();

    void on_unbind_button_clicked();

private:
    Ui::MainWindow *ui;
    List_usb list_usb;
};
#endif // MAINWINDOW_H
