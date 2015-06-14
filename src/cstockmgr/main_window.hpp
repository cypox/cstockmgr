#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_main_window.h"
#include "cstock.hpp"

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QString>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();

public slots:
    void update_product_view();

private:
    int calculate_total_from_product_list();

    Ui::MainWindow *ui;
    cstock *main_stock;
};

#endif
